#ifndef DATEWRAPPER_H
#define DATEWRAPPER_H

#include "date.h"
#include <iostream>

using namespace date::literals;		// Exception to the general rule

namespace Dates
{
	class XLDate
	{
	public:
		XLDate();
		XLDate(unsigned serialDate);								// throws out_of_range
		XLDate(unsigned year, unsigned month, unsigned day);		// throws out_of_range

		// We should maybe make these binary friend functions:
		XLDate& addYears(int years);
		XLDate& addMonths(int months);
		XLDate& addDays(int days);

		unsigned daysInMonth() const;
		unsigned dayOfWeek() const;		// What is the day of the week (1-7, or 0-6)
										// Needs implementation
		bool endOfMonth() const;
		bool leapYear() const;			// Is the date in a leap year
		bool weekday() const;			// Is the date on a weekday (Needs implementation)

		unsigned year() const;
		unsigned month() const;
		unsigned day() const;
		unsigned serialDate() const;

		void setYear(unsigned year);
		void setMonth(unsigned month);
		void setDay(unsigned day);
		void setSerialDate(unsigned serialDate);

		unsigned operator()() const;		// Alternative accessor for serialDate_
		unsigned operator - (const XLDate& rhs) const;

		XLDate& operator += (int days);
		XLDate& operator -= (int days);

		XLDate& operator ++ ();
		XLDate& operator -- ();

		XLDate operator ++ (int notused);
		XLDate operator -- (int notused);

		bool operator == (const XLDate& rhs) const;
		bool operator != (const XLDate& rhs) const;
		bool operator < (const XLDate& rhs) const;
		bool operator > (const XLDate& rhs) const;
		bool operator <= (const XLDate& rhs) const;
		bool operator >= (const XLDate& rhs) const;

		// friend operator so that we can output date details with cout
		friend std::ostream& operator << (std::ostream& os, const XLDate& rhs);

	private:
		bool serialToDate_();
		bool dateToSerial_();

		unsigned serialDate_;
		date::year_month_day date_;

		// This can only be done in the header for integer types (prior to C++11)
		static const unsigned minSerial_ = 1;		// 1900.01.01: Matches Excel
		static const unsigned maxSerial_ = 109574;	// 2199.12.31: Matches Excel

	};
};

#endif