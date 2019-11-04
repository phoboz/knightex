// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "rasterDraw.h"
#include "object.h"
#include "platform.h"

struct platform_def
{
	signed int y, x;
	signed int x0, x1;
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
#ifndef PLATFORM_HALF_RES
  0x03, 0x09,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b10000000, // forward
  0b00000000, 0b00110001, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111110, // backward
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11011000, 0b00000000, 0b00000000  // forward
#else
#ifndef PLATFORM_1_4
  0x03, 0x05,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b10000000, // forward
  0b00000000, 0b00001111, 0b11111111, 0b11111111, 0b11111110, // backward
  0b00100011, 0b00011101, 0b11111110, 0b10000000, 0b00000000  // forward
#else
  0x03, 0x03,
  0b11111111, 0b11111111, 0b10000000, // forward
  0b00000000, 0b00111111, 0b11111110, // backward
  0b11111111, 0b11111000, 0b00000000  // forward
#endif
#endif
};

static const unsigned int platform02_data[] =
{
#ifndef PLATFORM_HALF_RES
  0x03, 0x16,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111100, // forward
  0b00000000, 0b00111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111110, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111000, 0b00000000, // backward
  0b00000000, 0b00000000, 0b10000000, 0b01110110, 0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111011, 0b01101111, 0b11111110, 0b11100000, 0b00000011, 0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000  // forward
#else
#ifndef PLATFORM_1_4
  0x03, 0x0B,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111110, // forward
  0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b00000000, 0b00000000, 0b00111111, 0b11111111, 0b11000000, // backward
  0b00000000, 0b10000110, 0b01111111, 0b11111111, 0b11111111, 0b11111110, 0b11111111, 0b11000001, 0b11100000, 0b00000000, 0b00000000  // forward
#else
  0x03, 0x06,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11110000, // forward
  0b00000011, 0b11111111, 0b11111111, 0b11110000, 0b00000111, 0b11111000, // backward
  0b00000011, 0b11111111, 0b11111111, 0b11111000, 0b11000000, 0b00000000  // forward
#endif
#endif
};

static const unsigned int platform03_data[] =
{
#ifndef PLATFORM_HALF_RES
  0x03, 0x0C,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11110000, // forward
  0b00001111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11110000, 0b00000000, // backward
  0b00000000, 0b00000000, 0b11111100, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01111111, 0b01111111, 0b10000000, 0b11111111, 0b11110000  // forward
#else
#ifndef PLATFORM_1_4
  0x03, 0x06,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111100, // forward
  0b00111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000, // backward
  0b00000000, 0b11100000, 0b00000000, 0b00000010, 0b01110000, 0b11100000  // forward
#else
  0x03, 0x03,
  0b11111111, 0b11111111, 0b11111110, // forward
  0b01111111, 0b11111111, 0b11111000, // backward
  0b00001100, 0b00001111, 0b11111110  // forward
#endif
#endif
};

static const unsigned int platform04_data[] =
{
#ifndef PLATFORM_HALF_RES
  0x03, 0x10,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11110000, // forward
  0b00000000, 0b00001111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111000, 0b00000000, 0b00000000, 0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111110, // backward
  0b00000000, 0b00000000, 0b00000000, 0b00011111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111110, 0b00000000, 0b00000000  // forward
#else
#ifndef PLATFORM_1_4
  0x03, 0x08,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111100, // forward
  0b00000011, 0b11111111, 0b11111111, 0b11111111, 0b11100000, 0b00000001, 0b11111111, 0b11111110, // backward
  0b00000000, 0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b00000000  // forward
#else
  0x03, 0x04,
  0b11111111, 0b11111111, 0b11111111, 0b11111110, // forward
  0b00011111, 0b11111111, 0b10000001, 0b11111110, // backward
  0b00000001, 0b11111111, 0b11111111, 0b11110000  // forward
#endif
#endif
};

static const unsigned int platform05_data[] =
{
#ifndef PLATFORM_HALF_RES
  0x03, 0x12,
  0b00011111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111001, 0b00000000, // forward
  0b00000000, 0b00011111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11010000, // backward
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b10000000, 0b00000000, 0b00110001, 0b10000000, 0b00000000, 0b00000000, 0b00000000 // forward
#else
#ifndef PLATFORM_1_4
  0x03, 0x09,
  0b00111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000, // forward
  0b00000011, 0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11100000, // backward
  0b00000000, 0b00000000, 0b01010111, 0b11111111, 0b11111111, 0b11110000, 0b00000000, 0b00000000, 0b00000000  // forward
#else
  0x03, 0x05,
  0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000, // forward
  0b00000011, 0b11111111, 0b11111111, 0b11111111, 0b11111100, // backward
  0b00000000, 0b01111111, 0b11111100, 0b00000000, 0b00000000  // forward
#endif
#endif
};

