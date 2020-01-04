#ifndef _ENEMY_H
#define _ENEMY_H

#include "character.h"

#define ENEMY_DRAW_SCALE	1

#define ENEMY_TYPE_BOUNCER		1
#define ENEMY_TYPE_HUNTER		2
#define ENEMY_TYPE_LORD		3
#define ENEMY_TYPE_PTERY		10

#define ENEMY_STATE_STOP		0
#define ENEMY_STATE_MOVE		1
#define ENEMY_STATE_FLAP		2
#define ENEMY_STATE_BOUNCE		3
#define ENEMY_STATE_WALK		4
#define ENEMY_STATE_INACTIVE	10

#define ENEMY_STATE_RISE		11

#define ENEMY_STATE_COL_START	20
#define ENEMY_STATE_EGG_DROP	21
#define ENEMY_STATE_EGG		22
#define ENEMY_STATE_EGG_HATCH	23
#define ENEMY_STATE_KNIGHT		30
#define ENEMY_STATE_CALL_BIRD	35
#define ENEMY_STATE_COL_END		40

#define ENEMY_STATE_ZOMBIE		41

#define ENEMY_STATE_COLLECT		50

#define ENEMY_STATE_REMOVE		60
#define ENEMY_STATE_REMOVED		61

#define ENEMY_SPAWN_TRESHOLD		16
#define ENEMY_SPAWN_ANIM_TRESHOLD	1
#define ENEMY_SPAWN_ANIM_FRAMES		8
#define ENEMY_EGG_TRESHOLD			200
#define ENEMY_EGG_HATCH_TRESHOLD	50
#define ENEMY_KNIGHT_TRESHOLD		100
#define ENEMY_INVISIBLE_TRESHOLD	16
#define ENEMY_FLY_FLAP_TRESHOLD		4
#define ENEMY_COLLECT_TRESHOLD		100
#define ENEMY_LORD_MIN_Y			20

#define ENEMY_MAX_BOUNCES			4
#define ENEMY_TIME_WINDOW			200

#define ENEMY_CALL_BIRD_DY			18

#define ENEMY_RACE_BOUNCER			0
#define ENEMY_RACE_HUNTER			1
#define ENEMY_RACE_LORD			2
#define ENEMY_RACE_PTERY			3

struct enemy_race
{
	unsigned int type;
	signed int speed;
	unsigned int speed_treshold;
	unsigned int flap_treshold;
	unsigned int gravity_treshold;
	unsigned int rise_treshold;
	unsigned int reaction_treshold;
	unsigned int bounce_treshold;
	unsigned int attack_treshold;
	unsigned int retreat_treshold;
	const struct character_anim *anim;
};

struct enemy
{
	struct character ch;
	struct character ch_0;
	const struct enemy_race *race;
	unsigned int state;
	signed int target_speed;
	unsigned int speed_counter;
	unsigned int gravity_counter;
	unsigned int rise_counter;
	unsigned int invisible_counter;
	unsigned int attack_counter;
	unsigned int window_counter;
	unsigned int number_counter;
	unsigned int state_counter;
};

extern signed int target_y, target_x;
extern const struct enemy_race enemy_races[];
extern unsigned int enemy_status;
extern struct object *enemy_list;
extern struct object *enemy_free_list;

void init_enemy(
	struct enemy *enemy,
	signed int y,
	signed int x,
	unsigned int dir,
	unsigned int state,
	const struct enemy_race *race
	);

unsigned int init_enemy_at_pad(
	struct enemy *enemy,
	unsigned int pad_index,
	const struct enemy_race *race
	);

void init_enemy_in_sky(
	struct enemy *enemy,
	unsigned int dir,
	signed int y,
	const struct enemy_race *race
	);

unsigned int init_egg_at_location(
	struct enemy *enemy,
	unsigned int loc_index,
	const struct enemy_race *race
	);

void deinit_enemy(
	struct enemy *enemy
	);

void move_enemies(void);

unsigned int hit_enemy_equal(
	struct enemy *enemy,
	unsigned int dir,
	signed int dx
	);

unsigned int hit_enemy_over(
	struct enemy *enemy
	);

unsigned int collect_enemy(
	struct enemy *enemy
	);

void draw_enemies(void);

#endif
