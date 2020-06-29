#include "catch.hpp"
#include "../Dates/XLDate.h"
#include "../Dates/DayCount.h"
#include "../Dates/date.h"
#include <stdexcept>

using Dates::XLDate;

XLDate sd1(1973, 10, 26);
XLDate sd2(2014, 5, 7);
XLDate sd3(2016, 10, 31);
XLDate sd4(2015, 2, 28);
XLDate sd5(2016, 2, 29);
XLDate sd6(2014, 4, 30);
XLDate sd7(2016, 2, 29);

XLDate ed1(1973, 12, 26);
XLDate ed2(2016, 10, 10);
XLDate ed3(2017, 4, 30);
XLDate ed4(2016, 2, 29);
XLDate ed5(2016, 5, 30);
XLDate ed6(2016, 5, 30);
XLDate ed7(2018, 2, 28);

Dates::Thirty360Eur TestThirty360Eur;
Dates::Thirty360 TestThirty360;
Dates::Act360 TestAct360;
Dates::Act365 TestAct365;

TEST_CASE("Test 30/360 EUR year fractions for new class", "[Dates::Thirty360Eur]") {
	CHECK(TestThirty360Eur.yearFraction(sd1, ed1) == Approx(0.166667).epsilon(0.001));
	CHECK(TestThirty360Eur.yearFraction(sd2, ed2) == Approx(2.425).epsilon(0.001));
	CHECK(TestThirty360Eur.yearFraction(sd3, ed3) == Approx(0.5).epsilon(0.001));
	CHECK(TestThirty360Eur.yearFraction(sd4, ed4) == Approx(1.002778).epsilon(0.001));
	CHECK(TestThirty360Eur.yearFraction(sd5, ed5) == Approx(0.252778).epsilon(0.001));
	CHECK(TestThirty360Eur.yearFraction(sd6, ed6) == Approx(2.083333).epsilon(0.001));
	CHECK(TestThirty360Eur.yearFraction(sd7, ed7) == Approx(1.997222).epsilon(0.001));
}

TEST_CASE("Test 30/360 year fractions for new class", "[Dates::Thirty360]") {
	REQUIRE(TestThirty360.yearFraction(sd1, ed1) == Approx(0.166667).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd2, ed2) == Approx(2.425).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd3, ed3) == Approx(0.5).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd4, ed4) == Approx(1.0).epsilon(0.001)); 
	// Should be 1.002778. There should be 361 days in between. The original Test case is based on 30/360 US
	REQUIRE(TestThirty360.yearFraction(sd5, ed5) == Approx(0.25).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd6, ed6) == Approx(2.083333).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd7, ed7) == Approx(2.0).epsilon(0.001));
}

TEST_CASE("Test Act360 year fractions for new class", "[Dates::Act360]") {
	CHECK(TestAct360.yearFraction(sd1, ed1) == Approx(0.1694444).epsilon(0.001));
	CHECK(TestAct360.yearFraction(sd2, ed2) == Approx(2.463889).epsilon(0.001));
	CHECK(TestAct360.yearFraction(sd3, ed3) == Approx(0.502778).epsilon(0.001));
	CHECK(TestAct360.yearFraction(sd4, ed4) == Approx(1.016667).epsilon(0.001));
	CHECK(TestAct360.yearFraction(sd5, ed5) == Approx(0.252778).epsilon(0.001));
	CHECK(TestAct360.yearFraction(sd6, ed6) == Approx(2.113889).epsilon(0.001));
	CHECK(TestAct360.yearFraction(sd7, ed7) == Approx(2.027778).epsilon(0.001));
}

TEST_CASE("Test Act365 year fractions for new class", "[Dates::Act365]") {
	CHECK(TestAct365.yearFraction(sd1, ed1) == Approx(0.167123288).epsilon(0.001));
	CHECK(TestAct365.yearFraction(sd2, ed2) == Approx(2.430136986).epsilon(0.001));
	CHECK(TestAct365.yearFraction(sd3, ed3) == Approx(0.495890411).epsilon(0.001));
	CHECK(TestAct365.yearFraction(sd4, ed4) == Approx(1.002739726).epsilon(0.001));
	CHECK(TestAct365.yearFraction(sd5, ed5) == Approx(0.249315068).epsilon(0.001));
	CHECK(TestAct365.yearFraction(sd6, ed6) == Approx(2.084931507).epsilon(0.001));
	CHECK(TestAct365.yearFraction(sd7, ed7) == Approx(2).epsilon(0.001));
}