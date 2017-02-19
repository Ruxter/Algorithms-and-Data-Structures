#pragma once
#include "DummyClass.h"

/**
* Pomocný interface a podìdìná tøída pro porovnávání objektù skrze dereferenci.
* Inspirace z .NET knihovny.
*/
template <class T> class IComparable {
public:
	virtual bool IsFirtsBigger(T* first, T* second) {
		return true;
	}
};

class DummyComparer : IComparable<DummyClass>
{
public:
	bool IsFirtsBigger(DummyClass *first, DummyClass *second) {
		return first->x > second->y;
	}
};