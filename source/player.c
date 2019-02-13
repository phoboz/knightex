// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "generic.h"
#include "controller.h"
#include "draw.h"
#include "platform.h"
#include "ostrich.h"
#include "enemy.h"
#include "player.h"

// ---------------------------------------------------------------------------

static const struct character_anim player_anim =
{
	PLAYER_HEIGHT,
	PLAYER_WIDTH,
	PLAYER_SCALE,
	PLAYER_TRESHOLD,
	OSTRICH_LEFT,
	OSTRICH_RIGHT,
	OSTRICH_WALK_LEFT_END - OSTRICH_WALK_LEFT_START + 1,
	OSTRICH_WALK_LEFT_START,
	OSTRICH_WALK_RIGHT_START,
	OSTRICH_BRAKE_LEFT,
	OSTRICH_BRAKE_RIGHT,
	ostrich
};

void init_player(
	struct player *player,
	signed int y,
	signed int x,
	unsigned int dir
	)
{
	init_character(&player->ch, y, x, PLAYER_SPEED, &player_anim, 0);

	player->state			= PLAYER_STATE_NORMAL;
	player->state_counter	= 0;
	player->speed_counter	= 0;

	player->control_dir = dir;
	player->ch.dir = dir;
	if (dir == DIR_LEFT)
	{
		player->ch.base_frame = player_anim.frame_left;
	}
	else if (dir == DIR_RIGHT)
	{
		player->ch.base_frame = player_anim.frame_right;
	}
}

