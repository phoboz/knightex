// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "generic.h"
#include "draw.h"
#include "platform.h"
#include "vulture.h"
#include "starling.h"
#include "eagle.h"
#include "ptery.h"
#include "knight.h"
#include "egg.h"
#include "number.h"
#include "player.h"
#include "enemy.h"

// ---------------------------------------------------------------------------

signed int target_y, target_x;

static const struct character_anim enemy_anims[] =
{
	/* Vulture */
	{
		10,						// h
		4,						// w
		3,						// treshold
		VULTURE_LEFT,
		VULTURE_RIGHT,
		VULTURE_WALK_LEFT_END - VULTURE_WALK_LEFT_START + 1, // max_frames
		VULTURE_WALK_LEFT_START,
		VULTURE_WALK_RIGHT_START,
		VULTURE_BRAKE_LEFT,
		VULTURE_BRAKE_RIGHT,
		VULTURE_RISE_LEFT_END - VULTURE_RISE_LEFT_START + 1, // max_frames
		VULTURE_RISE_LEFT_START,
		VULTURE_RISE_RIGHT_START,
		vulture					// vectorlists
	},

	/* Starling */
	{
		10,						// h
		4,						// w
		3,						// treshold
		STARLING_LEFT,
		STARLING_RIGHT,
		STARLING_WALK_LEFT_END - STARLING_WALK_LEFT_START + 1, // max_frames
		STARLING_WALK_LEFT_START,
		STARLING_WALK_RIGHT_START,
		STARLING_BRAKE_LEFT,
		STARLING_BRAKE_RIGHT,
		STARLING_RISE_LEFT_END - STARLING_RISE_LEFT_START + 1, // max_frames
		STARLING_RISE_LEFT_START,
		STARLING_RISE_RIGHT_START,
		starling					// vectorlists
	},

	/* Eagle */
	{
		10,						// h
		5,						// w
		3,						// treshold
		EAGLE_LEFT,
		EAGLE_RIGHT,
		EAGLE_WALK_LEFT_END - EAGLE_WALK_LEFT_START + 1, // max_frames
		EAGLE_WALK_LEFT_START,
		EAGLE_WALK_RIGHT_START,
		EAGLE_BRAKE_LEFT,
		EAGLE_BRAKE_RIGHT,
		EAGLE_RISE_LEFT_END - EAGLE_RISE_LEFT_START + 1, // max_frames
		EAGLE_RISE_LEFT_START,
		EAGLE_RISE_RIGHT_START,
		eagle					// vectorlists
	},

	/* Ptery */
	{
		8,						// h
		12,						// w
		5,						// treshold
		PTERY_LEFT,
		PTERY_RIGHT,
		PTERY_FLAP_LEFT - PTERY_LEFT + 1,
		PTERY_LEFT,
		PTERY_RIGHT,
		PTERY_ATTACK_LEFT,
		PTERY_ATTACK_RIGHT,
		0,						// max_frames
		0,
		0,
		ptery
	}
};

const struct enemy_race enemy_races[] =
{
	/*	type					points_x10	speed	speed_treshold	flap_treshold		gravity_treshold	rise_treshold	reaction_treshold	bounce_treshold	attack_treshold	retreat_treshold	anim				*/
	{	ENEMY_TYPE_BOUNCER,	50,			2,		6,				24,				3,				2,			24,				12,				255,				255,				&enemy_anims[0]	},
	{	ENEMY_TYPE_HUNTER,		75,			2,		5,				32,				3,				1,			16,				12,				255,				255,				&enemy_anims[1]	},
	{	ENEMY_TYPE_LORD,		150,			4,		3,				24,				4,				1,			12,				8,				255,				255,				&enemy_anims[2]	},
	{	ENEMY_TYPE_PTERY,		100,			3,		2,				255,				4,				4,			16,				56,				100,				32,				&enemy_anims[3]	}
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
		enemy->target_speed = -enemy->ch.move_speed;
	}
	else if (dir == DIR_RIGHT)
	{
		enemy->ch.base_frame = enemy->ch.anim->frame_right;
		enemy->ch.dy = 0;
		enemy->target_speed = enemy->ch.move_speed;
	}
}

