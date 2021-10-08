#include "DT.h"
#include <iostream>
#include <string>
using namespace std;
DT::DT()
{
	year = 0;
	day = 1;
	month = 1;
	hour = 0;
	minute = 0;
}
DT::DT(short valueday, short valuemonth, short valueyear, short valuehour, short valueminute)
{
	try//День
	{
		if (valueday < 32 && valueday > 0)
			day = valueday;
		else
			throw exception("Not correct data, assign default");
	}
	catch (const std::exception& ex)
	{
		day = 1;
		cout << ex.what() << endl;
	}
	 
	try//Месяц
	{
		if (valuemonth < 13 && valuemonth >0)
			month = valuemonth;
		else
			throw exception("Not correct data, assign default");
	}
	catch (const std::exception& ex)
	{
		month = 1;
		cout << ex.what() << endl;
	}

	try//Час
	{
		if (valuehour < 25 && valuehour >= 0)
			hour = valuehour;
		else
			throw exception("Not correct data, assign default");
	}
	catch (const std::exception& ex)
	{
		hour = 1;
		cout << ex.what() << endl;
	}

	try//Минута
	{
		if (valueminute < 61 && valueminute >= 0)
			minute = valueminute;
		else
			throw exception("Not correct data, assign default");
	}
	catch (const std::exception& ex)
	{
		minute = 1;
		cout << ex.what() << endl;
	}

	try//Год
	{
		if (valueyear > 0)
			year = valueyear;
		else
			throw exception("Not correct data, assign default");
	}
	catch (const std::exception& ex)
	{
		year = 1;
		cout << ex.what() << endl;
	}
}
DT::DT(const DT& ob)
{
	day = ob.day;
	month = ob.month; 
	year = ob.year;
	hour = ob.hour;
	minute = ob.minute;
}
DT::~DT()
{
	cout << "  Destructing DT "<<endl;
}

void DT::SetDay(int day1) {

	try
	{
		if (day1 < 31 && day1 > 0)
			day = day1;
		else
			throw exception("Incorrect data");
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
void DT::SetMonth(int month1) {
	try
	{
		if (month1 < 12 && month1 > 0)
			month = month1;
		else
			throw exception("Incorrect data");
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
void DT::SetYear(int year1) {
	try
	{
		if (year1 > 0)
		 year = year1;
		else
			throw exception("Incorrect data");
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
void DT::SetHour(int hour1) {
	try
	{
		if (hour1 < 24 && hour1 > 0)
			hour = hour1;
		else
			throw exception("Incorrect data");

	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
void DT::SetMinute(int minute1) {
	try
	{
		if (minute1 < 24 && minute1 > 0)
			minute = minute1;
		else
			throw exception("Incorrect data");
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

}

int DT::GetDay() { return day; };
int DT::GetMonth() { return month; };
int DT::GetYear() { return year; };
int DT::GetHour() { return hour; };
int DT::GetMinute() { return minute; };

int DT::PlusDay()
{
	if (!(year / 4 == 0))
	{
		if (month == 2)
		{
			if (day < 28)
				day++;
			else
			{
				day = 0;
				month++;
			}
		}
		else
		{
			if (month == 2)
			{
				if (day < 29)
					day++;
				else
				{
					day = 0;
					month++;
				}
			}
		}
	}
	 if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day < 31)
			day++;
		else
		{
			day = 1;
			month++;
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 30)
			day++;
		else
		{
			day = 1;
			month++;
		}
	}
	
	return day;
}
int DT::PlusMonth()
{if (month<12)
	month++;
else
{
	month = 1;
	year++;
}
	return month;
}
int DT::PlusYear()
{
	year++;
	return year;
}
int DT::PlusHour()
{
	if (hour<24)
	hour++;
	else
	{
		hour =0;
		day++;
	}
	return hour;
}
int DT::PlusMinute()
{
	if (minute < 60)
		minute++;
	else
	{
		minute = 0;
		hour++;
	}
	return minute;
}

int DT::MinusDay()
{
	day--;
	if ((month == 12 || month == 10 || month == 7 || month == 5) && day == 0)
	{
		day = 30;
		month--;
	}
	if ((month == 11 || month == 9 || month== 6 || month == 4) && day == 0)
	{
		day = 31;
		month--;
	}
	if (year% 4 == 0 && month == 3 && day == 0)
	{
		day = 29;
		month--;
	}
	if (year % 4 != 0 && month == 3 && day == 0)
	{
		day = 28;
		month--;
	}
	if ((month == 8 || month == 1) && day == 0)
	{
		day = 31;
		month--;
		if (month == 1)
			month = 12;
	}

	return day;
}
int DT::MinusMonth()
{
	if (month>1)
	month--;
	else
	{
		month = 12;
		year--;
	}
	return month;
}
int DT::MinusYear()
{
	year--;
	if (year < 0)
		cout << "Error";
	return year;
}
int DT::MinusHour()
{
	if(hour>0)
	hour--;
	else
	{
		hour = 24;
		day--;
	}
	return hour;
}
int DT::MinusMinute()
{
	if (minute>0)
	minute--;
	else
	{
		minute = 60;
		hour--;
	}
	return minute;
}

char* DT::SR()
{
	char* stroka= new char[255];
	sprintf_s(stroka,25, "%d:%d  %d.%d.%d", minute, hour, day, month, year);
	return stroka;
}