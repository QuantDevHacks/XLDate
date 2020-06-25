#include "Fcns_Dates.h"
 #include "Date_old.h"


using alfinlib::Date;

int serialDate(const Date& d)
{
	unsigned ret = d();
	return ret;
}

Date fullDate(unsigned u)
{
	Date d(u);
	return d;
}
