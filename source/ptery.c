// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "ptery.h"

// ---------------------------------------------------------------------------


#define BLOW_UP PTERY_SCALE

const signed char ptery_0[]=
{	(signed char) +0, +5*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) -1, +3*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -11*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ptery_1[]=
{	(signed char) +0, +0*BLOW_UP, +6*BLOW_UP, // sync and move to y, x
	(signed char) +0, +0*BLOW_UP, +6*BLOW_UP, // sync and move to y, x
	(signed char) +0, +0*BLOW_UP, +2*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +2*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ptery_2[]=
{	(signed char) +0, -2*BLOW_UP, +11*BLOW_UP, // sync and move to y, x
	(signed char) -1, +4*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, +8*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +2*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ptery_3[]=
{	(signed char) +0, +5*BLOW_UP, -4*BLOW_UP, // sync and move to y, x
	(signed char) -1, +3*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +11*BLOW_UP, // draw, y, x
	(signed char) -1, -7*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ptery_4[]=
{	(signed char) +0, +0*BLOW_UP, -6*BLOW_UP, // sync and move to y, x
	(signed char) +0, +0*BLOW_UP, -6*BLOW_UP, // sync and move to y, x
	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +2*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, -9*BLOW_UP, // draw, y, x
	(signed char) -1, +7*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char ptery_5[]=
{	(signed char) +0, -2*BLOW_UP, -11*BLOW_UP, // sync and move to y, x
	(signed char) -1, +4*BLOW_UP, -7*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, +7*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, -1*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, +1*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -5*BLOW_UP, -8*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +5*BLOW_UP, +9*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char* const ptery[]=
{	 ptery_0, // list of all single vectorlists in this
	 ptery_1,
	 ptery_2,
	 ptery_3,
	 ptery_4,
	 ptery_5,
};

// ***************************************************************************
// end of file
// ***************************************************************************
