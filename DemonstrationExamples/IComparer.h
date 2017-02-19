#pragma once
#include "DummyClass.h"

/**
* Pomocn� interface a pod�d�n� t��da pro porovn�v�n� objekt� skrze dereferenci.
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