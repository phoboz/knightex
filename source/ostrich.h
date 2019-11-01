#ifndef _OSTRICH_H
#define _OSTRICH_H

#define OSTRICH_SCALE				8

#define OSTRICH_LEFT				0
#define OSTRICH_FLAP_LEFT			1
#define OSTRICH_WALK_LEFT_START		2
#define OSTRICH_WALK_LEFT_END		5
#define OSTRICH_BRAKE_LEFT			6

#define OSTRICH_RIGHT				7
#define OSTRICH_FLAP_RIGHT			8
#define OSTRICH_WALK_RIGHT_START	9
#define OSTRICH_WALK_RIGHT_END		12
#define OSTRICH_BRAKE_RIGHT			13

#define OSTRICH_RISE_LEFT_START		14
#define OSTRICH_RISE_LEFT_END		22
#define OSTRICH_RISE_RIGHT_START	23
#define OSTRICH_RISE_RIGHT_END		31

extern const signed char* const ostrich[];

#endif
