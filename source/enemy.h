#ifndef _ENEMY_H
#define _ENEMY_H

#include "character.h"

#define ENEMY_DRAW_SCALE	1

#define ENEMY_TYPE_JOUSTER	0

#define ENEMY_STATE_SPAWN	0
#define ENEMY_STATE_STOP	1
#define ENEMY_STATE_MOVE	2
#define ENEMY_STATE_EGG	4
#define ENEMY_STATE_KNIGHT	5
#define ENEMY_STATE_REMOVE	6

#define ENEMY_RACE_OSTRICH		0

#define ENEMY_SPAWN_TRESHOLD		16
#define ENEMY_SPAWN_ANIM_TRESHOLD	1
#define ENEMY_SPAWN_ANIM_FRAMES		8
#define ENEMY_EGG_TRESHOLD			255
#define ENEMY_STOP_TRESHOLD			3

struct enemy_race
{
	unsigned int type;
	signed int speed;
	const struct character_anim *anim;
};

struct enemy
{
	struct character ch;
	const struct enemy_race *race;
	unsigned int state;
	unsigned int spawn_counter;
	unsigned int state_counter;
};

extern const struct enemy_race enemy_races[];
extern unsigned int enemy_status;
extern struct object *enemy_list;
extern struct object *enemy_free_list;

void init_enemy(
	struct enemy *enemy,
	signed int y,
	signed int x,
	unsigned int dir,
	const struct enemy_race *race
	);

void deinit_enemy(
	struct enemy *enemy
	);

void move_enemies(void);

unsigned int hit_enemy(
	struct enemy *enemy
	);

void draw_enemies(void);

#endif