unsigned int move_player(
	struct player *player
	)
{
	unsigned int brake = 0;
	unsigned int status = 0;

	if (joystick_1_left())
	{
		if (player->control_dir == DIR_LEFT)
		{
			if (player->ch.dx > 0)
			{
				brake = 1;
			}

			if (++player->speed_counter >= PLAYER_SPEED_TRESHOLD)
			{
				player->speed_counter = 0;
				if (player->ch.dx > -PLAYER_SPEED)
				{
					player->ch.dx--;
				}
			}
		}
		else
		{
			player->control_dir = DIR_LEFT;
		}
	}
	else if (joystick_1_right())
	{
		if (player->control_dir == DIR_RIGHT)
		{
			if (player->ch.dx < 0)
			{
				brake = 1;
			}

			if (++player->speed_counter >= PLAYER_SPEED_TRESHOLD)
			{
				player->speed_counter = 0;
				if (player->ch.dx < PLAYER_SPEED)
				{
					player->ch.dx++;
				}
			}
		}
		else
		{
			player->control_dir = DIR_RIGHT;
		}
	}

	player->ch.treshold = PLAYER_TRESHOLD - (unsigned int) abs(player->ch.dx);

	switch (player->state)
	{
		case PLAYER_STATE_NORMAL:
			if (player->ch.dx < 0)
			{
				player->ch.dir = DIR_LEFT;
				player->ch.base_frame = player->ch.anim->frame_left;
			}
			else if (player->ch.dx > 0)
			{
				player->ch.dir = DIR_RIGHT;
				player->ch.base_frame = player->ch.anim->frame_right;
			}
			else if (player->ch.dx == 0)
			{
				if (player->control_dir == DIR_LEFT)
				{
					player->ch.dir = DIR_LEFT;
					player->ch.base_frame = player->ch.anim->frame_left;
				}
				else if (player->control_dir == DIR_RIGHT)
				{
					player->ch.dir = DIR_RIGHT;
					player->ch.base_frame = player->ch.anim->frame_right;
				}
			}

			if (button_1_4_pressed())
			{
				player->ch.dy = PLAYER_LIFT;
				player->ch.frame = 1;
				status |= PLAYER_STATUS_FLAP;
				if (!hit_platform(&player->ch.obj, &player->ch.dy, &player->ch.dx))
				{
					player->state = PLAYER_STATE_FLAP;
				}
			}
			else
			{
				if (++player->gravity_counter >= PLAYER_GRAVITY_TRESHOLD)
				{
					player->gravity_counter = 0;
					if (player->ch.dy > -PLAYER_GRAVITY)
					{
						player->ch.dy--;
					}
				}
			}

			if (hit_over_platform(&player->ch.obj, &player->ch.dy, player->ch.dx))
			{
				player->state = PLAYER_STATE_WALK;
				if (player->ch.base_frame == player->ch.anim->frame_left)
				{
					player->ch.base_frame = player->ch.anim->frame_walk_left;
				}
				else if (player->ch.base_frame == player->ch.anim->frame_right)
				{
					player->ch.base_frame = player->ch.anim->frame_walk_right;
				}
				status |= PLAYER_STATUS_WALK;
			}
			break;

		case PLAYER_STATE_FLAP:
			if (player->ch.dx < 0)
			{
				player->ch.base_frame = player->ch.anim->frame_left;
			}
			else if (player->ch.dx > 0)
			{
				player->ch.base_frame = player->ch.anim->frame_right;
			}
			else if (player->ch.dx == 0)
			{
				if (player->control_dir == DIR_LEFT)
				{
					player->ch.dir = DIR_LEFT;
					player->ch.base_frame = player->ch.anim->frame_left;
				}
				else if (player->control_dir == DIR_RIGHT)
				{
					player->ch.dir = DIR_RIGHT;
					player->ch.base_frame = player->ch.anim->frame_right;
				}
			}

			if (hit_platform(&player->ch.obj, &player->ch.dy, &player->ch.dx))
			{
				player->state_counter = 0;
				player->ch.frame = 0;
				player->state = PLAYER_STATE_NORMAL;
			}

			if (++player->state_counter >= PLAYER_FLAP_TRESHOLD)
			{
				player->state_counter = 0;
				player->ch.frame = 0;
				player->state = PLAYER_STATE_NORMAL;
			}
			break;

		case PLAYER_STATE_WALK:
			player->ch.dy = 0;
			if (player->ch.dx < 0 && player->control_dir != DIR_LEFT)
			{
				player->ch.dir = DIR_LEFT;
				player->ch.base_frame = player->ch.anim->frame_walk_left;
			}
			else if (player->ch.dx > 0 && player->control_dir != DIR_RIGHT)
			{
				player->ch.dir = DIR_RIGHT;
				player->ch.base_frame = player->ch.anim->frame_walk_right;
			}
			else if (player->ch.dx == 0)
			{
				if (player->control_dir == DIR_LEFT)
				{
					player->ch.dir = DIR_LEFT;
					player->ch.base_frame = player->ch.anim->frame_walk_left;
				}
				else if (player->control_dir == DIR_RIGHT)
				{
					player->ch.dir = DIR_RIGHT;
					player->ch.base_frame = player->ch.anim->frame_walk_right;
				}
				player->ch.frame = 0;
			}

			if (player->ch.dx != 0)
			{
				if (brake)
				{
					if (player->control_dir == DIR_LEFT)
					{
						player->ch.dir = DIR_RIGHT;
						player->ch.base_frame = player->ch.anim->frame_brake_right;
						player->ch.frame = 0;
					}
					else if (player->control_dir == DIR_RIGHT)
					{
						player->ch.dir = DIR_LEFT;
						player->ch.base_frame = player->ch.anim->frame_brake_left;
						player->ch.frame = 0;
					}
					status |= PLAYER_STATUS_BRAKE;
				}
				else
				{
					if (animate_character(&player->ch))
					{
						status |= PLAYER_STATUS_WALK;
					}
				}
			}

			if (button_1_4_pressed())
			{
				player->ch.dy = PLAYER_LIFT;
				player->ch.base_frame = 1;
				player->state = PLAYER_STATE_FLAP;
				status |= PLAYER_STATUS_FLAP;
			}
			else if (!hit_over_platform(&player->ch.obj, &player->ch.dy, player->ch.dx))
			{
				if (player->ch.base_frame == player->ch.anim->frame_walk_left)
				{
					player->ch.base_frame = player->ch.anim->frame_left;
				}
				else if (player->ch.base_frame == player->ch.anim->frame_walk_right)
				{
					player->ch.base_frame = player->ch.anim->frame_right;
				}
				player->ch.frame = 0;
				player->state = PLAYER_STATE_NORMAL;
			}
			break;

		default:
			break;
	}

	hit_platform(&player->ch.obj, &player->ch.dy, &player->ch.dx);
	move_character(&player->ch);

	return status;
}

void draw_player(
	struct player *player
	)
{
	if (player->ch.obj.active)
	{
		if (player->state != PLAYER_STATE_DEAD)
		{
			draw_synced_list_c(
				player->ch.anim->shapes[player->ch.base_frame + player->ch.frame],
				player->ch.obj.y,
				player->ch.obj.x,
				OBJECT_MOVE_SCALE,
				player->ch.obj.scale
				);
		}
	}
}

struct enemy* interaction_enemies_player(
	struct player *player
	)
{
	struct enemy *enemy;
	struct enemy *result = 0;

	if (player->ch.obj.active)
	{
		enemy = (struct enemy *) enemy_list;
		while (enemy != 0)
		{
			if (player->state == PLAYER_STATE_NORMAL)
			{
				if (enemy->state == ENEMY_STATE_MOVE || enemy->state == ENEMY_STATE_STOP)
				{
					if (hit_object(&player->ch.obj, &enemy->ch.obj))
					{
						if (player->ch.obj.y > enemy->ch.obj.y)
						{
							hit_enemy(enemy);
						}
						else
						{
							player->state = PLAYER_STATE_DEAD;
						}
					}
				}
			}

			enemy = (struct enemy *) enemy->ch.obj.next;
		}
	}

	return result;
}

// ***************************************************************************
// end of file
// ***************************************************************************
