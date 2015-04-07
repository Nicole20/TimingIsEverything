#include "stdafx.h"
#include "blocks.h"

blocks::blocks()
{
	spot = 0;
	stop = false;
}

blocks::blocks(int pos)
{
	spot = pos;
	stop = false;
}

blocks::~blocks()
{
}
