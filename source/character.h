#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "object.h"

#define CHARACTER_MIN_X	-120
#define CHARACTER_MAX_X	 120
#define CHARACTER_MIN_Y	-110
#define CHARACTER_MAX_Y	 100

struct character_anim
{
	signed int h;
	signed int w;
	unsigned int treshold;
	unsigned int frame_left;
	unsigned int frame_right;
	unsigned int max_frames;
	unsigned int frame_walk_left;
	unsigned int frame_walk_right;
	unsigned int frame_brake_left;
	unsigned int frame_brake_right;
	const signed char * const *shapes;
};

struct character
{
	struct object obj;
	signed int move_speed;
	unsigned int dir;
	signed int dy, dx;
	unsigned int counter;
	unsigned int treshold;
	unsigned int base_frame;
	unsigned int frame;
	const struct character_anim *anim;
};

void init_character_0(
	struct character *ch,
	signed int y,
	signed int x,
	signed int move_speed,
	const struct character_anim *anim
	);

void init_character(
	struct character *ch,
	signed int y,
	signed int x,
	signed int move_speed,
	const struct character_anim *anim,
	struct object **head
	);

void deinit_character(
	struct character *ch,
	struct object **head
	);

void set_dir_character(
	struct character *ch,
	unsigned int dir
	);

unsigned int animate_character(
	struct character *ch
	);

unsigned int animate_character_limit(
	struct character *ch,
	unsigned int max_frames
	);

unsigned int move_character(
	struct character *ch
	);

#endif
