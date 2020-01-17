#ifndef _PLATFORM_H
#define _PLATFORM_H

#define PLATFORM_HALF_RES
#define PLATFORM_1_4

#define MAX_PLATFORMS		7
#define MAX_PLATFORM_PADS	4
#define MAX_EGG_LOCATIONS	31

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

#define PLATFORM_GROUND_Y			-80
#define PLATFORM_GROUND_LENGTH_MAX	127
#define PLATFORM_GROUND_LENGTH_MIN	96

#define PLATFORM_ANIM_TRESHOLD		24

struct object;

struct platform_pad
{
	signed int y;
	signed int x;
	unsigned int dir;
};

struct egg_location
{
	signed int y;
	signed int x;
	unsigned int dir;
};

void enable_platform(
	signed int index
	);

void disable_platform(
	signed int index
	);

void restore_platforms(void);

void init_platforms(void);

void set_platform_ground_length(
	signed int length
	);

void move_platforms(void);

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

const struct platform_pad* get_platform_pad(
	unsigned int index
	);

const struct egg_location* get_egg_location(
	unsigned int index
	);

#endif
