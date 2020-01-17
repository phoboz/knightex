// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>

// ---------------------------------------------------------------------------

static unsigned int _x;
static unsigned int _a;
static unsigned int _b; 
static unsigned int _c;
 
void init_random(
	unsigned int s1,
	unsigned int s2,
	unsigned int s3,
	unsigned int x0
	)
{
	_x = x0;
	_a = s1;
	_b = s2;
	_c = s3;
	_x++;
	_a = (_a^_c^_x);
	_b = (_b+_a);
	_c = ((_c+(_b>>1))^_a);
}

static unsigned int rnd(void)
{
	_x++;
	_a = (_a^_c^_x);
	_b = (_b+_a);
	_c = ((_c+(_b>>1))^_a);
	return _c;
}

unsigned int random_2(void)
{
	unsigned int result;
	unsigned int number = rnd();

	if (number < 128U)
	{
		result = 0;
	}
	else
	{
		result = 1;
	}

	return result;
}

unsigned int random_3(void)
{
	unsigned int result;
	unsigned int number = rnd();

	if (number < 85U)
	{
		result = 0;
	}
	else if (number < 170U)
	{
		result = 1;
	}
	else
	{
		result = 2;
	}

	return result;
}

unsigned int random_4(void)
{
	unsigned int result;
	unsigned int number = rnd();

	if (number < 64U)
	{
		result = 0;
	}
	else if (number < 128U)
	{
		result = 1;
	}
	else if (number < 192U)
	{
		result = 2;
	}
	else
	{
		result = 3;
	}

	return result;
}

// ***************************************************************************
// end of file
// ***************************************************************************
