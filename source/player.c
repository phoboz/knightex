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
	OSTRICH_RISE_LEFT_END - OSTRICH_RISE_LEFT_START + 1,
	OSTRICH_RISE_LEFT_START,
	OSTRICH_RISE_RIGHT_START,
	ostrich
};

unsigned int init_player(
	struct player *player
	)
{
	unsigned int status;
	const struct platform_pad *pad;

	pad = get_platform_pad(PLAYER_INIT_PAD_INDEX);
	if (pad)
	{
		init_character(&player->ch, pad->y, pad->x, PLAYER_SPEED, &player_anim, 0);
		init_character_0(&player->ch_0, pad->y, pad->x, 1, &player_anim);

		player->ch_0.obj.active = 0;

		player->state			= PLAYER_STATE_RISE;
		player->state_counter	= 0;
		player->speed_counter	= 0;
		player->hit_roof		= 0;
		player->roof_counter	= 0;
		player->flap_countdown = 0;

		player->control_dir = pad->dir;
		player->ch.dir = pad->dir;
		if (pad->dir == DIR_LEFT)
		{
			player->ch.base_frame = player->ch.anim->frame_rise_left;
		}
		else if (pad->dir == DIR_RIGHT)
		{
			player->ch.base_frame = player->ch.anim->frame_rise_right;
		}
		status = 1;
	}
	else
	{
		status = 0;
	}

	return status;
}

unsigned int move_player(
	struct player *player
	)
{
	unsigned int brake = 0;
	unsigned int status = 0;

	if (player->state < PLAYER_STATE_INACTIVE)
	{
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
	}

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

			if (player->flap_countdown != 0)
			{
				player->flap_countdown--;
			}

			if (button_1_4_pressed() && player->flap_countdown == 0)
			{
				player->ch.dy = PLAYER_LIFT;
				player->ch.frame = 1;
				status |= PLAYER_STATUS_FLAP;
				if (!hit_platform(&player->ch.obj, &player->ch.dy, &player->ch.dx))
				{
					player->state_counter = 0;
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
				player->state_counter = 0;
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
				if (!player->hit_roof)
				{
					player->hit_roof = 1;
					player->roof_counter = 0;
				}

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
					player->state_counter = 0;
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
				player->state_counter = 0;
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
				player->state_counter = 0;
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
				player->state_counter = 0;
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
				player->state_counter = 0;
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
				player->state_counter = 0;
				player->state = PLAYER_STATE_NORMAL;
			}
			break;

		case PLAYER_STATE_RISE:
			if (++player->ch.counter == player->ch.anim->treshold)
			{
				player->ch.counter = 0;
				if (++player->ch.frame == player->ch.anim->max_rise_frames)
				{
					if (player->ch.dir == DIR_LEFT)
					{
						player->ch.base_frame = player->ch.anim->frame_walk_left;
					}
					else if (player->ch.dir == DIR_RIGHT)
					{
						player->ch.base_frame = player->ch.anim->frame_walk_right;
					}
					player->ch.frame = 0;
					player->state_counter = 0;
					player->state = PLAYER_STATE_WALK;
				}
			}
			break;

		case PLAYER_STATE_HIT:
			if (hit_over_platform(&player->ch_0.obj, &player->ch_0.dy, player->ch_0.dx))
			{
				player->ch_0.dx = 0;
				player->ch_0.frame = KNIGHT_DEAD;
			}

			if (move_character(&player->ch_0) == 2)
			{
				player->state_counter = 0;
				player->state = PLAYER_STATE_DROWNED;
			}

			if (!hit_over_platform(&player->ch.obj, &player->ch.dy, player->ch.dx))
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

			if (player->ch_0.obj.active)
			{
				if (check_move_character(&player->ch))
				{
					player->ch_0.obj.active = 0;
					player->ch.dy = 0;
					player->ch.dx = 0;
				}
			}
			else
			{
				if (++player->state_counter == PLAYER_DIE_TRESHOLD)
				{
					player->state_counter = 0;
					player->state = PLAYER_STATE_DEAD;
				}
			}
			break;

		case PLAYER_STATE_DROWNED:
			if (++player->state_counter == PLAYER_DIE_TRESHOLD)
			{
				player->state_counter = 0;
				player->state = PLAYER_STATE_DEAD;
			}
			break;

		default:
			break;
	}

	hit_platform(&player->ch.obj, &player->ch.dy, &player->ch.dx);

	unsigned int result = move_character(&player->ch);
	if (result == 2)
	{
		if (player->state != PLAYER_STATE_HIT)
		{
			player->state_counter = 0;
			player->state = PLAYER_STATE_DROWNED;
		}
	}
	else if (result == 1)
	{
		if (!player->hit_roof)
		{
			player->hit_roof = 1;
			player->roof_counter = 0;
		}
	}

	if (player->hit_roof)
	{
		if (++player->roof_counter == PLAYER_ROOF_TRESHOLD)
		{
			player->roof_counter = 0;
			player->hit_roof = 0;
		}
	}

	return status;
}


