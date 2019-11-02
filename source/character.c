// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "character.h"

// ---------------------------------------------------------------------------

void init_character_0(
	struct character *ch,
	signed int y,
	signed int x,
	signed int move_speed,
	const struct character_anim *anim
	)
{
	init_object_0(&ch->obj, y, x, anim->h, anim->w, anim->shapes[0]);

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

void init_character(
	struct character *ch,
	signed int y,
	signed int x,
	signed int move_speed,
	const struct character_anim *anim,
	struct object **head
	)
{
	init_object(&ch->obj, y, x, anim->h, anim->w, anim->shapes[0], head);

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

void set_dir_character(
	struct character *ch,
	unsigned int dir
	)
{
	ch->dir = dir;

	if (dir == DIR_LEFT)
	{
		ch->base_frame = ch->anim->frame_left;
		ch->dx = -ch->move_speed;
	}
	else if (dir == DIR_RIGHT)
	{
		ch->base_frame = ch->anim->frame_right;
		ch->dx = ch->move_speed;
	}
}

unsigned int animate_character(
	struct character *ch
	)
{
	unsigned int loop = 0;

	if (++ch->counter >= ch->treshold)
	{
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

unsigned int animate_character_limit(
	struct character *ch,
	unsigned int max_frames
	)
{
	unsigned int loop = 0;

	if (++ch->counter >= ch->treshold)
	{
		ch->counter = 0;
		if (ch->dir < DIR_NONE)
		{
			if (++ch->frame >= max_frames)
			{
				ch->frame = 0;
				loop = 1;
			}
		}
	}

	return loop;
}

unsigned int check_move_character(
	struct character *ch
	)
{
	unsigned int stopped = 0;

	signed int y = ch->obj.y + ch->dy;
	signed int x = ch->obj.x + ch->dx;

	if (y <= CHARACTER_MIN_Y)
	{
		y = CHARACTER_MIN_Y;
		stopped = 2;
	}

	if (y >= CHARACTER_MAX_Y)
	{
		y = CHARACTER_MAX_Y;
		stopped = 1;
	}

	if (x <= CHARACTER_MIN_X)
	{
		x = CHARACTER_MAX_X - 1;
		stopped = 3;
	}

	if (x >= CHARACTER_MAX_X)
	{
		x = CHARACTER_MIN_X + 1;
		stopped = 3;
	}

	return stopped;
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
		stopped = 3;
	}

	if (ch->obj.x >= CHARACTER_MAX_X)
	{
		ch->obj.x = CHARACTER_MIN_X + 1;
		stopped = 3;
	}

	return stopped;
}

// ***************************************************************************
// end of file
// ***************************************************************************
