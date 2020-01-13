#ifndef _WAVE_H
#define _WAVE_H

#define WAVE_TYPE_NORMAL				0
#define WAVE_TYPE_SURVIVAL				1
#define WAVE_TYPE_EGG					2
#define WAVE_TYPE_GLADIATOR				3
#define WAVE_TYPE_PTERY				4

#define WAVE_FINE_TIMER_TRESHOLD		50
#define WAVE_PTERY_TRESHOLD				30
#define WAVE_PTERY_Y					48

#define WAVE_ELEMENT_ENEMY_AT_PAD		1
#define WAVE_ELEMENT_ENEMY_IN_SKY		2
#define WAVE_ELEMENT_EGG_AT_LOCATION		10
#define WAVE_ELEMENT_INIT_PLATFORMS		20
#define WAVE_ELEMENT_DISABLE_PLATFORM	21
#define WAVE_ELEMENT_ENABLE_PLATFORM		22
#define WAVE_ELEMENT_RESTORE_PLATFORMS	23
#define WAVE_ELEMENT_SET_GROUND_LENGTH	24

#define WAVE_AWARD_TYPE_NONE			0
#define WAVE_AWARD_TYPE_SURVIVAL		1

struct wave_element
{
	unsigned int treshold;
	unsigned int index;
	unsigned int type;
	unsigned int race;
	signed int param;
};

struct wave_def
{
	unsigned int wave_type;
	unsigned int num_elements;
	const struct wave_element *elements;
};

struct wave
{
	unsigned int fine_timer;
	unsigned int timer;
	unsigned int wave_index;
	unsigned int counter;
	unsigned int element_index;
	unsigned int new_wave;
};

void init_wave(
	struct wave *wave
	);

unsigned int close_wave(
	struct wave *wave
	);

unsigned int move_wave(
	struct wave *wave
	);

unsigned int get_wave_type(
	struct wave *wave
	);

void draw_award_wave(
	unsigned int award_type
	);

void announce_wave(
	struct wave *wave
	);

#endif
