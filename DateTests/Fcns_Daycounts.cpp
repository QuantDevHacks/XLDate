#include "Fcns_Daycounts.h"

using alfinlib2::Thirty360;
using alfinlib2::Thirty360Eur;

/*
unsigned yearFracThirty360(const alfinlib::Date& date1, const alfinlib::Date& date2);
unsigned yearFracThirty360Eur(const alfinlib::Date& date1, const alfinlib::Date& date2);
*/

// Note: also need to test yearFraction(.) method separately.
double yearFracThirty360(const Date& date1, const Date& date2)
{
	Thirty360 dc360;
	return dc360(date1, date2);
}

double yearFracThirty360Eur(const Date& date1, const Date& date2)
{
	Thirty360Eur dc360Eur;
	return dc360Eur(date1, date2);
}