// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>

// ---------------------------------------------------------------------------

#define BLOW_UP 10

const signed char ostrich_fly_left_0[]=
{	(signed char) +1, +2*BLOW_UP, +8*BLOW_UP, // sync and move to y, x
	(signed char) -1, +0*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_fly_left_1[]=
{	(signed char) +1, +1*BLOW_UP, +10*BLOW_UP, // sync and move to y, x
	(signed char) -1, +6*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_fly_right_0[]=
{	(signed char) +1, +2*BLOW_UP, -8*BLOW_UP, // sync and move to y, x
	(signed char) -1, +0*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_fly_right_1[]=
{	(signed char) +1, +1*BLOW_UP, -10*BLOW_UP, // sync and move to y, x
	(signed char) -1, +6*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char* const ostrich[]=
{	 ostrich_fly_left_0, // list of all single vectorlists in this
	 ostrich_fly_left_1,
	 ostrich_fly_right_0,
	 ostrich_fly_right_1
};

// ***************************************************************************
// end of file
// ***************************************************************************
