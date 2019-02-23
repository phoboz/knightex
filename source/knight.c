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
	(signed char) +0, +10*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, -8*BLOW_UP, -5*BLOW_UP, // draw, y, x
	(signed char) -1, +4*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, -4*BLOW_UP, -2*BLOW_UP, // draw, y, x
	(signed char) -1, -3*BLOW_UP, +1*BLOW_UP, // draw, y, x
	(signed char) -1, -10*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +0*BLOW_UP, +4*BLOW_UP, // draw, y, x
	(signed char) -1, +10*BLOW_UP, -1*BLOW_UP, // draw, y, x
	(signed char) -1, +11*BLOW_UP, +5*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};
const signed char* const knight[]=
{	 knight_0, // list of all single vectorlists in this
	 knight_1,
	 knight_2,
};

// ***************************************************************************
// end of file
// ***************************************************************************
