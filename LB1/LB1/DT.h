#pragma once
#include <iostream>
#include <string>
using namespace std;
class DT
{
public:
	DT();
	~DT();
	DT(short valueday, short valuemonth, short valueyear, short valuehour, short valueminute);
	DT(const DT & ob);
private:
	static int val;
    short day;
	short month;
	short year;
	short hour;
	short minute;
public:
	char* SR();
	int PlusDay();
	int PlusMonth();
	int PlusYear();
	int PlusHour();
	int PlusMinute();
	int MinusDay();
	int MinusMonth();
	int MinusYear();
	int MinusHour();
	int MinusMinute();
	void SetDay(int day1);
	void SetMonth(int month1);
	void SetYear(int year1);
	void SetHour(int hour1);
	void SetMinute(int minute1);
	int GetDay();
	int GetMonth();
	int GetYear();
	int GetHour();
	int GetMinute();
};