// ***************************************************************************
// main
// ***************************************************************************
// This file was developed by Prof. Dr. Peer Johannsen as part of the 
// "Retro-Programming" and "Advanced C Programming" class at
// Pforzheim University, Germany.
// 
// It can freely be used, but at one's own risk and for non-commercial
// purposes only. Please respect the copyright and credit the origin of
// this file.
//
// Feedback, suggestions and bug-reports are welcome and can be sent to:
// peer.johannsen@pforzheim-university.de
// ---------------------------------------------------------------------------

#include <vectrex.h>
#include "controller.h"
#include "ayfxPlayer.h"
#include "platform.h"
#include "player.h"
#include "enemy.h"
#include "wave.h"
#include "text.h"
#include "flap_snd.h"
#include "walk_snd.h"
#include "brake_snd.h"
#include "rise_snd.h"
#include "hit1_snd.h"
#include "hit2_snd.h"
#include "bounce_snd.h"
#include "draw_snd.h"
#include "scream_snd.h"

#define MAX_ENEMIES				12
#define SURVIVAL_AWARD_PONTS_X10	300
#define SCORE_FOR_EXTRA_LIFE_X10	2000

#define GAME_STATE_NORMAL			0
#define GAME_STATE_AWARD			1
#define GAME_STATE_NEXT_WAVE		2
#define GAME_STATE_OVER			3

#define PLAYER_1_NO_SURVIVE			0x01

static const char game_over_text[]	= "GAME OVER\x80";

unsigned int game_state = GAME_STATE_NORMAL;
struct player player_1;
unsigned int player_1_status;
unsigned int player_1_wave_flags;
unsigned int player_1_extra_lives = 3;
unsigned long player_1_next_extra_life = SCORE_FOR_EXTRA_LIFE_X10;
unsigned int last_wave_type = WAVE_TYPE_NORMAL;
struct enemy enemies[MAX_ENEMIES];
struct wave wave;
unsigned int new_wave_index = 0;
unsigned int curr_wave_index;

void check_points(void)
{
	if (player_1.points_x10 >= player_1_next_extra_life)
	{
		player_1_extra_lives++;
		player_1_next_extra_life += SCORE_FOR_EXTRA_LIFE_X10;
	}
}

// ---------------------------------------------------------------------------
// cold reset: the vectrex logo is shown, all ram data is cleared
// warm reset: skip vectrex logo and keep ram data
// ---------------------------------------------------------------------------
// at system startup, when powering up the vectrex, a cold reset is performed
// if the reset button is pressed, then a warm reset is performed
// ---------------------------------------------------------------------------
// after each reset, the cartridge title is shown and then main() is called
// ---------------------------------------------------------------------------

