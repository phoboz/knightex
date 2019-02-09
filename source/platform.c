// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include <macro.h>
#include "rasterDraw.h"
#include "object.h"
#include "platform.h"

struct platform_def
{
	signed int y, x;
	signed int w;
	const unsigned int * const data;
};

// ---------------------------------------------------------------------------
// format:
// height, width
// shiftreg, ...,  shiftreg
// ....
// shiftreg, ...,  shiftreg
// 
// every second row is a 'backward' row
// backward rows have the direction AND the bits reversed!
static const unsigned int platform01_data[] =
{
  0x04, 0x09,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b10000000, // forward
  0b00000000, 0b00001111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, // backward
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11110000, 0b00000000, 0b00000000, // forward
  0b00000000, 0b00000000, 0b00000000, 0b00011111, 0b11111111, 0b10000000, 0b11100000, 0b00000000, 0b00000000  // backward
};

static const unsigned int platform02_data[] =
{
  0x04, 0x16,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111100, // forward
  0b00000000, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111110, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000, // backward
  0b00000000, 0b00011111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111100, 0b00000000, 0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111100, 0b00000000, // forward
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00011111, 0b00000000, 0b00000000, 0b00000111, 0b10000000, 0b00011111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11100000, 0b01111100, 0b00000000, 0b00000000, 0b00000000  // backward
};

static const unsigned int platform03_data[] =
{
  0x04, 0x0C,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11110000, // forward
  0b00001111, 0b11111111, 0b10011111, 0b11111111, 0b11111111, 0b11110001, 0b11111111, 0b11111111, 0b11111111, 0b11110001, 0b10110000, 0b00000000, // backward
  0b00000000, 0b00000001, 0b11111111, 0b11111111, 0b11111111, 0b11111011, 0b00000000, 0b11111111, 0b11111111, 0b10010000, 0b11111111, 0b11110000, // forward
  0b00000000, 0b00000011, 0b00000000, 0b11111100, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000  // backward
};

static const unsigned int platform04_data[] =
{
  0x04, 0x10,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11110000, // forward
  0b00000000, 0b00001111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00111111, 0b11111111, 0b11111111, 0b11111111, // backward
  0b00000000, 0b00000000, 0b00000001, 0b11111111, 0b11100000, 0b00000000, 0b00000000, 0b00011111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111100, 0b00000000, 0b00000000, // forward
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111110, 0b00000000, 0b00000000, 0b00000000, 0b00000000  // backward
};

static const unsigned int platform05_data[] =
{
  0x04, 0x12,
  0b00001111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11100000, 0b00000000, // forward
  0b00000000, 0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11110000, // backward
  0b00000000, 0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000, 0b00000000, 0b00000000, 0b00000000, // forward
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11100000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000  // backward
};

static const unsigned int platform06_data[] =
{
  0x04, 0x0F, 
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000, // forward
  0b00000000, 0b00001111, 0b11111111, 0b11000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111100, // backward
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01111111, 0b11111111, 0b11111110, 0b00000000, 0b00000000, 0b00000011, 0b11111111, 0b11111111, 0b11111000, 0b11000000, 0b00000000, // forward
  0b00000000, 0b00000000, 0b00000000, 0b00001111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000  // backward
};

static const unsigned int platform07_data[] =
{
  0x04, 0x0C,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11100000, // forward
  0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111011, 0b11111111, 0b11111111, 0b11111111, 0b10111111, 0b11111111, 0b11111111, 0b11110000, // backward
  0b00000000, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b00111111, 0b11111101, 0b11111110, 0b00000000, 0b00001110, 0b00000000, // forward
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11110000, 0b00000000, 0b00000000, 0b11111100, 0b00000000  // backward
};

static const struct platform_def platform_defs[]=
{
	// format
	//	y,	x,		w,		data
	{	64,	-120,	0x09*3+9,	platform01_data	},
	{	52,	-40,		0x16*3+9,	platform02_data	},
	{	64,	84,		0x0c*3,	platform03_data	},
	{	0,	-120,	0x10*3+9,	platform04_data	},
	{	-28,	-26,		0x12*3+9,	platform05_data	},
	{	4,	48,		0x0f*3+6,	platform06_data	},
	{	0,	90,		0x0c*3,	platform07_data	}
};

static signed int platform_indices[MAX_PLATFORMS] =
{
	0,
	1,
	2,
	3,
	4,
	5,
	6
};

void enable_platform(
	signed int index
	)
{
	platform_indices[index] = index;
}

void disable_platform(
	signed int index
	)
{
	platform_indices[index] = -1;
}

__INLINE void draw_platform(
	signed int index
	)
{
	Reset0Ref();
	Vec_Text_Height	= -PLATFORM_HEIGHT;
	Vec_Text_Width	=  PLATFORM_WIDTH;
	Moveto_d(platform_defs[index].y, platform_defs[index].x);
	rasterDraw(platform_defs[index].data);
}

void draw_platforms(void)
{
	unsigned int i;
	signed int index;

	for (i = 0; i < MAX_PLATFORMS; i++)
	{
		index = platform_indices[i];
		if (index >= 0 && index < MAX_PLATFORMS)
		{
			draw_platform(index);
		}
	}
}

unsigned int hit_over_platform(
	struct object *obj,
	signed int *dy,
	signed int dx
	)
{
	unsigned int i;
	signed int y, x, new_dy, min_dy, index;
	const struct platform_def *def;
	unsigned int result = 0;

	y = obj->y - obj->h_2;
	x = obj->x + dx;
	min_dy = *dy;
	for (i = 0; i < MAX_PLATFORMS; i++)
	{
		index = platform_indices[i];
		if (index >= 0 && index < MAX_PLATFORMS)
		{
			def = &platform_defs[index];
			if (y >= def->y && y + *dy <= def->y &&
				x > def->x && x < def->x + def->w)
			{
				new_dy = def->y - y;
				if (new_dy > min_dy)
				{
					min_dy = new_dy;
				}
				result = 1;
			}
		}
	}

	if (result)
	{
		*dy = min_dy;
	}

	return result;
}

unsigned int hit_platform(
	struct object *obj,
	signed int *dy,
	signed int *dx
	)
{
	unsigned int i;
	signed int index;
	signed int obj_y1, obj_x1, obj_y2, obj_x2;
	signed int platform_y1, platform_x1, platform_y2, platform_x2;
	const struct platform_def *def;
	signed int new_dy = 0;
	signed int new_dx = 0;
	unsigned int result = 0;

	obj_y1 = obj->y - obj->h_2;
	obj_x1 = obj->x - obj->w_2;
	obj_y2 = obj->y + obj->h_2;
	obj_x2 = obj->x + obj->w_2;

	obj_y1 += *dy;
	obj_x1 += *dx;
	obj_y2 += *dy;
	obj_x2 += *dx;

	for (i = 0; i < MAX_PLATFORMS; i++)
	{
		index = platform_indices[i];
		if (index >= 0 && index < MAX_PLATFORMS)
		{
			def = &platform_defs[index];
			platform_y1 = def->y - PLATFORM_HEIGHT;
			platform_x1 = def->x;
			platform_y2 = def->y;
			platform_x2 = def->x + def->w;
			if (obj_y1 < platform_y2 && obj_y2 > platform_y1 &&
				obj_x1 < platform_x2 && obj_x2 > platform_x1)
			{
				new_dx = 0;
				new_dy = 0;

				result = 1;
				break;
			}
		}
	}

	if (result)
	{
		*dy = new_dy;
		*dx = new_dx;
	}

	return result;
}

// ***************************************************************************
// end of file
// ***************************************************************************