void init_enemy(
	struct enemy *enemy,
	signed int y,
	signed int x,
	unsigned int dir,
	unsigned int state,
	const struct enemy_race *race
	)
{
	take_object(&enemy->ch.obj, &enemy_free_list);
	init_character(&enemy->ch, y, x, race->speed, race->anim, &enemy_list);
	init_character_0(&enemy->ch_0, y, x, 1, race->anim);

	enemy->ch_0.obj.active = 0;

	enemy->race = race;

	enemy->speed_counter		= 0;
	enemy->gravity_counter		= 0;
	enemy->rise_counter		= 0;
	enemy->invisible_counter	= ENEMY_INVISIBLE_TRESHOLD;
	enemy->attack_counter		= 0;
	enemy->window_counter		= 0;
	enemy->number_counter		= 0;

	enemy->state = state;
	enemy->state_counter = 0;

	set_dir_enemy(enemy, dir);
}

unsigned int init_enemy_at_pad(
	struct enemy *enemy,
	unsigned int pad_index,
	const struct enemy_race *race
	)
{
	unsigned int result;
	const struct platform_pad *pad;

	pad = get_platform_pad(pad_index);
	if (pad)
	{
		init_enemy(enemy, pad->y, pad->x, pad->dir, ENEMY_STATE_RISE, race);
		if (pad->dir == DIR_LEFT)
		{
			enemy->ch.base_frame = enemy->ch.anim->frame_rise_left;
		}
		else if (pad->dir == DIR_RIGHT)
		{
			enemy->ch.base_frame = enemy->ch.anim->frame_rise_right;
		}
		result = 1;
	}
	else
	{
		result = 0;
	}

	return result;
}

void init_enemy_in_sky(
	struct enemy *enemy,
	unsigned int dir,
	signed int y,
	const struct enemy_race *race
	)
{
	if (dir == DIR_LEFT)
	{
		init_enemy(enemy, y, CHARACTER_MAX_X - 1, dir, ENEMY_STATE_STOP, race);
	}
	else if (dir == DIR_RIGHT)
	{
		init_enemy(enemy, y, CHARACTER_MIN_X + 1, dir, ENEMY_STATE_STOP, race);
	}
}

