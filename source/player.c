// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "controller.h"
#include "draw.h"
#include "player.h"

extern const signed char* const ostrich[];

// ---------------------------------------------------------------------------

void init_player(
	struct player *player,
	signed int y,
	signed int x,
	unsigned int dir
	)
{
	init_character(
		&player->ch,
		y,
		x,
		PLAYER_HEIGHT,
		PLAYER_WIDTH,
		PLAYER_SCALE,
		PLAYER_SPEED,
		PLAYER_TRESHOLD,
		PLAYER_MAX_FRAMES,
		ostrich,
		0
		);

	player->state			= PLAYER_STATE_NORMAL;
	player->state_counter	= 0;
	player->speed_counter	= 0;

	set_dir_character(&player->ch, dir);
}

unsigned int move_player(
	struct player *player
	)
{
	unsigned int status = 0;

	if (joystick_1_left())
	{
		if (player->ch.dir == DIR_LEFT)
		{
			if (++player->speed_counter >= PLAYER_SPEED_TRESHOLD)
			{
				player->speed_counter = 0;
				if (player->ch.dx > -PLAYER_SPEED)
				{
					player->ch.dx--;
				}
			}
		}
		else
		{
			player->ch.dir = DIR_LEFT;
		}
	}
	else if (joystick_1_right())
	{
		if (player->ch.dir == DIR_RIGHT)
		{
			if (++player->speed_counter >= PLAYER_SPEED_TRESHOLD)
			{
				player->speed_counter = 0;
				if (player->ch.dx < PLAYER_SPEED)
				{
					player->ch.dx++;
				}
			}
		}
		else
		{
			player->ch.dir = DIR_RIGHT;
		}
	}

	if (player->ch.dx < 0)
	{
		set_dir_character(&player->ch, DIR_LEFT);
	}
	else if (player->ch.dx > 0)
	{
		set_dir_character(&player->ch, DIR_RIGHT);
	}
	else if (player->ch.dx == 0)
	{
		set_dir_character(&player->ch, player->ch.dir);
	}

	switch (player->state)
	{
		case PLAYER_STATE_NORMAL:
			if (button_1_4_pressed())
			{
				player->ch.dy = PLAYER_LIFT;
				player->ch.frame = 1;
				player->state = PLAYER_STATE_FLAP;
				status |= PLAYER_STATUS_FLAP;
			}
			else
			{
				if (++player->gravity_counter >= PLAYER_GRAVITY_TRESHOLD)
				{
					player->gravity_counter = 0;
					if (player->ch.dy > -PLAYER_GRAVITY)
					{
						player->ch.dy--;
					}
				}
			}
			break;

		case PLAYER_STATE_FLAP:
			if (++player->state_counter >= PLAYER_FLAP_TRESHOLD)
			{
				player->state_counter = 0;
				player->ch.frame = 0;
				player->state = PLAYER_STATE_NORMAL;
			}
			break;

		default:
			break;
	}

	move_character(&player->ch);

	return status;
}

void draw_player(
	struct player *player
	)
{
	if (player->ch.obj.active)
	{
		if (player->state != PLAYER_STATE_DEAD)
		{
			draw_synced_list_c(
				player->ch.shapes[player->ch.base_frame + player->ch.frame],
				player->ch.obj.y,
				player->ch.obj.x,
				OBJECT_MOVE_SCALE,
				player->ch.obj.scale
				);
		}
	}
}

// ***************************************************************************
// end of file
// ***************************************************************************
