#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "object.h"

#define CHARACTER_MIN_Y	-100
#define CHARACTER_MAX_Y	 100

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
	unsigned int max_frames;
	const signed char* const *shapes;
};


void init_character(
	struct character *ch,
	signed int y,
	signed int x,
	signed int h,
	signed int w,
	unsigned int scale,
	signed int move_speed,
	unsigned int treshold,
	unsigned int max_frames,
	const signed char* const *shapes,
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

void set_animation_character(
	struct character *ch,
	unsigned int base_frame,
	unsigned int max_frames
	);

unsigned int animate_character(
	struct character *ch
	);

unsigned int move_character(
	struct character *ch
	);

unsigned int retreat_character(
	struct character *ch
	);

#endif
