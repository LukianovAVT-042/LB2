#include "Test.h"
#include "DT.h"
#include <iostream>
#include <cassert>
void Test::TestPlus()
{
	DT a = DT(1,1,1,1,1);
	assert(a.PlusDay()==2);
	assert(a.PlusHour() == 2);
	assert(a.PlusMinute() == 2);
	assert(a.PlusMonth() == 2);
	assert(a.PlusYear() == 2);
	cout << "TestPlus completed";
}
void Test::TestMinus()
{
	DT a = DT(2, 2, 2, 2, 2);
	assert(a.MinusDay() == 1);
	assert(a.MinusHour() == 1);
	assert(a.MinusMinute() == 1);
	assert(a.MinusMonth() == 1);
	assert(a.MinusYear() == 1);
	cout << "TestMinus completed";
}
void Test::TestExcep()
{
	DT a = DT(0, -1, 0, -1, -1);
	assert(a.GetDay() == 1);
	assert(a.GetMonth() == 1);
	assert(a.GetHour() == 1);
	assert(a.GetMinute() == 1);
	assert(a.GetYear() == 1);
	cout << "TestExcep completed";
}
