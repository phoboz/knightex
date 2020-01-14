// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "platform.h"
#include "enemy.h"
#include "text.h"
#include "wave.h"

#define NUM_ELMTS(item)	(sizeof(item) / sizeof(item[0]))

// ---------------------------------------------------------------------------

struct wave_info {
	int dx;
	const char * const text;
};

static const char wave_heading_text[]	= "WAVE \x80";
static const char survival_wave_text[]	= "SURVIVAL WAVE \x80";
static const char egg_wave_text[]		= "EGG WAVE \x80";
static const char gladiator_wave_text[]	= "GLADIATOR WAVE \x80";
static const char ptery_wave_text[]		= "PTERY WAVE \x80";
static const struct wave_info wave_type_info[] =
{
	/*	dx	text					*/
	{	11,	survival_wave_text		},
	{	 1,	egg_wave_text			},
	{	12,	gladiator_wave_text	},
	{	11,	ptery_wave_text		}
};

static const char survival_award_text[] =		"SURVIVAL BONUS \x80";
static const char bonus_1000_text[] =		"1,000 \x80";

static const struct wave_element wave_1[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_INIT_PLATFORMS,	0,					0			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	255,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	255,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			}
};

static const struct wave_element wave_2[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			PLATFORM_GROUND_LENGTH_MIN,	WAVE_ELEMENT_SET_GROUND_LENGTH,	0,					0			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	255,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	255,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	255,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			}
};

static const struct wave_element wave_3[] =
{
	/*	treshold		index					type							race					param		*/
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	255,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	255,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	255,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	255,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	255,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			}
};

static const struct wave_element wave_4[] =
{
	/*	treshold		index					type							race					param		*/
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	255,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	255,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	255,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0			},
	{	255,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0			},
	{	255,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0			}
};

static const struct wave_element wave_5[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	//{	0,			1,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			2,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	//{	0,			3,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			4,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			5,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	//{	0,			6,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	//{	0,			7,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			8,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	//{	0,			9,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	//{	0,			10,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			11,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			}

};

static const struct wave_element wave_6[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	160,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	160,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	160,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	160,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0			},
	{	160,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0			},
	{	160,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0			}
};

static const struct wave_element wave_7[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			2,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	160,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	160,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	160,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	160,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	160,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	160,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			}
};

static const struct wave_element wave_8[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			2,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			DIR_RIGHT,				WAVE_ELEMENT_ENEMY_IN_SKY,		ENEMY_RACE_PTERY,		WAVE_PTERY_Y	},
	{	160,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	160,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	160,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	160,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	160,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	160,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			}
};

static const struct wave_element wave_9[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			2,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			4,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	160,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	160,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	160,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	160,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	160,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	160,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			}
};

static const struct wave_element wave_10[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_RESTORE_PLATFORMS,	0,					0			},
	{	0,			0,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			1,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			2,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			3,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			4,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			5,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			6,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			7,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			8,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			9,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			10,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			},
	{	0,			11,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_BOUNCER	,	0			}
};

static const struct wave_element wave_11[] =
{
	/*	treshold		index					type							race					param		*/
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			}
};

static const struct wave_element wave_12[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			4,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_BOUNCER	,	0			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			}
};

static const struct wave_element wave_13[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			2,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			4,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			DIR_RIGHT,				WAVE_ELEMENT_ENEMY_IN_SKY,		ENEMY_RACE_PTERY,		WAVE_PTERY_Y	},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			}
};

static const struct wave_element wave_14[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			2,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			4,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			}
};

static const struct wave_element wave_15[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_RESTORE_PLATFORMS,	0,					0			},
	{	0,			0,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			1,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			2,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			3,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			4,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			5,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			6,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			7,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			8,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			9,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			10,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			11,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			}
};

static const struct wave_element wave_16[] =
{
	/*	treshold		index					type							race					param		*/
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			}
};

static const struct wave_element wave_17[] =
{
	/*	treshold		index					type							race					param		*/
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			}
};

static const struct wave_element wave_18[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			DIR_RIGHT,				WAVE_ELEMENT_ENEMY_IN_SKY,		ENEMY_RACE_PTERY,		WAVE_PTERY_Y	},
	{	0,			DIR_LEFT,					WAVE_ELEMENT_ENEMY_IN_SKY,		ENEMY_RACE_PTERY,		WAVE_PTERY_Y	},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			}
};

static const struct wave_element wave_19[] =
{
	/*	treshold		index					type							race					param		*/
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			0,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			}
};

static const struct wave_element wave_20[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_RESTORE_PLATFORMS,	0,					0			},
	{	0,			0,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			1,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			2,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			3,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			4,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			5,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			6,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			7,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			8,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			9,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			10,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			11,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			}
};

