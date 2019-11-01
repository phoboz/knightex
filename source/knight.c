// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "knight.h"

// ---------------------------------------------------------------------------

#define BLOW_UP KNIGHT_SCALE

const signed char knight_0[]=
{	(signed char) +0, +10*BLOW_UP, +1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_1[]=
{	(signed char) +0, +10*BLOW_UP, -1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_2[]=
{	(signed char) +0, +11*BLOW_UP, +6*BLOW_UP, // sync and move to y, x
	(signed char) +0, +7*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -8*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +11*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_left_0[]=
{	(signed char) +0, -8*BLOW_UP, -6*BLOW_UP, // sync and move to y, x
	(signed char) +0, -8*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) +0, -2*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +0*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_left_1[]=
{	(signed char) +0, -12*BLOW_UP, +1*BLOW_UP, // sync and move to y, x
	(signed char) +0, -3*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -1*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_left_2[]=
{	(signed char) +0, -11*BLOW_UP, +1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_left_3[]=
{	(signed char) +0, -7*BLOW_UP, +1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_left_4[]=
{	(signed char) +0, -3*BLOW_UP, +1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_left_5[]=
{	(signed char) +0, +1*BLOW_UP, +1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_left_6[]=
{	(signed char) +0, +5*BLOW_UP, +1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_left_7[]=
{	(signed char) +0, +9*BLOW_UP, +1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_right_0[]=
{	(signed char) +0, -8*BLOW_UP, +6*BLOW_UP, // sync and move to y, x
	(signed char) +0, -8*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) +0, -2*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +0*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_right_1[]=
{	(signed char) +0, -12*BLOW_UP, -1*BLOW_UP, // sync and move to y, x
	(signed char) +0, -3*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -1*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_right_2[]=
{	(signed char) +0, -11*BLOW_UP, -1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_right_3[]=
{	(signed char) +0, -7*BLOW_UP, -1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_right_4[]=
{	(signed char) +0, -3*BLOW_UP, -1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_right_5[]=
{	(signed char) +0, +1*BLOW_UP, -1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_right_6[]=
{	(signed char) +0, +5*BLOW_UP, -1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char knight_rise_right_7[]=
{	(signed char) +0, +9*BLOW_UP, -1*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +12*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char* const knight[]=
{	 knight_0, // list of all single vectorlists in this
	 knight_1,
	 knight_2,
	 knight_rise_left_0,
	 knight_rise_left_1,
	 knight_rise_left_2,
	 knight_rise_left_3,
	 knight_rise_left_4,
	 knight_rise_left_5,
	 knight_rise_left_6,
	 knight_rise_left_7,
	 knight_rise_right_0,
	 knight_rise_right_1,
	 knight_rise_right_2,
	 knight_rise_right_3,
	 knight_rise_right_4,
	 knight_rise_right_5,
	 knight_rise_right_6,
	 knight_rise_right_7
};

// ***************************************************************************
// end of file
// ***************************************************************************