void draw_player(
	struct player *player
	)
{
	if (player->ch.obj.active)
	{
		if (player->state >= PLAYER_STATE_NORMAL && player->state <= PLAYER_STATE_BRAKE)
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
		else if (player->state == PLAYER_STATE_RISE)
		{
			unsigned int base_frame = 0;
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

			if (player->ch.dir == DIR_LEFT)
			{
				base_frame = KNIGHT_RISE_LEFT_START;
			}
			else if (player->ch.dir == DIR_RIGHT)
			{
				base_frame = KNIGHT_RISE_RIGHT_START;
			}

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
			draw_vlp_2(knight[base_frame + player->ch.frame]);
		}
		else if (player->state == PLAYER_STATE_HIT)
		{			
			signed int y;
			signed int x;

			if (player->ch_0.obj.active)
			{
				y = player->ch.obj.y;
 				x = player->ch.obj.x;
			
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
			}

			y = player->ch_0.obj.y - 4;
			x = player->ch_0.obj.x;

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
			draw_vlp_2(knight[player->ch_0.frame]);
		}
	}
}

static void bounce_player(
	struct player *player,
	signed int x,
	signed int speed
	)
{
	if (player->ch.dir == DIR_LEFT)
	{
		if (x < player->ch.obj.x)
		{
			player->ch.dx = speed;
		}
		else
		{
			player->ch.dx = -speed;
		}
	}
	else if (player->ch.dir == DIR_RIGHT)
	{
		if (x > player->ch.obj.x)
		{
			player->ch.dx = -speed;
		}
		else
		{
			player->ch.dx = speed;
		}
	}
}

static void hit_player(
	struct player *player,
	signed int x
	)
{
	player->ch_0.obj.active = 1;
	player->ch_0.obj.y = player->ch.obj.y;
	player->ch_0.obj.x = player->ch.obj.x;
	player->ch_0.dy = -PLAYER_KNIGHT_FALL_SPEED;
	player->ch_0.dx = -player->ch.dx;
	player->ch_0.frame = player->ch.dir;

	player->ch.dy = 0;
	bounce_player(player, x, player->ch.move_speed);

	player->state_counter = 0;
	player->state = PLAYER_STATE_HIT;
	player->points_x10 += 5;
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
			if (player->state < PLAYER_STATE_INACTIVE)
			{
				if (enemy->state < ENEMY_STATE_INACTIVE)
				{
					if (hit_object(&player->ch.obj, &enemy->ch.obj))
					{
						if (player->ch.obj.y == enemy->ch.obj.y)
						{
							if (hit_enemy_equal(enemy, player->ch.dir, player->ch.dx))
							{
								hit_player(player, enemy->ch.obj.x);
							}
							else
							{
								if (player->ch.dir != enemy->ch.dir)
								{
									bounce_player(player, enemy->ch.obj.x, 1);
								}

								if (enemy->state == ENEMY_STATE_COLLECT)
								{
									player->points_x10 += enemy->race->points_x10;
								}
							}
						}
						else if (player->ch.obj.y > enemy->ch.obj.y)
						{
							if (player->hit_roof)
							{
								if (enemy->race->type == ENEMY_TYPE_PTERY)
								{
									hit_player(player, enemy->ch.obj.x);
								}
								else
								{
									bounce_player(player, enemy->ch.obj.x, 2);
									enemy->ch.dx = -enemy->ch.dx;
									player->state = PLAYER_STATE_NORMAL;
									player->state_counter = 0;
									player->ch.frame = 0;
									player->ch.dy = -1;
									player->flap_countdown = PLAYER_FLAP_DELAY_TRESHOLD;
								}
							}
							else
							{
								if (hit_enemy_over(enemy))
								{
									hit_player(player, enemy->ch.obj.x);
								}
								else
								{
									player->points_x10 += enemy->race->points_x10;
								}
							}
						}
						else
						{
							hit_player(player, enemy->ch.obj.x);
						}
					}
				}
				else if (enemy->state > ENEMY_STATE_COL_START &&
						enemy->state < ENEMY_STATE_COL_END)
				{
					if (hit_object(&player->ch.obj, &enemy->ch.obj))
					{
						player->points_x10 += collect_enemy(enemy);
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