unsigned int init_egg_at_location(
	struct enemy *enemy,
	unsigned int loc_index,
	const struct enemy_race *race
	)
{
	unsigned int result;
	const struct egg_location *loc;

	loc = get_egg_location(loc_index);
	if (loc)
	{
		init_enemy(enemy, loc->y, loc->x, loc->dir, ENEMY_STATE_EGG, race);
		result = 1;
	}
	else
	{
		result = 0;
	}

	return result;
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
	unsigned int enemy_type;
	struct enemy *rem_enemy = 0;

	enemy_status = 0;

	enemy = (struct enemy *) enemy_list;
	while(enemy != 0)
	{
		if (++enemy->window_counter == ENEMY_TIME_WINDOW)
		{
			enemy->window_counter = 0;
			enemy->number_counter = 0;
		}

		if (enemy->invisible_counter < ENEMY_INVISIBLE_TRESHOLD)
		{
			enemy->invisible_counter++;
		}

		enemy_type = enemy->race->type;

		if (enemy->state == ENEMY_STATE_MOVE)
		{
			if (++enemy->speed_counter == enemy->race->speed_treshold)
			{
				enemy->speed_counter = 0;
				if (enemy->ch.dx < enemy->target_speed)
				{
					enemy->ch.dx++;
				}
				else if (enemy->ch.dx > enemy->target_speed)
				{
					enemy->ch.dx--;
				}
			}

			if (++enemy->gravity_counter == enemy->race->gravity_treshold)
			{
				enemy->gravity_counter = 0;
				enemy->ch.dy = -1;
			}
			else
			{
				enemy->ch.dy = 0;
			}

			if (enemy_type >= ENEMY_TYPE_BOUNCER && enemy_type <= ENEMY_TYPE_LORD)
			{
				if (hit_over_platform(&enemy->ch.obj, &enemy->ch.dy, enemy->ch.dx))
				{
					if (enemy->ch.dir == DIR_LEFT)
					{
						enemy->ch.base_frame = enemy->ch.anim->frame_walk_left;
					}
					else if (enemy->ch.dir == DIR_RIGHT)
					{
						enemy->ch.base_frame = enemy->ch.anim->frame_walk_right;
					}
					enemy->state_counter = 0;
					enemy->state = ENEMY_STATE_WALK;
				}
				else if (!hit_platform(&enemy->ch.obj, &enemy->ch.dy, &enemy->ch.dx))
				{
					if (move_character(&enemy->ch) == 2)
					{
						enemy->state_counter = 0;
						enemy->state = ENEMY_STATE_REMOVE;
					}

					if (++enemy->state_counter == enemy->race->reaction_treshold)
					{
						enemy->state_counter = 0;
						if (enemy_type == ENEMY_TYPE_HUNTER)
						{
							if (enemy->ch.obj.x < target_x)
							{
								set_dir_enemy(enemy, DIR_RIGHT);
							}
							else if (enemy->ch.obj.x > target_x)
							{
								set_dir_enemy(enemy, DIR_LEFT);
							}
						}

						if (enemy->ch.obj.y < target_y)
						{
							enemy->state = ENEMY_STATE_FLAP;
						}
						else
						{
							if (enemy_type == ENEMY_TYPE_LORD)
							{
								if (enemy->ch.obj.y < ENEMY_LORD_MIN_Y)
								{
									enemy->state = ENEMY_STATE_FLAP;
								}
							}
						}
					}
				}
				else
				{
					enemy->state_counter = 0;
					enemy->number_counter++;
					enemy->state = ENEMY_STATE_BOUNCE;
				}
			}
			else if (enemy_type == ENEMY_TYPE_PTERY)
			{
				if (enemy->ch.frame == PTERY_ATTACK_FRAME)
				{
					if (++enemy->attack_counter >= enemy->race->retreat_treshold)
					{
						enemy->attack_counter = 0;
						enemy->ch.frame = 0;
					}
				}
				else
				{
					animate_character(&enemy->ch);

					if (++enemy->attack_counter >= enemy->race->attack_treshold)
					{
						enemy->attack_counter = 0;
						enemy->ch.frame = PTERY_ATTACK_FRAME;
					}
				}

				unsigned int ret = check_move_character(&enemy->ch);
				if (!ret)
				{
					enemy->ch.obj.y += enemy->ch.dy;
					enemy->ch.obj.x += enemy->ch.dx;
				}
				else if (ret == 2)
				{
					enemy->state_counter = 0;
					enemy->state = ENEMY_STATE_REMOVE;
				}
				else if (ret == 3)
				{
					if (enemy->ch.dir == DIR_LEFT)
					{
						enemy->ch.base_frame = enemy->ch.anim->frame_right;
						enemy->ch.dir = DIR_RIGHT;
						enemy->ch.dx = enemy->ch.move_speed;
					}
					else if (enemy->ch.dir == DIR_RIGHT)
					{
						enemy->ch.base_frame = enemy->ch.anim->frame_left;
						enemy->ch.dir = DIR_LEFT;
						enemy->ch.dx = -enemy->ch.move_speed;
					}
					enemy->ch.frame = 0;
					enemy->state_counter = 0;
					enemy->state = ENEMY_STATE_STOP;
				}
			}
		}
		else if (enemy->state == ENEMY_STATE_FLAP)
		{
			if (++enemy->speed_counter == enemy->race->speed_treshold)
			{
				enemy->speed_counter = 0;
				if (enemy->ch.dx < enemy->target_speed)
				{
					enemy->ch.dx++;
				}
				else if (enemy->ch.dx > enemy->target_speed)
				{
					enemy->ch.dx--;
				}
			}

			if (++enemy->rise_counter == enemy->race->rise_treshold)
			{
				enemy->rise_counter = 0;
				enemy->ch.dy = 1;
			}
			else
			{
				enemy->ch.dy = 0;
			}

			if (enemy_type >= ENEMY_TYPE_BOUNCER && enemy_type <= ENEMY_TYPE_LORD)
			{
				animate_character_limit(&enemy->ch, 2);

				if (!hit_platform(&enemy->ch.obj, &enemy->ch.dy, &enemy->ch.dx))
				{
					if (move_character(&enemy->ch) == 2)
					{
						enemy->state_counter = 0;
						enemy->state = ENEMY_STATE_REMOVE;
					}

					if (++enemy->state_counter == enemy->race->flap_treshold)
					{
						enemy->ch.frame = 0;
						enemy->state_counter = 0;
						enemy->state = ENEMY_STATE_MOVE;
					}
				}
				else
				{
					enemy->ch.frame = 0;
					enemy->state_counter = 0;
					enemy->number_counter++;
					enemy->state = ENEMY_STATE_BOUNCE;
				}
			}
			else if (enemy_type == ENEMY_TYPE_PTERY)
			{
				animate_character(&enemy->ch);
				unsigned int ret = check_move_character(&enemy->ch);
				if (!ret)
				{
					enemy->ch.obj.y += enemy->ch.dy;
					enemy->ch.obj.x += enemy->ch.dx;
				}
				if (ret == 2)
				{
					enemy->state_counter = 0;
					enemy->state = ENEMY_STATE_REMOVE;
				}
				else if (ret == 3)
				{
					if (enemy->ch.dir == DIR_LEFT)
					{
						enemy->ch.base_frame = enemy->ch.anim->frame_right;
						enemy->ch.dir = DIR_RIGHT;
						enemy->ch.dx = enemy->ch.move_speed;
					}
					else if (enemy->ch.dir == DIR_RIGHT)
					{
						enemy->ch.base_frame = enemy->ch.anim->frame_left;
						enemy->ch.dir = DIR_LEFT;
						enemy->ch.dx = -enemy->ch.move_speed;
					}
					enemy->ch.frame = 0;
					enemy->state_counter = 0;
					enemy->state = ENEMY_STATE_STOP;
				}
			}
		}
		else if (enemy->state == ENEMY_STATE_BOUNCE)
		{
			if (++enemy->gravity_counter == enemy->race->gravity_treshold)
			{
				enemy->gravity_counter = 0;
				enemy->ch.dy = -1;
			}
			else
			{
				enemy->ch.dy = 0;
			}

			if (!hit_platform(&enemy->ch.obj, &enemy->ch.dy, &enemy->ch.dx))
			{
				if (move_character(&enemy->ch) == 2)
				{
					enemy->state_counter = 0;
					enemy->state = ENEMY_STATE_REMOVE;
				}
			}

			if (++enemy->state_counter == enemy->race->bounce_treshold)
			{
				if (enemy->number_counter >= ENEMY_MAX_BOUNCES)
				{
					enemy->window_counter = 0;
					enemy->number_counter = 0;
					if (enemy->ch.dir == DIR_LEFT)
					{
						set_dir_enemy(enemy, DIR_RIGHT);
					}
					else if (enemy->ch.dir == DIR_RIGHT)
					{
						set_dir_enemy(enemy, DIR_LEFT);
					}
				}

				enemy->state_counter = 0;

				if (enemy->ch.obj.y > target_y)
				{
					enemy->state = ENEMY_STATE_MOVE;
				}
				else
				{
					enemy->state = ENEMY_STATE_FLAP;
				}
			}
		}
		else if (enemy->state == ENEMY_STATE_WALK)
		{
			animate_character(&enemy->ch);

			if (++enemy->state_counter == enemy->race->reaction_treshold)
			{
				if (enemy->ch.dir == DIR_LEFT)
				{
					enemy->ch.base_frame = enemy->ch.anim->frame_left;
				}
				else if (enemy->ch.dir == DIR_RIGHT)
				{
					enemy->ch.base_frame = enemy->ch.anim->frame_right;
				}
				enemy->ch.frame = 0;
				enemy->state_counter = 0;
				enemy->state = ENEMY_STATE_FLAP;
			}
			else if (!hit_over_platform(&enemy->ch.obj, &enemy->ch.dy, enemy->ch.dx))
			{
				if (enemy->ch.dir == DIR_LEFT)
				{
					enemy->ch.base_frame = enemy->ch.anim->frame_left;
				}
				else if (enemy->ch.dir == DIR_RIGHT)
				{
					enemy->ch.base_frame = enemy->ch.anim->frame_right;
				}
				enemy->ch.frame = 0;
				enemy->state_counter = 0;
				enemy->state = ENEMY_STATE_MOVE;
			}
			else if (!hit_platform(&enemy->ch.obj, &enemy->ch.dy, &enemy->ch.dx))
			{
				if (move_character(&enemy->ch) == 2)
				{
					enemy->state_counter = 0;
					enemy->state = ENEMY_STATE_REMOVE;
				}
			}
		}
		else if (enemy->state == ENEMY_STATE_EGG_DROP)
		{
			if (enemy->ch.dy < 0)
			{
				if (enemy->ch.dx < 0)
				{
					enemy->ch.frame = EGG_FRAME_DROP_LEFT;
				}
				else if (enemy->ch.dx > 0)
				{
					enemy->ch.frame = EGG_FRAME_DROP_RIGHT;
				}
				else
				{
					enemy->ch.frame = EGG_FRAME_DROP;
				}

				if (move_character(&enemy->ch) == 2)
				{
					enemy->state_counter = 0;
					enemy->state = ENEMY_STATE_REMOVE;
				}
				else if (hit_over_platform(&enemy->ch.obj, &enemy->ch.dy, enemy->ch.dx))
				{
					if (enemy->ch.dx > 0)
					{
						if (--enemy->ch.dx == 0)
						{
							enemy->ch.dx = 1;
						}
					}
					else if (enemy->ch.dx < 0)
					{
						if (++enemy->ch.dx == 0)
						{
							enemy->ch.dx = -1;
						}
					}
				}
			}
			else if (enemy->ch.dy > 0)
			{
				if (enemy->ch.dx < 0)
				{
					enemy->ch.frame = EGG_FRAME_DROP_RIGHT;
				}
				else if (enemy->ch.dx > 0)
				{
					enemy->ch.frame = EGG_FRAME_DROP_LEFT;
				}
				else
				{
					enemy->ch.frame = EGG_FRAME_DROP;
				}

				if (enemy->ch.obj.y < enemy->ch_0.obj.y)
				{
					if (move_character(&enemy->ch) == 2)
					{
						enemy->state_counter = 0;
						enemy->state = ENEMY_STATE_REMOVE;
					}
					else if (hit_platform(&enemy->ch.obj, &enemy->ch.dy, &enemy->ch.dx))
					{
						enemy->ch.dy = -1;
					}
				}
				else
				{
					enemy->ch.dy = -1;
				}
			}
			else
			{
				enemy->ch_0.dy = (enemy->ch_0.obj.y - enemy->ch.obj.y) >> 1;
				if (enemy->ch_0.dy)
				{
					enemy->ch_0.obj.y -= enemy->ch_0.dy;
					enemy->ch.dy = 1;
				}
				else
				{
					enemy->ch.dx = 0;
					enemy->ch.frame = EGG_FRAME_STILL;
					enemy->state = ENEMY_STATE_EGG;
					enemy->state_counter = 0;
				}
			}
		}
		else if (enemy->state == ENEMY_STATE_EGG)
		{
			if (++enemy->state_counter >= ENEMY_EGG_TRESHOLD)
			{
				enemy->ch.frame = EGG_FRAME_HATCH;
				enemy->state = ENEMY_STATE_EGG_HATCH;
				enemy->state_counter = 0;
			}
		}
		else if (enemy->state == ENEMY_STATE_EGG_HATCH)
		{
			if (++enemy->state_counter >= ENEMY_EGG_HATCH_TRESHOLD)
			{
				enemy->state = ENEMY_STATE_KNIGHT;
				enemy->state_counter = 0;
			}
		}
		else if (enemy->state == ENEMY_STATE_KNIGHT)
		{
			if (++enemy->state_counter == ENEMY_KNIGHT_TRESHOLD)
			{
				enemy->ch_0.obj.y = enemy->ch.obj.y + ENEMY_CALL_BIRD_DY;

				if (enemy->ch.obj.x < 0)
				{
					enemy->ch_0.obj.x = CHARACTER_MIN_X;
					enemy->ch_0.base_frame = enemy->ch.anim->frame_right;
					set_dir_character(&enemy->ch_0, DIR_RIGHT);
				}
				else
				{
					enemy->ch_0.obj.x = CHARACTER_MAX_X;
					enemy->ch_0.base_frame = enemy->ch.anim->frame_left;
					set_dir_character(&enemy->ch_0, DIR_LEFT);
				}

				enemy->ch_0.obj.active = 1;
				enemy->ch_0.frame = 0;

				enemy->state = ENEMY_STATE_CALL_BIRD;
				enemy->state_counter = 0;
			}
		}
		else if (enemy->state == ENEMY_STATE_CALL_BIRD)
		{
			unsigned int match_y = 0;

			if (enemy->ch_0.obj.y > enemy->ch.obj.y)
			{
				if (++enemy->gravity_counter == enemy->race->gravity_treshold)
				{
					enemy->gravity_counter = 0;
					enemy->ch_0.dy = -1;
				}
				else
				{
					enemy->ch_0.dy = 0;
				}
			}
			else
			{
				enemy->ch_0.dy = 0;
				match_y = 1;
			}

			if (enemy->ch_0.obj.x == enemy->ch.obj.x && match_y)
			{
				enemy->ch_0.obj.active = 0;
				enemy->state_counter = 0;
				set_dir_enemy(enemy, enemy->ch_0.dir);
				enemy->state = ENEMY_STATE_MOVE;
			}
			else
			{
				if (++enemy->ch_0.counter >= ENEMY_FLY_FLAP_TRESHOLD)
				{
					enemy->ch_0.counter = 0;
					if (++enemy->ch_0.frame > 1)
					{
						enemy->ch_0.frame = 0;
					}
				}

				move_character(&enemy->ch_0);
			}
		}
		else if (enemy->state == ENEMY_STATE_COLLECT)
		{
			if (++enemy->state_counter == ENEMY_COLLECT_TRESHOLD)
			{
				enemy->state_counter = 0;
				enemy->state = ENEMY_STATE_REMOVE;
			}
		}
		else if (enemy->state == ENEMY_STATE_COLLECT_ZOMBIE)
		{
			if (++enemy->state_counter == ENEMY_COLLECT_TRESHOLD)
			{
				enemy->state_counter = 0;
				enemy->state = ENEMY_STATE_ZOMBIE;
			}
			else if (enemy->ch_0.obj.active)
			{
				if (++enemy->ch_0.counter >= ENEMY_FLY_FLAP_TRESHOLD)
				{
					enemy->ch_0.counter = 0;
					if (++enemy->ch_0.frame > 1)
					{
						enemy->ch_0.frame = 0;
					}
				}

				if (move_character(&enemy->ch_0))
				{
					enemy->ch_0.obj.active = 0;
					// Do not reset: enemy->state_counter = 0;
					enemy->state = ENEMY_STATE_COLLECT;
				}
			}
		}
		else if (enemy->state == ENEMY_STATE_ZOMBIE)
		{
			if (++enemy->ch_0.counter >= ENEMY_FLY_FLAP_TRESHOLD)
			{
				enemy->ch_0.counter = 0;
				if (++enemy->ch_0.frame > 1)
				{
					enemy->ch_0.frame = 0;
				}
			}

			if (move_character(&enemy->ch_0))
			{
				enemy->ch_0.obj.active = 0;
				enemy->state_counter = 0;
				enemy->state = ENEMY_STATE_REMOVE;
			}
		}
		else if (enemy->state == ENEMY_STATE_RISE)
		{
			if (++enemy->ch.counter == enemy->ch.anim->treshold)
			{
				enemy->ch.counter = 0;
				if (++enemy->ch.frame == enemy->ch.anim->max_rise_frames)
				{
					if (enemy->ch.dir == DIR_LEFT)
					{
						enemy->ch.base_frame = enemy->ch.anim->frame_walk_left;
					}
					else if (enemy->ch.dir == DIR_RIGHT)
					{
						enemy->ch.base_frame = enemy->ch.anim->frame_walk_right;
					}
					enemy->ch.frame = 0;
					enemy->state_counter = 0;
					enemy->state = ENEMY_STATE_WALK;
				}
			}
		}
		else if (enemy->state == ENEMY_STATE_STOP)
		{
			if (++enemy->state_counter >= enemy->race->bounce_treshold)
			{
				if (enemy->ch.obj.x < target_x)
				{
					set_dir_enemy(enemy, DIR_RIGHT);
				}
				else if (enemy->ch.obj.x > target_x)
				{
					set_dir_enemy(enemy, DIR_LEFT);
				}

				if (enemy->ch.obj.y < target_y)
				{
					enemy->state = ENEMY_STATE_FLAP;
				}
				else
				{
					enemy->state = ENEMY_STATE_MOVE;
				}
				enemy->state_counter = 0;
			}
		}
		else if (enemy->state == ENEMY_STATE_REMOVE)
		{
			rem_enemy = enemy;
		}
		enemy = (struct enemy *) enemy->ch.obj.next;

		if (rem_enemy != 0)
		{
			rem_enemy->state_counter = 0;
			rem_enemy->state = ENEMY_STATE_REMOVED;
			deinit_enemy(rem_enemy);
			rem_enemy = 0;
		}
	}
}