static const unsigned int platform06_data[] =
{
#ifndef PLATFORM_HALF_RES
  0x03, 0x0F,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11110000, // forward
  0b00001101, 0b10111111, 0b11111111, 0b11111111, 0b11110000, 0b00000000, 0b00000000, 0b00000000, 0b00001111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11011100, // backward
  0b00000001, 0b00010010, 0b00000000, 0b00000011, 0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b01000000, 0b00000000 // forward
#else
#ifndef PLATFORM_1_4
  0x03, 0x08,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000, // forward
  0b00000010, 0b11111111, 0b11111100, 0b00000000, 0b00000011, 0b11111111, 0b11111111, 0b11111110, // backward
  0b00010100, 0b00000011, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111000, 0b00000000  // forward
#else
  0x03, 0x04,
  0b11111111, 0b11111111, 0b11111111, 0b11111000, // forward
  0b00001111, 0b11100000, 0b00011111, 0b11111110, // backward
  0b00000000, 0b01111111, 0b11111111, 0b10000000  // forward
#endif
#endif
};

static const unsigned int platform07_data[] =
{
#ifndef PLATFORM_HALF_RES
  0x03, 0x0C,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11100000, // forward
  0b00000111, 0b11111111, 0b11111111, 0b00111111, 0b11111111, 0b11111111, 0b11111111, 0b01101111, 0b11111111, 0b11111111, 0b11111111, 0b11110000, // backward
  0b00000000, 0b00111111, 0b10000000, 0b00000000, 0b10011111, 0b00000010, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000  // forward
#else
#ifndef PLATFORM_1_4
  0x03, 0x06,
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111100, // forward
  0b00111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111100, // backward
  0b00000111, 0b11111111, 0b11110101, 0b00000000, 0b00000000, 0b00000000  // forward
#else
  0x03, 0x03,
  0b11111111, 0b11111111, 0b11111110, // forward
  0b01111111, 0b11111111, 0b11111110, // backward
  0b00111111, 0b11000000, 0b00000000  // forward
#endif
#endif
};

static const struct platform_def platform_defs[]=
{
	// format
	//	y,	x,		x0,		x1,				data
	{	64,	-127,	-127,	-127+0x09*3+9,	platform01_data	},
	{	52,	-40,		-40+6,	-40+0x16*3+14,	platform02_data	},
	{	64,	84,		84+6,	84+0x0c*3,		platform03_data	},
	{	0,	-127,	-127,	-127+0x10*3+9,	platform04_data	},
	{	-28,	-26,		-26+6,	-26+0x12*3+9,		platform05_data	},
	{	4,	42,		42+6,	42+0x0f*3+9,		platform06_data	},
	{	0,	90,		90+6,	90+0x0c*3,		platform07_data	}
};

static const struct platform_pad platform_pads[MAX_PLATFORM_PADS] =
{
	/*	y,	x,		dir			*/
	{	57,	-7,		DIR_RIGHT		},
	{	5,	-100,	DIR_RIGHT		},
	{	9,	76,		DIR_LEFT		},
	{	-75,	-9,		DIR_RIGHT		}
};

