#ifndef _TEXT_H
#define _TEXT_H

#define TEXT_HEIGHT			-2
#define TEXT_WIDTH				32

void reset_text(void);

void print_2digit_number(
	signed int y,
	signed int x,
	unsigned long number
	);

void print_points_x10(
	signed int y,
	signed int x,
	unsigned long number
	);

#endif
