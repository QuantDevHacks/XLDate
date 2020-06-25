#include "catch.hpp"
#include "Fcns_Daycounts.h"

using alfinlib2::Date;
using alfinlib2::DayCount;

Date sd1(1973, 10, 26);
Date sd2(2014, 5, 7);
Date sd3(2016, 10, 31);
Date sd4(2015, 2, 28);
Date sd5(2016, 2, 29);
Date sd6(2014, 4, 30);
Date sd7(2016, 2, 29);

Date ed1(1973, 12, 26);
Date ed2(2016, 10, 10);
Date ed3(2017, 4, 30);
Date ed4(2016, 2, 29);
Date ed5(2016, 5, 30);
Date ed6(2016, 5, 30);
Date ed7(2018, 2, 28);

TEST_CASE("Test 30/360 EUR year fractions for new class", "[yearFracThirty360Eur]") {
	CHECK(yearFracThirty360Eur(sd1, ed1) == Approx(0.166667).epsilon(0.001));
	CHECK(yearFracThirty360Eur(sd2, ed2) == Approx(2.425).epsilon(0.001));
	CHECK(yearFracThirty360Eur(sd3, ed3) == Approx(0.5).epsilon(0.001));
	CHECK(yearFracThirty360Eur(sd4, ed4) == Approx(1.002778).epsilon(0.001));
	CHECK(yearFracThirty360Eur(sd5, ed5) == Approx(0.252778).epsilon(0.001));
	CHECK(yearFracThirty360Eur(sd6, ed6) == Approx(2.083333).epsilon(0.001));
	CHECK(yearFracThirty360Eur(sd7, ed7) == Approx(1.997222).epsilon(0.001));
}

TEST_CASE("Test 30/360 US year fractions for new class", "[yearFracThirty360]") {
	REQUIRE(yearFracThirty360(sd1, ed1) == Approx(0.166667).epsilon(0.001));
	REQUIRE(yearFracThirty360(sd2, ed2) == Approx(2.425).epsilon(0.001));
	REQUIRE(yearFracThirty360(sd3, ed3) == Approx(0.5).epsilon(0.001));
	REQUIRE(yearFracThirty360(sd4, ed4) == Approx(1.0).epsilon(0.001));
	REQUIRE(yearFracThirty360(sd5, ed5) == Approx(0.25).epsilon(0.001));
	REQUIRE(yearFracThirty360(sd6, ed6) == Approx(2.083333).epsilon(0.001));
	REQUIRE(yearFracThirty360(sd7, ed7) == Approx(2.0).epsilon(0.001));
}