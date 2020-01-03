// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "number.h"

// ---------------------------------------------------------------------------

#define BLOW_UP NUMBER_SCALE

const signed char number_0[]=
{	(signed char) +1, +6*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) +0, +5*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +3*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char number_1[]=
{	(signed char) +1, +6*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) +0, +5*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -6*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char number_2[]=
{	(signed char) +1, +6*BLOW_UP, +4*BLOW_UP, // sync and move to y, x
	(signed char) +0, +5*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // mode, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char number_3[]=
{	(signed char) +1, +6*BLOW_UP, +5*BLOW_UP, // sync and move to y, x
	(signed char) +0, +5*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -6*BLOW_UP, // mode, y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -6*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -4*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -2*BLOW_UP, // mode, y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char* const number[]=
{	 number_0, // list of all single vectorlists in this
	 number_1,
	 number_2,
	 number_3,
};

// ***************************************************************************
// end of file
// ***************************************************************************