static const struct wave_element wave_21[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			}
};

static const struct wave_element wave_22[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			}
};

static const struct wave_element wave_23[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			3,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			6,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			DIR_RIGHT,				WAVE_ELEMENT_ENEMY_IN_SKY,		ENEMY_RACE_PTERY,		WAVE_PTERY_Y	},
	{	0,			DIR_LEFT,					WAVE_ELEMENT_ENEMY_IN_SKY,		ENEMY_RACE_PTERY,		WAVE_PTERY_Y	},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			}
};

static const struct wave_element wave_24[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			3,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			6,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			}
};

static const struct wave_element wave_25[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_RESTORE_PLATFORMS,	0,					0			},
	{	0,			0,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			1,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			2,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			3,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			4,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			5,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			6,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			7,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			8,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			9,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			10,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			11,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			}
};

static const struct wave_element wave_26[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			2,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			4,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			}
};

static const struct wave_element wave_27[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			2,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			4,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			}
};

static const struct wave_element wave_28[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			2,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			4,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			DIR_RIGHT,				WAVE_ELEMENT_ENEMY_IN_SKY,		ENEMY_RACE_PTERY,		WAVE_PTERY_Y	},
	{	0,			DIR_LEFT,					WAVE_ELEMENT_ENEMY_IN_SKY,		ENEMY_RACE_PTERY,		WAVE_PTERY_Y	},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			}
};

static const struct wave_element wave_29[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			1,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			2,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	0,			4,						WAVE_ELEMENT_DISABLE_PLATFORM,	0,					0			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_HUNTER,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			1,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			},
	{	80,			2,						WAVE_ELEMENT_ENEMY_AT_PAD,		ENEMY_RACE_LORD,		0,			}
};

static const struct wave_element wave_30[] =
{
	/*	treshold		index					type							race					param		*/
	{	0,			0,						WAVE_ELEMENT_RESTORE_PLATFORMS,	0,					0			},
	{	0,			0,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			1,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			2,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			3,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			4,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			5,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			6,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			7,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			8,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			9,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			10,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			},
	{	0,			11,						WAVE_ELEMENT_EGG_AT_LOCATION,	ENEMY_RACE_HUNTER,		0			}
};

static const struct wave_def waves[] =
{
	/*	wave_type				num_elmts				wave_elmts	*/
	{	WAVE_TYPE_NORMAL,		NUM_ELMTS(wave_1),		wave_1	},
	{	WAVE_TYPE_SURVIVAL,	NUM_ELMTS(wave_2),		wave_2	},
	{	WAVE_TYPE_NORMAL,		NUM_ELMTS(wave_3),		wave_3	},
	//{	WAVE_TYPE_GLADIATOR,	NUM_ELMTS(wave_4),		wave_4	},
	{	WAVE_TYPE_EGG,		NUM_ELMTS(wave_5),		wave_5	},
	{	WAVE_TYPE_NORMAL,		NUM_ELMTS(wave_6),		wave_6	},
	{	WAVE_TYPE_SURVIVAL,	NUM_ELMTS(wave_7),		wave_7	},
	{	WAVE_TYPE_PTERY,		NUM_ELMTS(wave_8),		wave_8	},
	//{	WAVE_TYPE_GLADIATOR,	NUM_ELMTS(wave_9),		wave_9	},
	{	WAVE_TYPE_EGG,		NUM_ELMTS(wave_10),	wave_10	},
	{	WAVE_TYPE_NORMAL,		NUM_ELMTS(wave_11),	wave_11	},
	{	WAVE_TYPE_SURVIVAL,	NUM_ELMTS(wave_12),	wave_12	},
	{	WAVE_TYPE_PTERY,		NUM_ELMTS(wave_13),	wave_13	},
	//{	WAVE_TYPE_GLADIATOR,	NUM_ELMTS(wave_14),	wave_14	},
	{	WAVE_TYPE_EGG,		NUM_ELMTS(wave_15),	wave_15	},
	{	WAVE_TYPE_NORMAL,		NUM_ELMTS(wave_16),	wave_16	},
	{	WAVE_TYPE_SURVIVAL,	NUM_ELMTS(wave_17),	wave_17	},
	{	WAVE_TYPE_PTERY,		NUM_ELMTS(wave_18),	wave_18	},
	//{	WAVE_TYPE_GLADIATOR,	NUM_ELMTS(wave_19),	wave_19	},
	{	WAVE_TYPE_EGG,		NUM_ELMTS(wave_20),	wave_20	},
	{	WAVE_TYPE_NORMAL,		NUM_ELMTS(wave_21),	wave_21	},
	{	WAVE_TYPE_SURVIVAL,	NUM_ELMTS(wave_22),	wave_22	},
	{	WAVE_TYPE_PTERY,		NUM_ELMTS(wave_23),	wave_23	},
	//{	WAVE_TYPE_GLADIATOR,	NUM_ELMTS(wave_24),	wave_24	},
	{	WAVE_TYPE_EGG,		NUM_ELMTS(wave_25),	wave_25	},
	{	WAVE_TYPE_NORMAL,		NUM_ELMTS(wave_26),	wave_26	},
	{	WAVE_TYPE_SURVIVAL,	NUM_ELMTS(wave_27),	wave_27	},
	{	WAVE_TYPE_PTERY,		NUM_ELMTS(wave_28),	wave_28	},
	//{	WAVE_TYPE_GLADIATOR,	NUM_ELMTS(wave_29),	wave_29	},
	{	WAVE_TYPE_EGG,		NUM_ELMTS(wave_30),	wave_30	}
};

