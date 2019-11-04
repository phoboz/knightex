#ifndef _WAVE_H
#define _WAVE_H

#define WAVE_ELEMENT_ENEMY_AT_PAD		1
#define WAVE_ELEMENT_ENEMY_IN_SKY		2
#define WAVE_ELEMENT_EGG_AT_LOCATION		10
#define WAVE_ELEMENT_INIT_PLATFORMS		20
#define WAVE_ELEMENT_DISABLE_PLATFORM	21
#define WAVE_ELEMENT_ENABLE_PLATFORM		22
#define WAVE_ELEMENT_SET_GROUND_LENGTH	23

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
	unsigned int num_elements;
	const struct wave_element *elements;
};

struct wave
{
	unsigned int wave_index;
	unsigned int counter;
	unsigned int element_index;
	unsigned int new_wave;
};

void init_wave(
	struct wave *wave
	);

void close_wave(
	struct wave *wave
	);

unsigned int move_wave(
	struct wave *wave
	);

#endif
