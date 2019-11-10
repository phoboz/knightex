#ifndef _EAGLE_H
#define _EAGLE_H

#define EAGLE_SCALE	8

#define EAGLE_LEFT					0
#define EAGLE_FLAP_LEFT			1
#define EAGLE_WALK_LEFT_START		2
#define EAGLE_WALK_LEFT_END			5
#define EAGLE_BRAKE_LEFT			6

#define EAGLE_RIGHT				7
#define EAGLE_FLAP_RIGHT			8
#define EAGLE_WALK_RIGHT_START		9
#define EAGLE_WALK_RIGHT_END		12
#define EAGLE_BRAKE_RIGHT			13

#define EAGLE_RISE_LEFT_START		14
#define EAGLE_RISE_LEFT_END			21
#define EAGLE_RISE_RIGHT_START		22
#define EAGLE_RISE_RIGHT_END		29

extern const signed char* const eagle[];

#endif