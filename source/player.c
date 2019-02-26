// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "generic.h"
#include "controller.h"
#include "draw.h"
#include "platform.h"
#include "enemy.h"
#include "ostrich.h"
#include "knight.h"
#include "player.h"

// ---------------------------------------------------------------------------

static const struct character_anim player_anim =
{
	PLAYER_HEIGHT,
	PLAYER_WIDTH,
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
				if (player->control_dir == DIR_LEFT)
				{
					player->ch.dir = DIR_LEFT;
					player->ch.base_frame = player->ch.anim->frame_left;
				}
			}
			else if (player->ch.dx > 0)
			{
				if (player->control_dir == DIR_RIGHT)
				{
					player->ch.dir = DIR_RIGHT;
					player->ch.base_frame = player->ch.anim->frame_right;
				}
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
				if (player->ch.dir == DIR_LEFT)
				{
					player->ch.base_frame = player->ch.anim->frame_walk_left;
				}
				else if (player->ch.dir == DIR_RIGHT)
				{
					player->ch.base_frame = player->ch.anim->frame_walk_right;
				}
				player->state = PLAYER_STATE_WALK;
				status |= PLAYER_STATUS_WALK;
			}
			break;

		case PLAYER_STATE_FLAP:
			if (player->ch.dx < 0)
			{
				if (player->control_dir == DIR_LEFT)
				{
					player->ch.base_frame = player->ch.anim->frame_left;
				}
			}
			else if (player->ch.dx > 0)
			{
				if (player->control_dir == DIR_RIGHT)
				{
					player->ch.base_frame = player->ch.anim->frame_right;
				}
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
			if (player->ch.dx < 0)
			{
				if (player->control_dir == DIR_LEFT)
				{
					player->ch.dir = DIR_LEFT;
					player->ch.base_frame = player->ch.anim->frame_walk_left;
				}
			}
			else if (player->ch.dx > 0)
			{
				if (player->control_dir == DIR_RIGHT)
				{
					player->ch.dir = DIR_RIGHT;
					player->ch.base_frame = player->ch.anim->frame_walk_right;
				}
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
					if (player->ch.dir == DIR_LEFT)
					{
						player->ch.base_frame = player->ch.anim->frame_brake_left;
						player->ch.frame = 0;
					}
					else if (player->ch.dir == DIR_RIGHT)
					{
						player->ch.base_frame = player->ch.anim->frame_brake_right;
						player->ch.frame = 0;
					}
					player->state = PLAYER_STATE_BRAKE;
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
				if (player->ch.dir == DIR_LEFT)
				{
					player->ch.base_frame = player->ch.anim->frame_left;
				}
				else if (player->ch.dir == DIR_RIGHT)
				{
					player->ch.base_frame = player->ch.anim->frame_right;
				}
				player->ch.frame = 1;
				player->state = PLAYER_STATE_FLAP;
				status |= PLAYER_STATUS_FLAP;
			}
			else if (!hit_over_platform(&player->ch.obj, &player->ch.dy, player->ch.dx))
			{
				if (player->ch.dir == DIR_LEFT)
				{
					player->ch.base_frame = player->ch.anim->frame_left;
				}
				else if (player->ch.dir == DIR_RIGHT)
				{
					player->ch.base_frame = player->ch.anim->frame_right;
				}
				player->ch.frame = 0;
				player->state = PLAYER_STATE_NORMAL;
			}
			break;

		case PLAYER_STATE_BRAKE:
			if (!brake)
			{
				if (player->ch.dir == DIR_LEFT)
				{
					player->ch.base_frame = player->ch.anim->frame_walk_left;
				}
				else if (player->ch.dir == DIR_RIGHT)
				{
					player->ch.base_frame = player->ch.anim->frame_walk_right;
				}
				player->state = PLAYER_STATE_WALK;
			}
			else
			{
				status |= PLAYER_STATUS_BRAKE;
			}

			if (button_1_4_pressed())
			{
				player->ch.dy = PLAYER_LIFT;
				if (player->ch.dir == DIR_LEFT)
				{
					player->ch.base_frame = player->ch.anim->frame_left;
				}
				else if (player->ch.dir == DIR_RIGHT)
				{
					player->ch.base_frame = player->ch.anim->frame_right;
				}
				player->ch.frame = 1;
				player->state = PLAYER_STATE_FLAP;
				status |= PLAYER_STATUS_FLAP;
			}
			else if (!hit_over_platform(&player->ch.obj, &player->ch.dy, player->ch.dx))
			{
				if (player->ch.dir == DIR_LEFT)
				{
					player->ch.base_frame = player->ch.anim->frame_left;
				}
				else if (player->ch.dir == DIR_RIGHT)
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
	if (move_character(&player->ch) == 2)
	{
		player->state = PLAYER_STATE_DEAD;
	}

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
			signed int y = player->ch.obj.y;
			signed int x = player->ch.obj.x;
			
			
			dp_VIA_t1_cnt_lo = OBJECT_MOVE_SCALE;
            	dp_VIA_port_a = y;			// y pos to dac
            	dp_VIA_cntl = 0xce;	// disable zero, disable all blank
            	dp_VIA_port_b = 0;			// mux enable, dac to -> integrator y (and x)
            	dp_VIA_shift_reg = 0;		// all output is BLANK
            	dp_VIA_port_b++;			// mux disable, dac only to x
            	dp_VIA_port_a = x;			// dac -> x
            	dp_VIA_t1_cnt_hi=0;		// start timer
			dp_VIA_t1_cnt_lo = PLAYER_DRAW_SCALE;
            	while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes

			draw_vlp_1(player->ch.anim->shapes[player->ch.base_frame + player->ch.frame]);
/*			
			draw_synced_list_c(
				player->ch.anim->shapes[player->ch.base_frame + player->ch.frame],
				player->ch.obj.y,
				player->ch.obj.x,
				OBJECT_MOVE_SCALE,
				player->ch.obj.scale
				);
*/
			// ZERO
			dp_VIA_cntl=0xcc;
			
			dp_VIA_t1_cnt_lo = OBJECT_MOVE_SCALE;
            	dp_VIA_port_a = y;			// y pos to dac
            	dp_VIA_cntl = 0xce;	// disable zero, disable all blank
            	dp_VIA_port_b = 0;			// mux enable, dac to -> integrator y (and x)
            	dp_VIA_shift_reg = 0;		// all output is BLANK
            	dp_VIA_port_b++;			// mux disable, dac only to x
            	dp_VIA_port_a = x;			// dac -> x
            	dp_VIA_t1_cnt_hi=0;		// start timer
			dp_VIA_t1_cnt_lo = KNIGHT_DRAW_SCALE;
            	while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes
			draw_vlp_2(knight[player->ch.dir]);
/*
				draw_synced_list_c(
				knight[player->ch.dir],
				player->ch.obj.y,
				player->ch.obj.x,
				OBJECT_MOVE_SCALE,
				0x18/KNIGHT_SCALE
				);
*/			
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
