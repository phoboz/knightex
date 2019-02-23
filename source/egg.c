// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>
#include "egg.h"

#define BLOW_UP EGG_SCALE

// ---------------------------------------------------------------------------

const signed char egg[]=
{	(signed char) +0, +10*BLOW_UP, -10*BLOW_UP, // sync and move to y, x
	(signed char) +0, +4*BLOW_UP, +0*BLOW_UP, // additional sync move to y, x
	(signed char) -1, +2*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, +10*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) -1, -6*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, -2*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +2*BLOW_UP, -10*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, -3*BLOW_UP, // draw, y, x
	(signed char) -1, +6*BLOW_UP, +3*BLOW_UP, // draw, y, x
	(signed char) +2 // endmarker 
};

// ***************************************************************************
// end of file
// ***************************************************************************