static const struct egg_location egg_locations[MAX_EGG_LOCATIONS] =
{
	/*	y,	x		dir				index */
	{	69,	-102,	DIR_RIGHT		},	// 1
	{	57,	-20,		DIR_RIGHT		},	// 2
	{	69,	100,		DIR_LEFT		},	// 3
	{	5,	-78,		DIR_RIGHT		},	// 4
	{	-23,	-9,		DIR_RIGHT		},	// 5
	{	-23,	28,		DIR_LEFT		},	// 6
	{	9,	60,		DIR_LEFT		},	// 7
	{	5,	112,		DIR_LEFT		},	// 8
	{	-75,	-80,		DIR_RIGHT		},	// 9
	{	-75,	-52,		DIR_RIGHT		},	// 10
	{	-75,	52,		DIR_LEFT		},	// 11
	{	-75,	80,		DIR_LEFT		}	// 12
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

static signed int platform_target_ground_length;
static signed int platform_ground_length;
static unsigned int platform_counter;

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

void restore_platforms(void)
{
	unsigned int i;

	for (i = 0; i < MAX_PLATFORMS; i++)
	{
		enable_platform((signed int) i);
	}
}

void init_platforms(void)
{
	platform_target_ground_length = PLATFORM_GROUND_LENGTH_MAX;
	platform_ground_length = PLATFORM_GROUND_LENGTH_MAX;
	platform_counter = 0;

	restore_platforms();
}

void set_platform_ground_length(
	signed int length
	)
{
	if (length < PLATFORM_GROUND_LENGTH_MIN)
	{
		length = PLATFORM_GROUND_LENGTH_MIN;
	}
	else if (length > PLATFORM_GROUND_LENGTH_MAX)
	{
		length = PLATFORM_GROUND_LENGTH_MAX;
	}

	platform_target_ground_length = length;
}

void move_platforms(void)
{
	if (++platform_counter >= PLATFORM_ANIM_TRESHOLD)
	{
		platform_counter = 0;

		if (platform_ground_length < platform_target_ground_length)
		{
			if (++platform_ground_length > platform_target_ground_length)
			{
				platform_ground_length = platform_target_ground_length;
			}
		}
		else if (platform_ground_length > platform_target_ground_length)
		{
			if (--platform_ground_length < platform_target_ground_length)
			{
				platform_ground_length = platform_target_ground_length;
			}
		}
	}
}

void draw_platforms(void)
{
	unsigned int i;
	signed int index;

	VIA_t1_cnt_lo = OBJECT_MOVE_SCALE;
	Reset0Ref();
	Moveto_d(PLATFORM_GROUND_Y, -platform_ground_length);
	Draw_Line_d(0, platform_ground_length);
	Moveto_d(-PLATFORM_HEIGHT/4, 0);
	Draw_Line_d(0, -2*PLATFORM_WIDTH0/3);
	Moveto_d(PLATFORM_HEIGHT/4, 2*PLATFORM_WIDTH0/3);
	Draw_Line_d(0, platform_ground_length);

	Reset0Ref();
	Vec_Text_Height = -PLATFORM_HEIGHT;
	Vec_Text_Width = PLATFORM_WIDTH;
	for (i = 0; i < MAX_PLATFORMS; i++)
	{
		index = platform_indices[i];
		if (index >= 0 && index < MAX_PLATFORMS)
		{
			Moveto_d(platform_defs[index].y, platform_defs[index].x);
			rasterDraw(platform_defs[index].data);
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
	signed int y, x, new_dy, index;
	const struct platform_def *def;
	unsigned int result = 0;

	y = obj->y - obj->h_2;
	for (i = 0; i < MAX_PLATFORMS; i++)
	{
		index = platform_indices[i];
		if (index >= 0 && index < MAX_PLATFORMS)
		{
			def = &platform_defs[index];
			if (y >= def->y && y + *dy <= def->y)
			{
				x = obj->x - obj->w_2 + dx;
				if (x > def->x0 && x < def->x1)
				{
					new_dy = def->y - y;
					result = 1;
					break;
				}

				x = obj->x + obj->w_2 + dx;
				if (x > def->x0 && x < def->x1)
				{
					new_dy = def->y - y;
					result = 1;
					break;
				}
			}
		}
	}

	if (result)
	{
		*dy = new_dy;
	}
	else if (y >= PLATFORM_GROUND_Y && y + *dy <= PLATFORM_GROUND_Y)
	{
		x = obj->x + dx;
		if (x >= -platform_ground_length && x <= platform_ground_length)
		{
			*dy = PLATFORM_GROUND_Y - y;
			result = 1;
		}
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
			platform_y1 = def->y - PLATFORM_HEIGHT/2;
			platform_x1 = def->x0;
			platform_y2 = def->y;
			platform_x2 = def->x1;
			if (obj_y1 < platform_y2 && obj_y2 > platform_y1 &&
				obj_x1 < platform_x2 && obj_x2 > platform_x1)
			{
				if (obj->y + obj->h_2 <= platform_y1)
				{
					new_dx = *dx;
				}
				else
				{
					new_dx = -*dx;
				}

				if (*dy < 0)
				{
					new_dy = *dy;
				}

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

const struct platform_pad* get_platform_pad(
	unsigned int index
	)
{
	const struct platform_pad *pad;

	if (index < MAX_PLATFORM_PADS)
	{
		pad = &platform_pads[index];
	}
	else
	{
		pad = 0;
	}

	return pad;
}

const struct egg_location* get_egg_location(
	unsigned int index
	)
{
	const struct egg_location *loc;

	if (index < MAX_EGG_LOCATIONS)
	{
		loc = &egg_locations[index];
	}
	else
	{
		loc = 0;
	}

	return loc;
}

// ***************************************************************************
// end of file
// ***************************************************************************