int main(void)
{
	unsigned int i;

	enable_controller_1_x();
	enable_controller_1_y();
	disable_controller_2_x();
	disable_controller_2_y();

	for (i = 0; i < MAX_ENEMIES; i++)
	{
		give_object(&enemies[i].ch.obj, &enemy_free_list);
	}

	init_platforms();
	init_player(&player_1);
	player_1.points_x10 = 0;
	init_wave(&wave);

/////////////////////
//wave.wave_index = 3;
////////////////////

	while(1)
	{
			check_joysticks();
			check_buttons();

			move_platforms();

			player_1_status = move_player(&player_1);
			if (player_1.state < PLAYER_STATE_INACTIVE)
			{
				target_y = player_1.ch.obj.y;
				target_x = player_1.ch.obj.x;
			}
			else
			{
				target_y = 40;
				target_x = 0;
			}

			move_enemies();

		if (game_state == GAME_STATE_NORMAL)
		{
			new_wave_index = move_wave(&wave);
			if (new_wave_index)
			{
				curr_wave_index = new_wave_index;
				new_wave_index = 0;
				sfx_status_1 = 0;
				sfx_status_2 = 0;
				Vec_Music_Flag = 1;
				if (last_wave_type == WAVE_TYPE_SURVIVAL &&
				    (player_1_wave_flags & PLAYER_1_NO_SURVIVE) == 0x00)
				{
					player_1.points_x10 += SURVIVAL_AWARD_PONTS_X10;
					check_points();
					game_state = GAME_STATE_AWARD;
				}
				else
				{
					game_state = GAME_STATE_NEXT_WAVE;
				}
			}

			player_1_status |= interaction_enemies_player(&player_1);

			if (player_1_status &
				(PLAYER_STATUS_COLLECT | PLAYER_STATUS_WIN | PLAYER_STATUS_HIT))
			{
				check_points();
			}

			// Higher prio sound that cannot be interrupted
			if ((enemy_status & ENEMY_STATUS_RISE) == ENEMY_STATUS_RISE)
			{
				sfx_pointer_1 = (long unsigned int) (&rise_snd_data);
				sfx_status_1 = 1;
			}
			else if ((enemy_status & ENEMY_STATUS_SCREAM) == ENEMY_STATUS_SCREAM)
			{
				sfx_pointer_1 = (long unsigned int) (&scream_snd_data);
				sfx_status_1 = 1;
			}

			if (!sfx_status_1)
			{
				if ((player_1_status & PLAYER_STATUS_HIT) == PLAYER_STATUS_HIT)
				{
					sfx_pointer_1 = (long unsigned int) (&hit2_snd_data);
					sfx_status_1 = 1;
				}
				else if ((player_1_status & PLAYER_STATUS_WIN) == PLAYER_STATUS_WIN)
				{
					sfx_pointer_1 = (long unsigned int) (&hit1_snd_data);
					sfx_status_1 = 1;
				}
				else if ((player_1_status & PLAYER_STATUS_DRAW) == PLAYER_STATUS_DRAW)
				{
					sfx_pointer_1 = (long unsigned int) (&draw_snd_data);
					sfx_status_1 = 1;
				}
			}

			if (!sfx_status_1)
			{
				if ((player_1_status & PLAYER_STATUS_BOUNCE) == PLAYER_STATUS_BOUNCE)
				{
					sfx_pointer_1 = (long unsigned int) (&bounce_snd_data);
					sfx_status_1 = 1;
				}
				else if ((player_1_status & PLAYER_STATUS_FLAP) == PLAYER_STATUS_FLAP)
				{
					sfx_pointer_1 = (long unsigned int) (&flap_snd_data);
					sfx_status_1 = 1;
				}
				else if ((player_1_status & PLAYER_STATUS_WALK) == PLAYER_STATUS_WALK)
				{
					sfx_pointer_1 = (long unsigned int) (&walk_snd_data);
					sfx_status_1 = 1;
				}
				else if ((player_1_status & PLAYER_STATUS_BRAKE) == PLAYER_STATUS_BRAKE)
				{
					sfx_pointer_1 = (long unsigned int) (&brake_snd_data);
					sfx_status_1 = 1;
				}
			}
		}
		else if (game_state == GAME_STATE_AWARD)
		{
			if (Vec_Music_Flag)
			{
				DP_to_C8();
				Init_Music_chk(&Vec_Music_4);
			}
			else
			{
				sfx_status_1 = 0;
				sfx_status_2 = 0;
				Vec_Music_Flag = 1;
				game_state = GAME_STATE_NEXT_WAVE;
			}
		}
		else if (game_state == GAME_STATE_NEXT_WAVE)
		{
			if (Vec_Music_Flag)
			{
				DP_to_C8();
				if (get_wave_type(&wave) == WAVE_TYPE_SURVIVAL)
				{
					Init_Music_chk(&Vec_Music_5);
				}
				else if (get_wave_type(&wave) == WAVE_TYPE_EGG)
				{
					Init_Music_chk(&Vec_Music_8);
				}
				else if (get_wave_type(&wave) == WAVE_TYPE_PTERY)
				{
					Init_Music_chk(&Vec_Music_2);
				}
				else
				{
					Init_Music_chk(&Vec_Music_9);
				}
			}
			else
			{
				player_1_wave_flags = 0x00;
				player_1.collect_count = 0;
				last_wave_type = close_wave(&wave);
				game_state = GAME_STATE_NORMAL;
			}
		}

		if (player_1.state == PLAYER_STATE_DEAD)
		{
			if (get_wave_type(&wave) == WAVE_TYPE_SURVIVAL)
			{
				player_1_wave_flags |= PLAYER_1_NO_SURVIVE;
			}

			if (player_1_extra_lives)
			{
				init_player(&player_1);
				player_1_extra_lives--;
			}
			else
			{
				game_state = GAME_STATE_OVER;
			}
		}

		Wait_Recal();

		if (Vec_Music_Flag)
		{
			Do_Sound();
		}
		else if (sfx_status_1 == 1 || sfx_status_2 == 1)
		{
			if (sfx_status_1 == 1)
			{
				ayfx_sound1();
			}

			if (sfx_status_2 == 1)
			{
				ayfx_sound2();
			}
			Do_Sound();
		}

		Intensity_5F();
		reset_text();
		print_points_x10(120, -16, player_1.points_x10);

		Intensity_5F();
		if (game_state == GAME_STATE_AWARD)
		{
			draw_award_wave(WAVE_AWARD_TYPE_SURVIVAL);
		}
		else if (game_state == GAME_STATE_NEXT_WAVE)
		{
			announce_wave(&wave);
		}
		else if (game_state == GAME_STATE_OVER)
		{
			reset_text();
			Print_Str_d(32, -24, (char *) game_over_text);
		}

		Moveto_d(PLATFORM_GROUND_Y - 10, -120);
		for (unsigned int i = 0; i < player_1_extra_lives; i++)
		{
			Dot_d(0, 4);
		}

		//Intensity_7F();
		draw_platforms();

		Intensity_7F();
		draw_player(&player_1);
		draw_enemies();
	};
	
	// if return value is <= 0, then a warm reset will be performed,
	// otherwise a cold reset will be performed
	return 0;
}

// ***************************************************************************
// end of file
// ***************************************************************************
