#include "catch2/catch.hpp"
#include "XLDate.h"
#include <stdexcept>

using Dates::XLDate;

XLDate d1(1973, 10, 26);		// 26963
XLDate d2(2016, 7, 22);		// 42573

TEST_CASE("Test YYYY,MM,DD date format to integer representation", "[serialDate]") {
	CHECK(d1.serialDate() == 26963);
	CHECK(d2.serialDate() == 42573);
}

XLDate u1(26963);	// 1973.10.26
XLDate u2(42573);	// 2016.07.22

TEST_CASE("Test unsigned integer format to YYYY,MM,DD date representation", "[fullDate]") {
	CHECK(u1.year() == 1973);
	CHECK(u1.month() == 10);
	CHECK(u1.day() == 26);

	CHECK(u2.year() == 2016);
	CHECK(u2.month() == 7);
	CHECK(u2.day() == 22);
}