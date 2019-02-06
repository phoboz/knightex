// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "rasterDraw.h"
#include "platform.h"

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

const struct platform platforms[]=
{
	{	64,	-120,	platform01_data	},
	{	52,	-40,		platform02_data	},
	{	64,	84,		platform03_data	},
	{	0,	-120,	platform04_data	},
	{	-28,	-26,		platform05_data	},
	{	4,	48,		platform06_data	},
	{	0,	90,		platform07_data	}
};

void draw_platform(
	unsigned int index
	)
{
	Reset0Ref();
	Vec_Text_Height = PLATFORM_HEIGHT;
	Vec_Text_Width = PLATFORM_WIDTH;
	Moveto_d(platforms[index].y, platforms[index].x);
	rasterDraw(platforms[index].data);
}

// ***************************************************************************
// end of file
// ***************************************************************************
