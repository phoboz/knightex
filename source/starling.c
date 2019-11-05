// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "starling.h"

// ---------------------------------------------------------------------------

#define BLOW_UP STARLING_SCALE

const signed char starling_left_0[]=
{	(signed char) +0, +13*BLOW_UP, +3*BLOW_UP, // sync and move to y, x
	(signed char) -1, -3*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_1[]=
{	(signed char) +0, +14*BLOW_UP, +14*BLOW_UP, // sync and move to y, x
	(signed char) +0, +12*BLOW_UP, +6*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -7*BLOW_UP, -13*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +14*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +14*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_2[]=
{	(signed char) +0, +3*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -9*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -11*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +5*BLOW_UP, -2*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_3[]=
{	(signed char) +0, +3*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -7*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +3*BLOW_UP, -7*BLOW_UP, // mode, y, x
	(signed char) -1, +2*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_4[]=
{	(signed char) +0, -14*BLOW_UP, -9*BLOW_UP, // sync and move to y, x
	(signed char) +0, -4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -7*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -14*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) +0, -10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -9*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -11*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_5[]=
{	(signed char) +0, +3*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -11*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, +9*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +11*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_6[]=
{	(signed char) +0, -14*BLOW_UP, -14*BLOW_UP, // sync and move to y, x
	(signed char) +0, -4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +11*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -14*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, +4*BLOW_UP, // mode, y, x
	(signed char) -1, -10*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -10*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_7[]=
{	(signed char) +0, -4*BLOW_UP, -4*BLOW_UP, // sync and move to y, x
	(signed char) +0, -4*BLOW_UP, -2*BLOW_UP, // additional sync move to y, x
	(signed char) +0, -4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) +0, -4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) +0, -2*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_8[]=
{	(signed char) +0, -8*BLOW_UP, +3*BLOW_UP, // sync and move to y, x
	(signed char) +0, -8*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) +0, -2*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_9[]=
{	(signed char) +0, -10*BLOW_UP, +10*BLOW_UP, // sync and move to y, x
	(signed char) +0, -8*BLOW_UP, +3*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +4*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_10[]=
{	(signed char) +0, -7*BLOW_UP, +3*BLOW_UP, // sync and move to y, x
	(signed char) -1, -3*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_11[]=
{	(signed char) +0, -13*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -5*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, +8*BLOW_UP, // mode, y, x
	(signed char) -1, +5*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_12[]=
{	(signed char) +0, -9*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -9*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, +2*BLOW_UP, // mode, y, x
	(signed char) -1, +4*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_13[]=
{	(signed char) +0, -5*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -9*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, +7*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_left_14[]=
{	(signed char) +0, -1*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -9*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_0[]=
{	(signed char) +0, +13*BLOW_UP, -3*BLOW_UP, // sync and move to y, x
	(signed char) -1, -3*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_1[]=
{	(signed char) +0, +14*BLOW_UP, -14*BLOW_UP, // sync and move to y, x
	(signed char) +0, +12*BLOW_UP, -6*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -7*BLOW_UP, +13*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -14*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +14*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_2[]=
{	(signed char) +0, +3*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -9*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -11*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +5*BLOW_UP, +2*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_3[]=
{	(signed char) +0, +3*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -7*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +3*BLOW_UP, +7*BLOW_UP, // mode, y, x
	(signed char) -1, +2*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_4[]=
{	(signed char) +0, -14*BLOW_UP, +9*BLOW_UP, // sync and move to y, x
	(signed char) +0, -4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -7*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +14*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +0, -10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -9*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -11*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_5[]=
{	(signed char) +0, +3*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -9*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -11*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -9*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +11*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_6[]=
{	(signed char) +0, -14*BLOW_UP, +14*BLOW_UP, // sync and move to y, x
	(signed char) +0, -4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +11*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +14*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, -10*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -10*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_7[]=
{	(signed char) +0, -4*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) +0, -4*BLOW_UP, +2*BLOW_UP, // additional sync move to y, x
	(signed char) +0, -4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) +0, -4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) +0, -2*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_8[]=
{	(signed char) +0, -8*BLOW_UP, -3*BLOW_UP, // sync and move to y, x
	(signed char) +0, -8*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) +0, -2*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +0*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_9[]=
{	(signed char) +0, -10*BLOW_UP, -10*BLOW_UP, // sync and move to y, x
	(signed char) +0, -8*BLOW_UP, -3*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +4*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_10[]=
{	(signed char) +0, -7*BLOW_UP, -3*BLOW_UP, // sync and move to y, x
	(signed char) -1, -3*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_11[]=
{	(signed char) +0, -13*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -5*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -8*BLOW_UP, // mode, y, x
	(signed char) -1, +5*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_12[]=
{	(signed char) +0, -9*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -9*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // mode, y, x
	(signed char) -1, +4*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_13[]=
{	(signed char) +0, -5*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -9*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, +7*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char starling_right_14[]=
{	(signed char) +0, -1*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -9*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, +4*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // mode, y, x
	(signed char) -1, -3*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -14*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char* const starling[]=
{	 starling_left_0, // list of all single vectorlists in this
	 starling_left_1,
	 starling_left_2,
	 starling_left_3,
	 starling_left_4,
	 starling_left_5,
	 starling_left_6,
	 starling_left_7,
	 starling_left_8,
	 starling_left_9,
	 starling_left_10,
	 starling_left_11,
	 starling_left_12,
	 starling_left_13,
	 starling_left_14,
	 starling_right_0,
	 starling_right_1,
	 starling_right_2,
	 starling_right_3,
	 starling_right_4,
	 starling_right_5,
	 starling_right_6,
	 starling_right_7,
	 starling_right_8,
	 starling_right_9,
	 starling_right_10,
	 starling_right_11,
	 starling_right_12,
	 starling_right_13,
	 starling_right_14
};

// ***************************************************************************
// end of file
// ***************************************************************************
