#include "DummyClass.h"

DummyClass::DummyClass()
{
	x = 0;
	y = 0;
}

DummyClass::DummyClass(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool DummyClass::operator < (const int IntNumber) const
{
	return this->x < this->y;
}


DummyClass::~DummyClass()
{
}
