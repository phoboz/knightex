#ifndef _PLATFORM_H
#define _PLATFORM_H

#define PLATFORM_HEIGHT	-12
#define PLATFORM_WIDTH		24

struct platform
{
	signed int y, x;
	const unsigned int * const data;
};

extern const struct platform platforms[];

void draw_platform(
	unsigned int index
	);

#endif
