#ifndef _PLAYER_H
#define _PLAYER_H

#include "character.h"

#define PLAYER_HEIGHT				10
#define PLAYER_WIDTH				4
#define PLAYER_DRAW_SCALE			1
#define PLAYER_SPEED				4
#define PLAYER_TRESHOLD			4
#define PLAYER_GRAVITY				6
#define PLAYER_LIFT				1
#define PLAYER_KNIGHT_FALL_SPEED	2

#define PLAYER_SPEED_TRESHOLD		10
#define PLAYER_FLAP_TRESHOLD		8
#define PLAYER_GRAVITY_TRESHOLD		8
#define PLAYER_ROOF_TRESHOLD		8
#define PLAYER_FLAP_DELAY_TRESHOLD	4
#define PLAYER_DIE_TRESHOLD			64

#define PLAYER_STATE_NORMAL		1
#define PLAYER_STATE_FLAP		2
#define PLAYER_STATE_WALK		3
#define PLAYER_STATE_BRAKE		4
#define PLAYER_STATE_INACTIVE	10
#define PLAYER_STATE_RISE		11
#define PLAYER_STATE_HIT		20
#define PLAYER_STATE_DROWNED	21
#define PLAYER_STATE_DEAD		30

#define PLAYER_INIT_PAD_INDEX	3

#define PLAYER_STATUS_FLAP		0x01
#define PLAYER_STATUS_WALK		0x02
#define PLAYER_STATUS_BRAKE		0x04
#define PLAYER_STATUS_WIN		0x08
#define PLAYER_STATUS_HIT		0x10
#define PLAYER_STATUS_DRAW		0x20
#define PLAYER_STATUS_BOUNCE	0x40
#define PLAYER_STATUS_COLLECT	0x80

struct player
{
	struct character ch;
	struct character ch_0;
	unsigned int control_dir;
	unsigned int state;
	unsigned int state_counter;
	unsigned int speed_counter;
	unsigned int gravity_counter;
	unsigned long points_x10;
	unsigned int hit_roof;
	unsigned int roof_counter;
	unsigned int flap_countdown;
};

unsigned int init_player(
	struct player *player
	);

unsigned int move_player(
	struct player *player
	);

void draw_player(
	struct player *player
	);

unsigned int interaction_enemies_player(
	struct player *player
	);

#endif
