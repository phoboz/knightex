// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "number.h"

// ---------------------------------------------------------------------------

#define BLOW_UP NUMBER_SCALE

const signed char number_250[]=
{	(signed char) +0, +12*BLOW_UP, +7*BLOW_UP, // sync and move to y, x
	(signed char) +0, +3*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char number_500[]=
{	(signed char) +0, +12*BLOW_UP, +7*BLOW_UP, // sync and move to y, x
	(signed char) +0, +3*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -10*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char number_750[]=
{	(signed char) +0, +12*BLOW_UP, +7*BLOW_UP, // sync and move to y, x
	(signed char) +0, +3*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, +12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char number_1000[]=
{	(signed char) +0, +12*BLOW_UP, +9*BLOW_UP, // sync and move to y, x
	(signed char) +0, +3*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -10*BLOW_UP, // mode, y, x
	(signed char) -1, -12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -10*BLOW_UP, // mode, y, x
	(signed char) -1, +0*BLOW_UP, +6*BLOW_UP, // draw, y, x
	(signed char) -1, -12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, -6*BLOW_UP, // draw, y, x
	(signed char) -1, +12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +0, +0*BLOW_UP, -4*BLOW_UP, // mode, y, x
	(signed char) -1, -12*BLOW_UP, +0*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char* const number[]=
{	 number_250, // list of all single vectorlists in this
	 number_500,
	 number_750,
	 number_1000,
};

// ***************************************************************************
// end of file
// ***************************************************************************
