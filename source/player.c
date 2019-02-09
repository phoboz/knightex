// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "generic.h"
#include "controller.h"
#include "draw.h"
#include "platform.h"
#include "ostrich.h"
#include "player.h"

// ---------------------------------------------------------------------------

void init_player(
	struct player *player,
	signed int y,
	signed int x,
	unsigned int dir
	)
{
	init_character(
		&player->ch,
		y,
		x,
		PLAYER_HEIGHT,
		PLAYER_WIDTH,
		PLAYER_SCALE,
		PLAYER_SPEED,
		PLAYER_TRESHOLD,
		PLAYER_MAX_FRAMES,
		ostrich,
		0
		);

	player->state			= PLAYER_STATE_NORMAL;
	player->state_counter	= 0;
	player->speed_counter	= 0;

	set_dir_character(&player->ch, dir);
}

unsigned int move_player(
	struct player *player
	)
{
	unsigned int brake = 0;
	unsigned int status = 0;

	if (joystick_1_left())
	{
		if (player->ch.dir == DIR_LEFT)
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
			player->ch.dir = DIR_LEFT;
		}
	}
	else if (joystick_1_right())
	{
		if (player->ch.dir == DIR_RIGHT)
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
			player->ch.dir = DIR_RIGHT;
		}
	}

	player->ch.treshold = PLAYER_TRESHOLD - (unsigned int) abs(player->ch.dx);

	switch (player->state)
	{
		case PLAYER_STATE_NORMAL:
			if (player->ch.dx < 0)
			{
				player->ch.base_frame = OSTRICH_LEFT;
			}
			else if (player->ch.dx > 0)
			{
				player->ch.base_frame = OSTRICH_RIGHT;
			}
			else if (player->ch.dx == 0)
			{
				if (player->ch.dir == DIR_LEFT)
				{
					player->ch.base_frame = OSTRICH_LEFT;
				}
				else if (player->ch.dir == DIR_RIGHT)
				{
					player->ch.base_frame = OSTRICH_RIGHT;
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
				if (player->ch.base_frame == OSTRICH_LEFT)
				{
					player->ch.base_frame = OSTRICH_WALK_LEFT_START;
				}
				else if (player->ch.base_frame == OSTRICH_RIGHT)
				{
					player->ch.base_frame = OSTRICH_WALK_RIGHT_START;
				}
				status |= PLAYER_STATUS_WALK;
			}
			break;

		case PLAYER_STATE_FLAP:
			if (player->ch.dx < 0)
			{
				player->ch.base_frame = OSTRICH_LEFT;
			}
			else if (player->ch.dx > 0)
			{
				player->ch.base_frame = OSTRICH_RIGHT;
			}
			else if (player->ch.dx == 0)
			{
				if (player->ch.dir == DIR_LEFT)
				{
					player->ch.base_frame = OSTRICH_LEFT;
				}
				else if (player->ch.dir == DIR_RIGHT)
				{
					player->ch.base_frame = OSTRICH_RIGHT;
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
			if (player->ch.dx < 0 && player->ch.dir != DIR_LEFT)
			{
				player->ch.base_frame = OSTRICH_WALK_LEFT_START;
			}
			else if (player->ch.dx > 0 && player->ch.dir != DIR_RIGHT)
			{
				player->ch.base_frame = OSTRICH_WALK_RIGHT_START;
			}
			else if (player->ch.dx == 0)
			{
				if (player->ch.dir == DIR_LEFT)
				{
					player->ch.base_frame = OSTRICH_WALK_LEFT_START;
				}
				else if (player->ch.dir == DIR_RIGHT)
				{
					player->ch.base_frame = OSTRICH_WALK_RIGHT_START;
				}
				player->ch.frame = 0;
			}

			if (player->ch.dx != 0)
			{
				if (brake)
				{
					if (player->ch.dir == DIR_LEFT)
					{
						player->ch.base_frame = OSTRICH_BRAKE_RIGHT;
						player->ch.frame = 0;
					}
					else if (player->ch.dir == DIR_RIGHT)
					{
						player->ch.base_frame = OSTRICH_BRAKE_LEFT;
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
				player->ch.frame = 1;
				player->state = PLAYER_STATE_FLAP;
				status |= PLAYER_STATUS_FLAP;
			}
			else if (!hit_over_platform(&player->ch.obj, &player->ch.dy, player->ch.dx))
			{
				if (player->ch.base_frame == OSTRICH_WALK_LEFT_START)
				{
					player->ch.base_frame = OSTRICH_LEFT;
				}
				else if (player->ch.base_frame == OSTRICH_WALK_RIGHT_START)
				{
					player->ch.base_frame = OSTRICH_RIGHT;
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
				player->ch.shapes[player->ch.base_frame + player->ch.frame],
				player->ch.obj.y,
				player->ch.obj.x,
				OBJECT_MOVE_SCALE,
				player->ch.obj.scale
				);
		}
	}
}

// ***************************************************************************
// end of file
// ***************************************************************************