static const unsigned int max_waves = NUM_ELMTS(waves);

void init_wave(
	struct wave *wave
	)
{
	wave->fine_timer =		0;
	wave->timer =			0;

	wave->wave_index =		0;
	wave->counter =		0;
	wave->element_index =	0;
	wave->new_wave =		0;
}

unsigned close_wave(
	struct wave *wave
	)
{
	struct enemy *enemy;

	wave->fine_timer =		0;
	wave->timer =			0;

	enemy = (struct enemy *) enemy_list;
	while (enemy != 0)
	{
		enemy->state = ENEMY_STATE_REMOVE;
		enemy->state_counter = 0;
		enemy = (struct enemy *) enemy->ch.obj.next;
	}

	wave->new_wave = 0;

	return waves[wave->wave_index].wave_type;
}
	
unsigned int move_wave(
	struct wave *wave
	)
{
	struct enemy *enemy;
	unsigned int result = 0;

	if (++wave->fine_timer >= WAVE_FINE_TIMER_TRESHOLD)
	{
		wave->fine_timer = 0;
		if (++wave->timer == WAVE_PTERY_TRESHOLD)
		{
			if (enemy_free_list != 0)
			{
				init_enemy_in_sky(
					(struct enemy *) enemy_free_list,
					DIR_LEFT,
					WAVE_PTERY_Y,
					&enemy_races[ENEMY_RACE_PTERY]
					);
			}
		}
	}

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
			else if (waves[wave->wave_index].elements[wave->element_index].type == WAVE_ELEMENT_RESTORE_PLATFORMS)
			{
				restore_platforms();
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
			enemy = (struct enemy *) enemy_list;
			while (enemy != 0)
			{
				if (enemy->race->type == ENEMY_TYPE_PTERY)
				{
					enemy->state = ENEMY_STATE_REMOVE;
					enemy->state_counter = 0;
				}
				enemy = (struct enemy *) enemy->ch.obj.next;
			}

			if (++wave->wave_index >= max_waves)
			{
				wave->wave_index = 0;
				result = 255;
			}
		}
	}

	return result;
}

unsigned int get_wave_type(
	struct wave *wave
	)
{
	return waves[wave->wave_index].wave_type;
}

#define WAVE_TEXT_X 		18
#define WAVE_TEXT_Y 		32
#define WAVE_TEXT_SPACE	8

void draw_award_wave(
	unsigned int award_type
	)
{
	switch (award_type)
	{
		case WAVE_AWARD_TYPE_SURVIVAL:
			reset_text();
			Print_Str_d(WAVE_TEXT_Y, -WAVE_TEXT_X-7, (char *) survival_award_text);
			Print_Str_d(WAVE_TEXT_Y - WAVE_TEXT_SPACE, -WAVE_TEXT_X + 7, (char *) bonus_1000_text);
			break;

		default:
			break;
	}
}

void announce_wave(
	struct wave *wave
	)
{
	reset_text();
	Print_Str_d(WAVE_TEXT_Y, -WAVE_TEXT_X, (char *) wave_heading_text);
	print_2digit_number(WAVE_TEXT_Y, 6, (unsigned long) wave->wave_index + 1);
	if (waves[wave->wave_index].wave_type)
	{
		Print_Str_d(WAVE_TEXT_Y - WAVE_TEXT_SPACE,
				   -(WAVE_TEXT_X + wave_type_info[waves[wave->wave_index].wave_type - 1].dx),
				   (char *) wave_type_info[waves[wave->wave_index].wave_type - 1].text);
	}
}

// ***************************************************************************
// end of file
// ***************************************************************************
