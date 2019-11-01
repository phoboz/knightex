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
#include "flap_snd.h"
#include "walk_snd.h"
#include "brake_snd.h"

#define MAX_ENEMIES	12

struct player player_1;
unsigned int player_1_status;
struct enemy enemies[MAX_ENEMIES];

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

	init_player(&player_1);

//disable_platform(0);
//disable_platform(2);

	// 3 bouncers
	init_enemy_at_pad(&enemies[0], 0, &enemy_races[0]);
	init_enemy_at_pad(&enemies[1], 1, &enemy_races[0]);
	init_enemy_at_pad(&enemies[2], 2, &enemy_races[0]);

	// 1 ptery
	init_enemy(&enemies[3], 48, -48, DIR_RIGHT, ENEMY_STATE_SPAWN, &enemy_races[1]);

	while(1)
	{
		check_joysticks();
		check_buttons();

		player_1_status = move_player(&player_1);
		move_enemies();
		interaction_enemies_player(&player_1);

		if (!sfx_status_1)
		{
			if ((player_1_status & PLAYER_STATUS_FLAP) == PLAYER_STATUS_FLAP)
			{
				sfx_pointer_1 = (long unsigned int) (&flap_snd_data);
				sfx_status_1 = 1;
			}
			if ((player_1_status & PLAYER_STATUS_WALK) == PLAYER_STATUS_WALK)
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

		Wait_Recal();

		Intensity_7F();
		draw_platforms();

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
