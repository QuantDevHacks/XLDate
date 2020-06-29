#include "Dates/XLDate.h"

#include <iostream>

using Dates::XLDate;
using std::cout;
using std::endl;

void quickTestDates();
void testLeapDates();

int main()
{
	//quickTestDates();
	//testLeapDates();
	XLDate a(1900,1,11);
	cout << a.serialDate() << endl; 
	cout << a.dayOfWeek() << endl;
	return 0;
}

void quickTestDates()
{
	cout << endl << "*** quickTestDates() *** " << endl;
	XLDate valDate(2017, 7, 1);
	XLDate expDate(valDate);
	expDate.addYears(5);

	cout << "Val Date = " << valDate << endl;	// 42917
	cout << "Exp Date = " << expDate << endl;	// 44743
	cout << endl;
}

void testLeapDates()
{
	cout << endl << "*** testLeapDates() *** " << endl;
	XLDate d1(2017, 7, 1);
	XLDate d2(2000, 2, 1);
	XLDate d3(1900, 10, 26);

	cout << "d1 = " << d1 << " is a leap year? " << (d1.leapYear() ? "True" : "False") << endl;
	cout << "d2 = " << d2 << " is a leap year? " << (d2.leapYear() ? "True" : "False") << endl;
	cout << "d3 = " << d3 << " is a leap year? " << (d3.leapYear() ? "True" : "False") << endl;
	cout << "1900 is not actually a leap year, but we are replicating Excel's bug" << endl;
	cout << endl;
}