unsigned int hit_enemy_equal(
	struct enemy *enemy,
	unsigned int dir,
	signed int dx
	)
{
	unsigned int result;

	if (enemy->race->type == ENEMY_TYPE_PTERY)
	{
		if (dir != enemy->ch.dir && enemy->ch.frame == PTERY_ATTACK_FRAME)
		{
			enemy->state_counter = 0;
			enemy->state = ENEMY_STATE_COLLECT;
			enemy->ch.frame = NUMBER_1000;
			result = 0;
		}
		else
		{
			result = 1;
		}
	}
	else
	{
		if (dir != enemy->ch.dir)
		{
			enemy->ch.dx = -enemy->ch.dx;
			result = 0;
		}
		else
		{
			if (abs(dx) > abs(enemy->ch.dx))
			{
				enemy->state_counter = 0;
				enemy->state = ENEMY_STATE_REMOVE;
				result = 0;
			}
			else
			{
				result = 1;
			}
		}
	}

	return result;
}

unsigned int hit_enemy_over(
	struct enemy *enemy
	)
{
	unsigned int result;

	if (enemy->race->type == ENEMY_TYPE_PTERY)
	{
		result = 1;
	}
	else
	{
		enemy->ch_0.obj.y = enemy->ch.obj.y;
		enemy->ch.dy = -1;
		enemy->state_counter = 0;
		enemy->state = ENEMY_STATE_EGG_DROP;
		enemy->invisible_counter = 0;
		result = 0;
	}

	return result;
}

