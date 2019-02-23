// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "ostrich.h"

// ---------------------------------------------------------------------------

#define BLOW_UP OSTRICH_SCALE

const signed char ostrich_0[]=
{	(signed char) +0, +12*BLOW_UP, +8*BLOW_UP, // sync and move to y, x
	(signed char) -1, -2*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_1[]=
{	(signed char) +0, +10*BLOW_UP, +10*BLOW_UP, // sync and move to y, x
	(signed char) -1, +7*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, -10*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_2[]=
{	(signed char) +0, -13*BLOW_UP, -4*BLOW_UP, // sync and move to y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -7*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -11*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_3[]=
{	(signed char) +0, -15*BLOW_UP, -6*BLOW_UP, // sync and move to y, x
	(signed char) -1, +2*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -6*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_4[]=
{	(signed char) +0, -12*BLOW_UP, +6*BLOW_UP, // sync and move to y, x
	(signed char) +0, -6*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +11*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -10*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_5[]=
{	(signed char) +0, -12*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) +0, -6*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +11*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, -5*BLOW_UP, // mode, y, x
	(signed char) -1, -7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -11*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_6[]=
{	(signed char) +0, -12*BLOW_UP, -7*BLOW_UP, // sync and move to y, x
	(signed char) +0, -6*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, -7*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -11*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_7[]=
{	(signed char) +0, +12*BLOW_UP, -8*BLOW_UP, // sync and move to y, x
	(signed char) -1, -2*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_8[]=
{	(signed char) +0, +10*BLOW_UP, -10*BLOW_UP, // sync and move to y, x
	(signed char) -1, +7*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, -10*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -8*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_9[]=
{	(signed char) +0, -13*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -7*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -11*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_10[]=
{	(signed char) +0, -15*BLOW_UP, +6*BLOW_UP, // sync and move to y, x
	(signed char) -1, +2*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +9*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -6*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_11[]=
{	(signed char) +0, -12*BLOW_UP, -6*BLOW_UP, // sync and move to y, x
	(signed char) +0, -6*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +11*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -10*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_12[]=
{	(signed char) +0, -12*BLOW_UP, -4*BLOW_UP, // sync and move to y, x
	(signed char) +0, -6*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +11*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, +5*BLOW_UP, // mode, y, x
	(signed char) -1, -7*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, -11*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ostrich_13[]=
{	(signed char) +0, -12*BLOW_UP, +7*BLOW_UP, // sync and move to y, x
	(signed char) +0, -6*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +1*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +8*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -9*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) +0, +1*BLOW_UP, +4*BLOW_UP, // mode, y, x
	(signed char) -1, -7*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -11*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char* const ostrich[]=
{	 ostrich_0, // list of all single vectorlists in this
	 ostrich_1,
	 ostrich_2,
	 ostrich_3,
	 ostrich_4,
	 ostrich_5,
	 ostrich_6,
	 ostrich_7,
	 ostrich_8,
	 ostrich_9,
	 ostrich_10,
	 ostrich_11,
	 ostrich_12,
	 ostrich_13,
};

// ***************************************************************************
// end of file
// ***************************************************************************
