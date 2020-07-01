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
XLDate sd8(2006, 1, 31);
XLDate sd9(2006, 1, 30);
XLDate sd10(2006, 2, 28);
XLDate sd11(2006, 2, 14);
XLDate sd12(2006, 9, 30);
XLDate sd13(2006, 10, 31);
XLDate sd14(2007, 8, 31);
XLDate sd15(2008, 2, 28);
XLDate sd16(2008, 2, 28);
XLDate sd17(2008, 2, 28);
XLDate sd18(2007, 2, 26);
XLDate sd19(2007, 2, 26);
XLDate sd20(2008, 2, 29);
XLDate sd21(2008, 2, 28);
XLDate sd22(2008, 2, 28);

XLDate ed1(1973, 12, 26);
XLDate ed2(2016, 10, 10);
XLDate ed3(2017, 4, 30);
XLDate ed4(2016, 2, 29);
XLDate ed5(2016, 5, 30);
XLDate ed6(2016, 5, 30);
XLDate ed7(2018, 2, 28);
XLDate ed8(2006, 2, 28);
XLDate ed9(2006, 2, 28);
XLDate ed10(2006, 3, 3);
XLDate ed11(2006, 2, 28);
XLDate ed12(2006, 10, 31);
XLDate ed13(2006, 11, 28);
XLDate ed14(2008, 2, 28);
XLDate ed15(2008, 8, 28);
XLDate ed16(2008, 8, 30);
XLDate ed17(2008, 8, 31);
XLDate ed18(2008, 2, 28);
XLDate ed19(2008, 2, 29);
XLDate ed20(2009, 2, 28);
XLDate ed21(2008, 3, 30);
XLDate ed22(2008, 3, 31);


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
	REQUIRE(TestThirty360.yearFraction(sd8, ed8) == Approx(28.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd9, ed9) == Approx(28.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd10, ed10) == Approx(5.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd11, ed11) == Approx(14.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd12, ed12) == Approx(30.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd13, ed13) == Approx(28.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd14, ed14) == Approx(178.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd15, ed15) == Approx(180.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd16, ed16) == Approx(182.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd17, ed17) == Approx(183.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd18, ed18) == Approx(362.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd19, ed19) == Approx(363.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd20, ed20) == Approx(359.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd21, ed21) == Approx(32.0 / 360).epsilon(0.001));
	REQUIRE(TestThirty360.yearFraction(sd22, ed22) == Approx(33.0 / 360).epsilon(0.001));
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