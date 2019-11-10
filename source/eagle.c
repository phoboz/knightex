// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "eagle.h"

// ---------------------------------------------------------------------------

#define BLOW_UP EAGLE_SCALE

const signed char eagle_left_0[]=
{	(signed char) +0, +11*BLOW_UP, +7*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +12*BLOW_UP, // draw, y, x
	(signed char) -1, +14*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_left_1[]=
{	(signed char) +0, +9*BLOW_UP, +6*BLOW_UP, // sync and move to y, x
	(signed char) +0, +4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_left_2[]=
{	(signed char) +0, +0*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) +0, -2*BLOW_UP, +3*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_left_3[]=
{	(signed char) +0, +0*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -6*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, -4*BLOW_UP, +13*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_left_4[]=
{	(signed char) +0, +0*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, +14*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_left_5[]=
{	(signed char) +0, +0*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -10*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +2*BLOW_UP, +8*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_left_6[]=
{	(signed char) +0, +0*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -11*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, +6*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +11*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_right_0[]=
{	(signed char) +0, +11*BLOW_UP, -7*BLOW_UP, // sync and move to y, x
	(signed char) -1, -1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -12*BLOW_UP, // draw, y, x
	(signed char) -1, +14*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_right_1[]=
{	(signed char) +0, +9*BLOW_UP, -6*BLOW_UP, // sync and move to y, x
	(signed char) +0, +4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_right_2[]=
{	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) +0, -2*BLOW_UP, -3*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_right_3[]=
{	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -6*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, -4*BLOW_UP, -13*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_right_4[]=
{	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -14*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_right_5[]=
{	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -10*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +2*BLOW_UP, -8*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_right_6[]=
{	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -11*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -6*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +11*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_left_0[]=
{	(signed char) +0, -6*BLOW_UP, +6*BLOW_UP, // sync and move to y, x
	(signed char) +0, -6*BLOW_UP, +6*BLOW_UP, // additional sync move to y, x
	(signed char) +0, -6*BLOW_UP, +2*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +2*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_left_1[]=
{	(signed char) +0, -9*BLOW_UP, +9*BLOW_UP, // sync and move to y, x
	(signed char) +0, -9*BLOW_UP, +5*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_left_2[]=
{	(signed char) +0, -9*BLOW_UP, +9*BLOW_UP, // sync and move to y, x
	(signed char) +0, -9*BLOW_UP, +3*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +2*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_left_3[]=
{	(signed char) +0, -9*BLOW_UP, +8*BLOW_UP, // sync and move to y, x
	(signed char) +0, -9*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +6*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_left_4[]=
{	(signed char) +0, -14*BLOW_UP, +1*BLOW_UP, // sync and move to y, x
	(signed char) +0, -4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +2*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) +0, -2*BLOW_UP, +2*BLOW_UP, // mode, y, x
	(signed char) -1, +2*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_left_5[]=
{	(signed char) +0, -14*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) +0, -4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +6*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, -6*BLOW_UP, +3*BLOW_UP, // mode, y, x
	(signed char) -1, +6*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_left_6[]=
{	(signed char) +0, -8*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, +6*BLOW_UP, // mode, y, x
	(signed char) -1, +2*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_left_7[]=
{	(signed char) +0, -4*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, +6*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_right_0[]=
{	(signed char) +0, -6*BLOW_UP, -6*BLOW_UP, // sync and move to y, x
	(signed char) +0, -6*BLOW_UP, -6*BLOW_UP, // additional sync move to y, x
	(signed char) +0, -6*BLOW_UP, -2*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +2*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_right_1[]=
{	(signed char) +0, -9*BLOW_UP, -9*BLOW_UP, // sync and move to y, x
	(signed char) +0, -9*BLOW_UP, -5*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_right_2[]=
{	(signed char) +0, -9*BLOW_UP, -9*BLOW_UP, // sync and move to y, x
	(signed char) +0, -9*BLOW_UP, -3*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +2*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_right_3[]=
{	(signed char) +0, -9*BLOW_UP, -8*BLOW_UP, // sync and move to y, x
	(signed char) +0, -9*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +6*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_right_4[]=
{	(signed char) +0, -14*BLOW_UP, -1*BLOW_UP, // sync and move to y, x
	(signed char) +0, -4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +2*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) +0, -2*BLOW_UP, -2*BLOW_UP, // mode, y, x
	(signed char) -1, +2*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_right_5[]=
{	(signed char) +0, -14*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) +0, -4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +6*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, -6*BLOW_UP, -3*BLOW_UP, // mode, y, x
	(signed char) -1, +6*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_right_6[]=
{	(signed char) +0, -8*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -6*BLOW_UP, // mode, y, x
	(signed char) -1, +2*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char eagle_rise_right_7[]=
{	(signed char) +0, -4*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, +6*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) +0, +8*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char* const eagle[]=
{	 eagle_left_0, // list of all single vectorlists in this
	 eagle_left_1,
	 eagle_left_2,
	 eagle_left_3,
	 eagle_left_4,
	 eagle_left_5,
	 eagle_left_6,
	 eagle_right_0,
	 eagle_right_1,
	 eagle_right_2,
	 eagle_right_3,
	 eagle_right_4,
	 eagle_right_5,
	 eagle_right_6,
	 eagle_rise_left_0,
	 eagle_rise_left_1,
	 eagle_rise_left_2,
	 eagle_rise_left_3,
	 eagle_rise_left_4,
	 eagle_rise_left_5,
	 eagle_rise_left_6,
	 eagle_rise_left_7,
	 eagle_rise_right_0,
	 eagle_rise_right_1,
	 eagle_rise_right_2,
	 eagle_rise_right_3,
	 eagle_rise_right_4,
	 eagle_rise_right_5,
	 eagle_rise_right_6,
	 eagle_rise_right_7
};

// ***************************************************************************
// end of file
// ***************************************************************************