unsigned int collect_enemy(
	struct enemy *enemy
	)
{
	unsigned int result = 0;

	if (enemy->invisible_counter >= ENEMY_INVISIBLE_TRESHOLD)
	{
		if (enemy->state == ENEMY_STATE_EGG_DROP)
		{
			enemy->ch.frame = NUMBER_500;
			result = 50;
		}
		else
		{
			enemy->ch.frame = NUMBER_250;
			result = 25;
		}

		if (enemy->state == ENEMY_STATE_CALL_BIRD)
		{
			enemy->state_counter = 0;
			enemy->state = ENEMY_STATE_COLLECT_ZOMBIE;
		}
		else
		{
			enemy->state_counter = 0;
			enemy->state = ENEMY_STATE_COLLECT;
		}
	}

	return result;
}

void draw_enemies(void)
{
	struct enemy *enemy;

	enemy = (struct enemy *) enemy_list;
	while (enemy != 0)
	{
		if (enemy->state >= ENEMY_STATE_MOVE && enemy->state <= ENEMY_STATE_WALK)
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
						
/*						
			draw_synced_list_c(
				enemy->ch.anim->shapes[enemy->ch.base_frame + enemy->ch.frame],
				enemy->ch.obj.y,
				enemy->ch.obj.x,
				OBJECT_MOVE_SCALE,
				enemy->ch.obj.scale
				);
*/			

			if (enemy->race->type < ENEMY_TYPE_PTERY)
			{
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
		}
		else if (enemy->state >= ENEMY_STATE_EGG_DROP && enemy->state <= ENEMY_STATE_EGG_HATCH)
		{
			// ZERO
			dp_VIA_cntl=0xcc;

			signed int y = enemy->ch.obj.y - enemy->ch.obj.h_2;
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

			draw_vlp_1(egg[enemy->ch.frame]);
		}
		else if (enemy->state == ENEMY_STATE_KNIGHT)
		{
			signed int y = enemy->ch.obj.y - enemy->ch.obj.h_2;;
			signed int x = enemy->ch.obj.x;			

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
			draw_vlp_2(knight[2]);
		}
		else if (enemy->state == ENEMY_STATE_CALL_BIRD)
		{
			signed int y = enemy->ch.obj.y - enemy->ch.obj.h_2;;
			signed int x = enemy->ch.obj.x;			

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
			draw_vlp_2(knight[2]);

			if (enemy->ch_0.obj.active)
			{
				// ZERO
				dp_VIA_cntl=0xcc;

				y = enemy->ch_0.obj.y;
				x = enemy->ch_0.obj.x;			
			
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

				draw_vlp_1(enemy->ch_0.anim->shapes[enemy->ch_0.base_frame + enemy->ch_0.frame]);
			}
		}
		else if (enemy->state >= ENEMY_STATE_COLLECT && enemy->state <= ENEMY_STATE_ZOMBIE)
		{
			signed int y;
			signed int x;

			if (enemy->state < ENEMY_STATE_ZOMBIE)
			{
				// ZERO
				dp_VIA_cntl=0xcc;

				y = enemy->ch.obj.y - enemy->ch.obj.h_2;
				int x = enemy->ch.obj.x;			
			
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

				draw_vlp_1(number[enemy->ch.frame]);
			}

			if (enemy->ch_0.obj.active)
			{
				// ZERO
				dp_VIA_cntl=0xcc;

				y = enemy->ch_0.obj.y;
				x = enemy->ch_0.obj.x;			
			
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

				draw_vlp_1(enemy->ch_0.anim->shapes[enemy->ch_0.base_frame + enemy->ch_0.frame]);
			}
		}
		else if (enemy->state == ENEMY_STATE_RISE)
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

			if (enemy->race->type < ENEMY_TYPE_PTERY)
			{
				unsigned int base_frame = 0;

				if (enemy->ch.dir == DIR_LEFT)
				{
					base_frame = KNIGHT_RISE_LEFT_START;
				}
				else if (enemy->ch.dir == DIR_RIGHT)
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
				draw_vlp_2(knight[base_frame + enemy->ch.frame]);						
			}			
		}

		enemy = (struct enemy *) enemy->ch.obj.next;
	}
}

// ***************************************************************************
// end of file
// ***************************************************************************
