#ifndef _PLATFORMS_H
#define _PLATFORMS_H

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
