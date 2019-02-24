#ifndef _PLATFORM_H
#define _PLATFORM_H

#define PLATFORM_HALF_RES
#define PLATFORM_1_4

#define MAX_PLATFORMS		7

#define PLATFORM_HEIGHT	9
#define PLATFORM_WIDTH0	24

#ifndef PLATFORM_HALF_RES
#define PLATFORM_WIDTH		24
#else
#ifndef PLATFORM_1_4
#define PLATFORM_WIDTH		48
#else
#define PLATFORM_WIDTH		96
#endif
#endif

#define PLATFORM_GROUND_Y		-80

struct object;

extern signed int platform_ground_length;

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
