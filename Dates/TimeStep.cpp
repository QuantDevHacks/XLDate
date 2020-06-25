#include "TimeStep.h"
#include <stdexcept>
using std::array;
using std::invalid_argument;

namespace alfinlib
{
	TimeStep::TimeStep(double yearFrac1, double yearFrac2,
		bool isAnniv, bool isSemiAnniv,
		bool isQtrversary, bool isMonthversary, bool isStub) :yearFrac1_(yearFrac1), yearFrac2_(yearFrac2),
		yfLength_(yearFrac2 - yearFrac1), isStub_(isStub)
	{
		if (yearFrac2 < yearFrac1)
		{
			invalid_argument e("TimeStep::TimeStep(.): yearFrac2 < yearFrac1 is invalid");
			throw e;
		}

		// Cannot initialise; must assign in body of ctor:
		isVersaries_[ANNIVERSARY] = isAnniv;
		isVersaries_[SEMIANNIVERSARY] = isSemiAnniv;
		isVersaries_[QUARTERVERSARY] = isQtrversary;
		isVersaries_[MONTHVERSARY] = isMonthversary;
	}

	bool TimeStep::isAnniv() const
	{
		return isVersaries_[ANNIVERSARY];
	}

	bool TimeStep::isSemiAnniv() const
	{
		return isVersaries_[SEMIANNIVERSARY];
	}

	bool TimeStep::isQtrversary() const
	{
		return isVersaries_[QUARTERVERSARY];
	}

	bool TimeStep::isMonthversary() const
	{
		return isVersaries_[MONTHVERSARY];
	}

	bool TimeStep::isStub() const
	{
		return isStub_;
	}

	// Deprecate this:
	double TimeStep::timeStepLength() const
	{
		return yfLength_;
	}

	double TimeStep::operator()() const
	{
		return yearFrac1_;
	}
}