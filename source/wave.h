#ifndef _WAVE_H
#define _WAVE_H

#define WAVE_ELEMENT_ENEMY_AT_PAD		1
#define WAVE_ELEMENT_EGG_AT_LOCATION		2

struct wave_element
{
	unsigned int treshold;
	unsigned int type;
	unsigned int index;
};

#endif
