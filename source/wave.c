// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "platform.h"
#include "enemy.h"
#include "wave.h"

#define NUM_ELMTS(item)	(sizeof(item) / sizeof(item[0]))

// ---------------------------------------------------------------------------

static const unsigned int max_waves = 6;

const struct wave_element wave_1[] =
{
	/*	treshold		index					type							race					param	*/
	{	0,			0,						WAVE_ELEMENT_INIT_PLATFORMS,	0,					0		},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		}
};

const struct wave_element wave_2[] =
{
	/*	treshold		index					type							race					param	*/
	{	0,			PLATFORM_GROUND_LENGTH_MIN,	WAVE_ELEMENT_SET_GROUND_LENGTH,	0,					0		},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		}
};

const struct wave_element wave_3[] =
{
	/*	treshold		index					type							race					param	*/
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			DIR_RIGHT,				WAVE_ELEMENT_ENEMY_IN_SKY,		ENEMY_RACE_PTERY,		48		}
};

const struct wave_element wave_4[] =
{
	/*	treshold		index					type							race					param	*/
	{	0,			0,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0		},
	{	0,			1,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0		},
	{	0,			2,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0		},
	{	0,			3,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0		},
	{	0,			4,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0		},
	{	0,			5,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0		},
	{	0,			6,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0		},
	{	0,			7,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0		},
	{	0,			8,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0		},
	{	0,			9,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0		},
	{	0,			10,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0		},
	{	0,			11,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0		}

};

const struct wave_element wave_5[] =
{
	/*	treshold		index					type							race					param	*/
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0		},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0		}
};

const struct wave_element wave_6[] =
{
	/*	treshold		index					type							race					param	*/
	{	0,			1,						WAVE_ELEMENT_ENABLE_PLATFORM,	0,					0		},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0,		}
};

const struct wave_def waves[] =
{
	/*	num_elmts				wave_elmts	*/
	{	NUM_ELMTS(wave_1),		wave_1	},
	{	NUM_ELMTS(wave_2),		wave_2	},
	{	NUM_ELMTS(wave_3),		wave_3	},
	{	NUM_ELMTS(wave_4),		wave_4	},
	{	NUM_ELMTS(wave_5),		wave_5	},
	{	NUM_ELMTS(wave_6),		wave_6	}
};

void init_wave(
	struct wave *wave
	)
{
	wave->wave_index =		0;
	wave->counter =		0;
	wave->element_index =	0;
	wave->new_wave =		0;
}

void close_wave(
	struct wave *wave
	)
{
	struct enemy *enemy;

	enemy = (struct enemy *) enemy_list;
	while (enemy != 0)
	{
		enemy->state = ENEMY_STATE_REMOVE;
		enemy->state_counter = 0;
		enemy = (struct enemy *) enemy->ch.obj.next;
	}

	wave->new_wave = 0;
}
	
unsigned int move_wave(
	struct wave *wave
	)
{
	struct enemy *enemy;
	unsigned int result = 0;

	if (!wave->new_wave)
	{
		if (++wave->counter >= waves[wave->wave_index].elements[wave->element_index].treshold)
		{
			wave->counter = 0;

			if (waves[wave->wave_index].elements[wave->element_index].type == WAVE_ELEMENT_ENEMY_AT_PAD)
			{
				if (enemy_free_list != 0)
				{
					init_enemy_at_pad(
						(struct enemy *) enemy_free_list,
						waves[wave->wave_index].elements[wave->element_index].index,
						&enemy_races[waves[wave->wave_index].elements[wave->element_index].race]
						);
				}
			}
			else if (waves[wave->wave_index].elements[wave->element_index].type == WAVE_ELEMENT_ENEMY_IN_SKY)
			{
				if (enemy_free_list != 0)
				{
					init_enemy_in_sky(
						(struct enemy *) enemy_free_list,
						waves[wave->wave_index].elements[wave->element_index].index,
						waves[wave->wave_index].elements[wave->element_index].param,
						&enemy_races[waves[wave->wave_index].elements[wave->element_index].race]
						);
				}
			}
			else if (waves[wave->wave_index].elements[wave->element_index].type == WAVE_ELEMENT_EGG_AT_LOCATION)
			{
				if (enemy_free_list != 0)
				{
					init_egg_at_location(
						(struct enemy *) enemy_free_list,
						waves[wave->wave_index].elements[wave->element_index].index,
						&enemy_races[waves[wave->wave_index].elements[wave->element_index].race]
						);
				}
			}
			else if (waves[wave->wave_index].elements[wave->element_index].type == WAVE_ELEMENT_INIT_PLATFORMS)
			{
				init_platforms();
			}
			else if (waves[wave->wave_index].elements[wave->element_index].type == WAVE_ELEMENT_DISABLE_PLATFORM)
			{
				disable_platform((signed int) waves[wave->wave_index].elements[wave->element_index].index);
			}
			else if (waves[wave->wave_index].elements[wave->element_index].type == WAVE_ELEMENT_ENABLE_PLATFORM)
			{
				enable_platform((signed int) waves[wave->wave_index].elements[wave->element_index].index);
			}
			else if (waves[wave->wave_index].elements[wave->element_index].type == WAVE_ELEMENT_SET_GROUND_LENGTH)
			{
				set_platform_ground_length((signed int) waves[wave->wave_index].elements[wave->element_index].index);
			}
			if (++wave->element_index >= waves[wave->wave_index].num_elements)
			{
				wave->element_index = 0;
				wave->new_wave = 1;
			}
		}
	}

	if (wave->new_wave)
	{
		result = wave->wave_index + 1;
		enemy = (struct enemy *) enemy_list;
		while (enemy != 0)
		{
			if (enemy->race->type != ENEMY_TYPE_PTERY)
			{
				result = 0;
				break;
			}

			enemy = (struct enemy *) enemy->ch.obj.next;
		}

		if (result)
		{
			if (++wave->wave_index >= max_waves)
			{
				wave->wave_index = 0;
				result = 255;
			}
		}
	}

	return result;
}

// ***************************************************************************
// end of file
// ***************************************************************************
