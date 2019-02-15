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
	signed int move_speed,
	const struct character_anim *anim,
	struct object **head
	)
{
	init_object(&ch->obj, y, x, anim->h, anim->w, anim->scale, anim->shapes[0], head);

	ch->dir 			= DIR_LEFT;
	ch->move_speed	= move_speed;

	ch->dy = 0;
	ch->dx = 0;

	ch->counter		= 0;
	ch->treshold		= anim->treshold;
	ch->base_frame	= 0;
	ch->frame			= 0;

	ch->anim = anim;
}

void deinit_character(
	struct character *ch,
	struct object **head
	)
{
	deinit_object(&ch->obj, head);
}

unsigned int animate_character(
	struct character *ch
	)
{
	unsigned int loop = 0;

	if (++ch->counter >= ch->treshold) {
		ch->counter = 0;
		if (ch->dir < DIR_NONE)
		{
			if (++ch->frame >= ch->anim->max_frames)
			{
				ch->frame = 0;
				loop = 1;
			}
		}
	}

	return loop;
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
		stopped = 2;
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
