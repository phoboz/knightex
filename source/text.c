// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "text.h"

// ---------------------------------------------------------------------------

static const unsigned long text_muls2[] = { 10, 1 };
static const unsigned long text_muls5[] = { 10000, 1000, 100, 10, 1 };
static char text_buffer[7];

static void itoa02(
	unsigned long number,
	char* text
	)
{
	unsigned int i, d;

	if (number > 99)
	{
		number = 99;
	}

	for (i = 0; i < 2; i++)
	{
		d = 0;
		while (number >= text_muls2[i])
		{
			d++;
			number -= text_muls2[i];
		}

		text[i] = d + '0';
	}
	text[2] = 0x80;
}

static void itoa050(
	unsigned long number,
	char* text
	)
{
	unsigned int i, d;

	for (i = 0; i < 5; i++)
	{
		d = 0;
		while (number >= text_muls5[i])
		{
			d++;
			number -= text_muls5[i];
		}

		text[i] = d + '0';
	}
	text[5] = '0';
	text[6] = 0x80;
}

void reset_text(void)
{
	Reset0Ref();
	Vec_Text_Height = TEXT_HEIGHT;
	Vec_Text_Width = TEXT_WIDTH;
}

void print_2digit_number(
	signed int y,
	signed int x,
	unsigned long number
	)
{
	itoa02(number, text_buffer);
	Print_Str_d(y, x, text_buffer);
}

void print_points_x10(
	signed int y,
	signed int x,
	unsigned long number
	)
{
	itoa050(number, text_buffer);
	Print_Str_d(y, x, text_buffer);
}

// ***************************************************************************
// end of file
// ***************************************************************************
