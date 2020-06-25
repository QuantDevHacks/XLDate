#include "catch.hpp"
#include "Fcns_Dates.h"
#include "Date_old.h"

using alfinlib::Date;

Date d1(1973, 10, 26);		// 26963
Date d2(2016, 7, 22);		// 42573

TEST_CASE("Test YYYY,MM,DD date format to integer representation", "[serialDate]") {
	CHECK(serialDate(d1) == 26963);
	CHECK(serialDate(d2) == 42573);
}

unsigned u1 = 26963;	// 1973.10.26
unsigned u2 = 42573;	// 2016.07.22

TEST_CASE("Test unsigned integer format to YYYY,MM,DD date representation", "[fullDate]") {
	CHECK(fullDate(u1).year() == 1973);
	CHECK(fullDate(u1).month() == 10);
	CHECK(fullDate(u1).day() == 26);

	CHECK(fullDate(u2).year() == 2016);
	CHECK(fullDate(u2).month() == 7);
	CHECK(fullDate(u2).day() == 22);
}