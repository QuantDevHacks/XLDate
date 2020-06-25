#include "XLDate.h"
#include "date.h"
#include <stdexcept>	// For out_of_range and invalid argument exceptions
// See http://www.cplusplus.com/reference/stdexcept/out_of_range/

using Dates::XLDate;
using namespace date;		// C++20 date namespace
using std::out_of_range;
using std::invalid_argument;

/*
	This implementation borrows information from the following source:
	http://www.codeproject.com/Articles/2750/Excel-serial-date-to-Day-Month-Year-and-vise-versa
*/

// Note:  _MSC_VER >= 1900 in date.h means Visual Studio 2015 or higher

namespace Dates
{
	// Default:  Earliest UNIX date
	XLDate::XLDate():date_(date::year(1970) / date::month(1) / date::day(1))
	{
		if (!dateToSerial_())
		{
			// This should never happen:
			out_of_range e("XLDate::XLDate: Calendar XLDate is out of range in default constructor.");
			throw e;
		}
	}

	XLDate::XLDate(unsigned serialDate) : serialDate_(serialDate)
	{
		if (!serialToDate_())
		{
			out_of_range e("XLDate::XLDate: Serial XLDate is out of range in serialDate constructor.");
			throw e;
		}
	}

	XLDate::XLDate(unsigned year, unsigned month, unsigned day) : date_(date::year(year) / date::month(month) / date::day(day))
	{		
		if (!dateToSerial_())
		{
			out_of_range e("XLDate::XLDate: Calendar XLDate is out of range in YMD constructor.");
			throw e;
		}
	}

	XLDate& XLDate::addYears(int years)
	{
		date_ += date::years(years);

		if (!dateToSerial_())
		{
			out_of_range e("XLDate::XLDate::addYears(.): resulting date out of range.");
			throw e;
		}

		return *this;
	}

	XLDate& XLDate::addMonths(int months)
	{
		date_ += date::months(months);

		if (!dateToSerial_())
		{
			out_of_range e("XLDate::XLDate::addMonths(.): resulting date out of range.");
			throw e;
		}

		return *this;
	}

	XLDate& XLDate::addDays(int days)
	{
		serialDate_ += days;

		if (!serialToDate_())
		{
			out_of_range e("XLDate::XLDate::addDays(.): resulting date out of range.");
			throw e;
		}

		return *this;
	}

	bool XLDate::endOfMonth() const
	{
		if (serialDate_ == 60)
		{
			return true;
		}

		return date_ == date_.year() / date_.month() / date::last;
	}

	unsigned XLDate::daysInMonth() const
	{
		static const unsigned monthLength[] = {
			31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
		};
		static const unsigned monthLeapLength[] = {
			31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
		};
		return (leapYear() ? monthLeapLength[month() - 1] : monthLength[month() - 1]);
	}
	
	bool XLDate::leapYear() const
	{	
		if(year() == 1900)
		{
			return true;
		}
		else
		{
			return date_.year().is_leap();
		}
	}

	unsigned XLDate::year() const
	{
		return static_cast<unsigned>(static_cast<int>(date_.year()));
	}

	unsigned XLDate::month() const
	{
		return static_cast<unsigned>(date_.month());
	}

	unsigned XLDate::day() const
	{
		return static_cast<unsigned>(date_.day());
	}

	unsigned XLDate::serialDate() const
	{
		return serialDate_;
	}

	void XLDate::setYear(unsigned year)
	{
		date_ = date::year(year) / date_.month() / date_.day();
		if (!dateToSerial_())
		{
			out_of_range e("Dates::XLDate::setYear(.): resulting date out of range.");
			throw e;
		}

	}

	void XLDate::setMonth(unsigned month)
	{
		date_ = date_.year() / date::month(month) / date_.day();
		if (!dateToSerial_())
		{
			out_of_range e("Dates::XLDate::setMonth(.): resulting date out of range.");
			throw e;
		}
	}

	void XLDate::setDay(unsigned day)
	{
		date_ = date_.year() / date_.month() / date_.day();
		if (!dateToSerial_())
		{
			out_of_range e("Dates::XLDate::setDay(.): resulting date out of range.");
			throw e;
		}
	}

	void XLDate::setSerialDate(unsigned serialXLDate)
	{
		serialDate_ = serialXLDate;
		if (!serialToDate_())
		{
			out_of_range e("Dates::XLDate::setSerialXLDate(.): resulting date out of range.");
			throw e;
		}
	}

	unsigned XLDate::operator()() const
	{
		return serialDate();
	}

	unsigned XLDate::operator - (const XLDate& rhs) const
	{
		return serialDate_ - rhs.serialDate_;
	}

	XLDate& XLDate::operator += (int days)
	{
		return addDays(days);
	}

	XLDate& XLDate::operator -= (int days)
	{
		return addDays(-days);
	}

	XLDate& XLDate::operator ++ ()
	{
		return addDays(1);
	}

	XLDate& XLDate::operator -- ()
	{
		return addDays(-1);
	}

	XLDate XLDate::operator ++ (int notused)
	{
		XLDate d(*this);

		return ++d;
	}

	XLDate XLDate::operator -- (int notused)
	{
		XLDate d(*this);

		return --d;
	}

	bool XLDate::operator == (const XLDate& rhs) const
	{
		return serialDate_ == rhs.serialDate_;
	}

	bool XLDate::operator!=(const XLDate & rhs) const
	{
		return serialDate_ != rhs.serialDate_;
	}

	bool XLDate::operator < (const XLDate& rhs) const
	{
		return serialDate_ < rhs.serialDate_;
	}

	bool XLDate::operator > (const XLDate& rhs) const
	{
		return serialDate_ > rhs.serialDate_;
	}

	bool XLDate::operator <= (const XLDate& rhs) const
	{
		return serialDate_ <= rhs.serialDate_;
	}

	bool XLDate::operator >= (const XLDate& rhs) const
	{
		return serialDate_ >= rhs.serialDate_;
	}

	bool XLDate::serialToDate_()
	{
		// Check if serial date is in range
		if ((serialDate_ - minSerial_) >= maxSerial_)
		{
			return false;
		}
		else if (serialDate_ == 60)
		{
			date_ = 1900_y / feb / 29;
		}
		else
		{
			// If serialXLDate is greater than 60, then adjust serial date accordingly
			date_ = (serialDate_ > 60) ? date::year_month_day(minDate_ + date::days(serialDate_ - 2))
									   : date::year_month_day(minDate_ + date::days(serialDate_ - 1));
		}

		return true;
	}

	bool XLDate::dateToSerial_()
	{
		// Check if date is valid
		
		if (date_ == 1900_y / feb / 29)
		{
			serialDate_ = 60;
		}
		else if (!date_.ok() || (year() - 1900) > 199)
		{
			return false;
		}
		else
		{
			// If date is past Feb 29, 1900, add one to serial date value
			serialDate_ = (date_ >= 1900_y / mar / 1) ? date::days(date::sys_days(date_) - minDate_).count() + 2
													  : date::days(date::sys_days(date_) - minDate_).count() + 1;
		}

		return true;
	}

	// This is a 'friend' of the XLDate class
	std::ostream& operator << (std::ostream& os, const XLDate& rhs)
	{
		os /* << "yyyy.mm.dd = " */ << rhs.year() << "." << rhs.month() << "." << rhs.day() << "; Excel serial format = " << rhs.serialDate_;
		return os;
	}
}