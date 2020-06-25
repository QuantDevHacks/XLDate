#ifndef TIME_STEP_H
#define TIME_STEP_H
#include <array>

namespace alfinlib
{
	// May want to move this elsewhere.
	// Keep as a traditional enum so that we can use the
	// ordering 0-3 as indices in the member array.
	enum Versary
	{
		ANNIVERSARY,
		SEMIANNIVERSARY,
		QUARTERVERSARY,
		MONTHVERSARY
	};

	class TimeStep
	{
	public:
		TimeStep(double yearFrac1, double yearFrac2,
			bool isAnniv = false, bool isSemiAnniv = false, 
			bool isQtrversary = false, bool isMonthversary = false, bool isStub = false);

		bool isAnniv() const;
		bool isSemiAnniv() const;
		bool isQtrversary() const;
		bool isMonthversary() const;
		bool isStub() const;

		double timeStepLength() const;	// returns time step length
		double operator()() const;		// returns starting time step value (yearFrac1_)

	private:
		double yearFrac1_, yearFrac2_, yfLength_;
		bool isStub_;
		std::array<bool, 4> isVersaries_{false, false, false, false};
	};

};



#endif

