// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "vulture.h"

#define BLOW_UP VULTURE_SCALE

// ---------------------------------------------------------------------------

const signed char vulture_0[]=
{	(signed char) +0, +7*BLOW_UP, +5*BLOW_UP, // sync and move to y, x
	(signed char) -1, +3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, +15*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_1[]=
{	(signed char) +0, +5*BLOW_UP, +7*BLOW_UP, // sync and move to y, x
	(signed char) -1, +5*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -15*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_2[]=
{	(signed char) +0, -1*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) -1, -7*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +2*BLOW_UP, -3*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, +4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_3[]=
{	(signed char) +0, -15*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) +0, -3*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +12*BLOW_UP, +2*BLOW_UP, // mode, y, x
	(signed char) -1, -6*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -15*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +0, -11*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, -6*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_4[]=
{	(signed char) +0, -15*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) +0, -3*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +12*BLOW_UP, +2*BLOW_UP, // mode, y, x
	(signed char) -1, -6*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -15*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +0, -11*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, -8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_5[]=
{	(signed char) +0, -1*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) -1, -7*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) +0, -2*BLOW_UP, -8*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, +4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_6[]=
{	(signed char) +0, +0*BLOW_UP, +2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -11*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, +6*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, +12*BLOW_UP, +7*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, -15*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +15*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_7[]=
{	(signed char) +0, +7*BLOW_UP, -5*BLOW_UP, // sync and move to y, x
	(signed char) -1, +3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, -15*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_8[]=
{	(signed char) +0, +5*BLOW_UP, -7*BLOW_UP, // sync and move to y, x
	(signed char) -1, +5*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +15*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_9[]=
{	(signed char) +0, -1*BLOW_UP, -4*BLOW_UP, // sync and move to y, x
	(signed char) -1, -7*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +2*BLOW_UP, +3*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_10[]=
{	(signed char) +0, -15*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) +0, -3*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +12*BLOW_UP, -2*BLOW_UP, // mode, y, x
	(signed char) -1, -6*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +15*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +0, -11*BLOW_UP, +4*BLOW_UP, // mode, y, x
	(signed char) -1, -6*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_11[]=
{	(signed char) +0, -15*BLOW_UP, -4*BLOW_UP, // sync and move to y, x
	(signed char) +0, -3*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, +12*BLOW_UP, -2*BLOW_UP, // mode, y, x
	(signed char) -1, -6*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +15*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +0, -11*BLOW_UP, +4*BLOW_UP, // mode, y, x
	(signed char) -1, -8*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_12[]=
{	(signed char) +0, -1*BLOW_UP, -4*BLOW_UP, // sync and move to y, x
	(signed char) -1, -7*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) +0, -2*BLOW_UP, +8*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_13[]=
{	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // sync and move to y, x
	(signed char) -1, -11*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -6*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +12*BLOW_UP, -7*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, +15*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -15*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_left_0[]=
{	(signed char) +0, -10*BLOW_UP, +8*BLOW_UP, // sync and move to y, x
	(signed char) +0, -8*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_left_1[]=
{	(signed char) +0, -10*BLOW_UP, +10*BLOW_UP, // sync and move to y, x
	(signed char) +0, -8*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +5*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_left_2[]=
{	(signed char) +0, -10*BLOW_UP, +10*BLOW_UP, // sync and move to y, x
	(signed char) +0, -8*BLOW_UP, +1*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +3*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_left_3[]=
{	(signed char) +0, -15*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) +0, -2*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -1*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, +2*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, +4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_left_4[]=
{	(signed char) +0, -13*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) -1, -5*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -6*BLOW_UP, // mode, y, x
	(signed char) -1, +6*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, +4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_left_5[]=
{	(signed char) +0, -9*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) -1, -7*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -6*BLOW_UP, // mode, y, x
	(signed char) -1, +2*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, +4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_left_6[]=
{	(signed char) +0, -5*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) -1, -7*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, +4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_left_7[]=
{	(signed char) +0, -1*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) -1, -7*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +2*BLOW_UP, -3*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, +4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_right_0[]=
{	(signed char) +0, -10*BLOW_UP, -8*BLOW_UP, // sync and move to y, x
	(signed char) +0, -8*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_right_1[]=
{	(signed char) +0, -10*BLOW_UP, -10*BLOW_UP, // sync and move to y, x
	(signed char) +0, -8*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +5*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_right_2[]=
{	(signed char) +0, -10*BLOW_UP, -10*BLOW_UP, // sync and move to y, x
	(signed char) +0, -8*BLOW_UP, -1*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +3*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_right_3[]=
{	(signed char) +0, -15*BLOW_UP, -4*BLOW_UP, // sync and move to y, x
	(signed char) +0, -2*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -1*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, +4*BLOW_UP, // mode, y, x
	(signed char) -1, +2*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_right_4[]=
{	(signed char) +0, -13*BLOW_UP, -4*BLOW_UP, // sync and move to y, x
	(signed char) -1, -5*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, +6*BLOW_UP, // mode, y, x
	(signed char) -1, +6*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_right_5[]=
{	(signed char) +0, -9*BLOW_UP, -4*BLOW_UP, // sync and move to y, x
	(signed char) -1, -7*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, +6*BLOW_UP, // mode, y, x
	(signed char) -1, +2*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_right_6[]=
{	(signed char) +0, -5*BLOW_UP, -4*BLOW_UP, // sync and move to y, x
	(signed char) -1, -7*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char vulture_rise_right_7[]=
{	(signed char) +0, -1*BLOW_UP, -4*BLOW_UP, // sync and move to y, x
	(signed char) -1, -7*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +0, +2*BLOW_UP, +3*BLOW_UP, // mode, y, x
	(signed char) -1, +1*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +11*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, -1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -15*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char* const vulture[]=
{	 vulture_0, // list of all single vectorlists in this
	 vulture_1,
	 vulture_2,
	 vulture_3,
	 vulture_4,
	 vulture_5,
	 vulture_6,
	 vulture_7,
	 vulture_8,
	 vulture_9,
	 vulture_10,
	 vulture_11,
	 vulture_12,
	 vulture_13,
	 vulture_rise_left_0,
	 vulture_rise_left_1,
	 vulture_rise_left_2,
	 vulture_rise_left_3,
	 vulture_rise_left_4,
	 vulture_rise_left_5,
	 vulture_rise_left_6,
	 vulture_rise_left_7,
	 vulture_rise_right_0,
	 vulture_rise_right_1,
	 vulture_rise_right_2,
	 vulture_rise_right_3,
	 vulture_rise_right_4,
	 vulture_rise_right_5,
	 vulture_rise_right_6,
	 vulture_rise_right_7
};

// ***************************************************************************
// end of file
// ***************************************************************************
