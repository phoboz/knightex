// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "character.h"

// ---------------------------------------------------------------------------

void init_character(
	struct character *ch,
	signed int y,
	signed int x,
	signed int h,
	signed int w,
	unsigned int scale,
	signed int move_speed,
	unsigned int treshold,
	unsigned int max_frames,
	const signed char* const *shapes,
	struct object **head
	)
{
	init_object(&ch->obj, y, x, h, w, scale, shapes[0], head);

	ch->dir 			= DIR_LEFT;
	ch->move_speed	= move_speed;

	ch->dy = 0;
	ch->dx = 0;

	ch->counter		= 0;
	ch->treshold		= treshold;
	ch->base_frame	= 0;
	ch->frame			= 0;
	ch->max_frames	= max_frames;

	ch->shapes = shapes;
}

void deinit_character(
	struct character *ch,
	struct object **head
	)
{
	deinit_object(&ch->obj, head);
}

void set_dir_character(
	struct character *ch,
	unsigned int dir
	)
{
#if 0
	ch->dir = dir;

	switch (dir)
	{
		case DIR_LEFT:
			ch->dy = 0;
			ch->dx = -ch->move_speed;
			break;

		case DIR_RIGHT:
			ch->dy =  0;
			ch->dx =  ch->move_speed;
			break;

		case DIR_NONE:
		default:
			ch->dy =  0;
			ch->dx =  0;
			break;
	}
#endif

	if (dir < DIR_NONE)
	{
		ch->base_frame = dir << 1;
	}
}

void set_animation_character(
	struct character *ch,
	unsigned int base_frame,
	unsigned int max_frames
	)
{
	ch->base_frame = base_frame;
	ch->max_frames = max_frames;
}

unsigned int animate_character(
	struct character *ch
	)
{
	unsigned int changed = 0;

	if (++ch->counter >= ch->treshold) {
		ch->counter = 0;
		if (ch->dir < DIR_NONE)
		{
			if (++ch->frame >= ch->max_frames)
			{
				ch->frame = 0;
			}
		}
		changed = 1;
	}

	return changed;
}

unsigned int move_character(
	struct character *ch
	)
{
	unsigned int stopped = 0;

	ch->obj.y += ch->dy;
	ch->obj.x += ch->dx;

	if (ch->obj.y <= CHARACTER_MIN_Y)
	{
		ch->obj.y = CHARACTER_MIN_Y;
		stopped = 1;
	}

	if (ch->obj.y >= CHARACTER_MAX_Y)
	{
		ch->obj.y = CHARACTER_MAX_Y;
		stopped = 1;
	}

	if (ch->obj.x <= CHARACTER_MIN_X)
	{
		ch->obj.x = CHARACTER_MAX_X - 1;
	}

	if (ch->obj.x >= CHARACTER_MAX_X)
	{
		ch->obj.x = CHARACTER_MIN_X + 1;
	}

	return stopped;
}

// ***************************************************************************
// end of file
// ***************************************************************************
