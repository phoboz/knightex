#ifndef _PLATFORM_H
#define _PLATFORM_H

#define MAX_PLATFORMS		7

#define PLATFORM_HEIGHT	 8
#define PLATFORM_WIDTH		24

struct object;

void enable_platform(
	signed int index
	);

void disable_platform(
	signed int index
	);

void draw_platforms(void);

unsigned int hit_over_platform(
	struct object *obj,
	signed int *dy,
	signed int dx
	);

unsigned int hit_platform(
	struct object *obj,
	signed int *dy,
	signed int *dx
	);

#endif
