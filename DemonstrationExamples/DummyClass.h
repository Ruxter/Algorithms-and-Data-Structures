#pragma once
class DummyClass
{
public:
	DummyClass();
	DummyClass(int x, int y);
	~DummyClass();
	bool operator < (const int IntNumber) const;
	int x, y;
private:
};

