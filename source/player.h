#ifndef _PLAYER_H
#define _PLAYER_H

#include "character.h"

#define PLAYER_HEIGHT			12
#define PLAYER_WIDTH			6
#define PLAYER_SCALE			0x18/OSTRICH_SCALE
#define PLAYER_SPEED			4
#define PLAYER_TRESHOLD		4
#define PLAYER_GRAVITY			6
#define PLAYER_LIFT			1

#define PLAYER_SPEED_TRESHOLD	6
#define PLAYER_FLAP_TRESHOLD	8
#define PLAYER_GRAVITY_TRESHOLD	8

#define PLAYER_STATE_NORMAL		0
#define PLAYER_STATE_FLAP		1
#define PLAYER_STATE_WALK		2
#define PLAYER_STATE_DEAD		10

#define PLAYER_STATUS_FLAP		0x01
#define PLAYER_STATUS_WALK		0x02
#define PLAYER_STATUS_BRAKE		0x04

struct player
{
	struct character ch;
	unsigned int control_dir;
	unsigned int state;
	unsigned int state_counter;
	unsigned int speed_counter;
	unsigned int gravity_counter;
};

void init_player(
	struct player *player,
	signed int y,
	signed int x,
	unsigned int dir
	);

unsigned int move_player(
	struct player *player
	);

void draw_player(
	struct player *player
	);

struct enemy* interaction_enemies_player(
	struct player *player
	);

#endif
