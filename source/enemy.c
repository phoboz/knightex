// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "generic.h"
#include "draw.h"
#include "platform.h"
#include "ostrich.h"
#include "knight.h"
#include "enemy.h"

// ---------------------------------------------------------------------------

extern const signed char* const spiral[];

static const struct character_anim enemy_anims[] =
{
	{
		10,						// h
		4,						// w
		4,						// treshold
		OSTRICH_LEFT,
		OSTRICH_RIGHT,
		2,						// max_frames
		OSTRICH_WALK_LEFT_START,
		OSTRICH_WALK_RIGHT_START,
		OSTRICH_BRAKE_LEFT,
		OSTRICH_BRAKE_RIGHT,
		ostrich					// vectorlists
	}
};

const struct enemy_race enemy_races[] =
{
	/*	type					speed	anim	*/
	{	ENEMY_TYPE_JOUSTER,	1,		&enemy_anims[0]	}
};

unsigned int enemy_status = 0;
struct object *enemy_list = 0;
struct object *enemy_free_list = 0;

static void set_dir_enemy(
	struct enemy *enemy,
	unsigned int dir
	)
{
	enemy->ch.dir = dir;

	if (dir == DIR_LEFT)
	{
		enemy->ch.base_frame = enemy->ch.anim->frame_left;
		enemy->ch.dy = 0;
		enemy->ch.dx = -enemy->ch.move_speed;
	}
	else if (dir == DIR_RIGHT)
	{
		enemy->ch.base_frame = enemy->ch.anim->frame_right;
		enemy->ch.dy = 0;
		enemy->ch.dx = enemy->ch.move_speed;
	}
}

void init_enemy(
	struct enemy *enemy,
	signed int y,
	signed int x,
	unsigned int dir,
	const struct enemy_race *race
	)
{
	take_object(&enemy->ch.obj, &enemy_free_list);
	init_character(&enemy->ch, y, x, race->speed, race->anim, &enemy_list);

	enemy->race			= race;
	enemy->spawn_counter	= 0;

	enemy->state = ENEMY_STATE_SPAWN;
	enemy->state_counter = 0;

	set_dir_enemy(enemy, dir);
}

void deinit_enemy(
	struct enemy *enemy
	)
{
	deinit_object(&enemy->ch.obj, &enemy_list);
	give_object(&enemy->ch.obj, &enemy_free_list);
}

void move_enemies(void)
{
	struct enemy *enemy;
	struct enemy *rem_enemy = 0;

	enemy_status = 0;

	enemy = (struct enemy *) enemy_list;
	while(enemy != 0)
	{
		if (enemy->state == ENEMY_STATE_MOVE)
		{
			switch (enemy->race->type)
			{
				case ENEMY_TYPE_JOUSTER:
					animate_character(&enemy->ch);
	
					if (!hit_platform(&enemy->ch.obj, &enemy->ch.dy, &enemy->ch.dx))
					{
						move_character(&enemy->ch);
					}
					else
					{
						if (enemy->ch.dir == DIR_LEFT)
						{
							set_dir_enemy(enemy, DIR_RIGHT);
						}
						else if (enemy->ch.dir == DIR_RIGHT)
						{
							set_dir_enemy(enemy, DIR_LEFT);
						}
					}
					break;

				default:
					break;
			}
		}
		else if (enemy->state == ENEMY_STATE_SPAWN)
		{
			if (++enemy->ch.counter >= ENEMY_SPAWN_ANIM_TRESHOLD)
			{
				enemy->ch.counter = 0;
				if (++enemy->ch.frame >= ENEMY_SPAWN_ANIM_FRAMES)
				{
					enemy->ch.frame = 0;
				}
			}

			if (++enemy->state_counter >= ENEMY_SPAWN_TRESHOLD)
			{
				enemy->ch.counter = 0;
				enemy->ch.frame = 0;
				enemy->state = ENEMY_STATE_MOVE;
				enemy->state_counter = 0;
			}
		}
		else if (enemy->state == ENEMY_STATE_STOP)
		{
			if (++enemy->state_counter >= ENEMY_STOP_TRESHOLD)
			{
				enemy->state = ENEMY_STATE_MOVE;
				enemy->state_counter = 0;
			}
		}
		else if (enemy->state == ENEMY_STATE_DYING)
		{
			rem_enemy = enemy;
		}
		enemy = (struct enemy *) enemy->ch.obj.next;

		if (rem_enemy != 0)
		{
			rem_enemy->state = ENEMY_STATE_DEAD;
			rem_enemy->state_counter = 0;
			deinit_enemy(rem_enemy);
			rem_enemy = 0;
		}
	}
}

unsigned int hit_enemy(
	struct enemy *enemy
	)
{
	unsigned int result = 0;

	enemy->state = ENEMY_STATE_DYING;
	enemy->state_counter = 0;
	result = 1;

	return result;
}

void draw_enemies(void)
{
	struct enemy *enemy;

	enemy = (struct enemy *) enemy_list;
	while (enemy != 0)
	{
		if (enemy->state == ENEMY_STATE_MOVE || enemy->state == ENEMY_STATE_STOP)
		{
			// ZERO
			dp_VIA_cntl=0xcc;

			signed int y = enemy->ch.obj.y;
			signed int x = enemy->ch.obj.x;
			
			
			dp_VIA_t1_cnt_lo = OBJECT_MOVE_SCALE;
            	dp_VIA_port_a = y;			// y pos to dac
            	dp_VIA_cntl = 0xce;	// disable zero, disable all blank
            	dp_VIA_port_b = 0;			// mux enable, dac to -> integrator y (and x)
            	dp_VIA_shift_reg = 0;		// all output is BLANK
            	dp_VIA_port_b++;			// mux disable, dac only to x
            	dp_VIA_port_a = x;			// dac -> x
            	dp_VIA_t1_cnt_hi=0;		// start timer
			dp_VIA_t1_cnt_lo = ENEMY_DRAW_SCALE;
            	while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes

			draw_vlp_1(enemy->ch.anim->shapes[enemy->ch.base_frame + enemy->ch.frame]);
			
			// ZERO
			dp_VIA_cntl=0xcc;
			
/*						
			draw_synced_list_c(
				enemy->ch.anim->shapes[enemy->ch.base_frame + enemy->ch.frame],
				enemy->ch.obj.y,
				enemy->ch.obj.x,
				OBJECT_MOVE_SCALE,
				enemy->ch.obj.scale
				);
*/			
			

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
			draw_vlp_2(knight[enemy->ch.dir]);			
			
/*
			draw_synced_list_c(
				knight[enemy->ch.dir],
				enemy->ch.obj.y,
				enemy->ch.obj.x,
				OBJECT_MOVE_SCALE,
				0x18/KNIGHT_SCALE
				);
*/			
		}
		else if (enemy->state == ENEMY_STATE_SPAWN)
		{
			draw_synced_list_c(
				spiral[enemy->ch.frame],
				enemy->ch.obj.y,
				enemy->ch.obj.x,
				OBJECT_MOVE_SCALE,
				0x01 + (enemy->state_counter >> 2)
				);
		}
		enemy = (struct enemy *) enemy->ch.obj.next;
	}
}

// ***************************************************************************
// end of file
// ***************************************************************************
