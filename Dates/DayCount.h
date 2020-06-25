#ifndef DAY_COUNT_H
#define DAY_COUNT_H

#include "XLDate.h"

namespace Dates
{
	class DayCount
	{
	public:
		// The operator should just call the member function yearFraction(.)
		virtual double operator() (const Dates::XLDate& date1, const Dates::XLDate& date2) const = 0;
		virtual double yearFraction(const Dates::XLDate& date1, const Dates::XLDate& date2) const = 0;
		virtual ~DayCount() {};
	};

	class Thirty360 : public DayCount
	{
	public:
		virtual double operator() (const Dates::XLDate& date1, const Dates::XLDate& date2) const;
		virtual double yearFraction(const Dates::XLDate& date1, const Dates::XLDate& date2) const;

	private:
		// Maybe we should make this public and virtual on all derived classes (?)
		unsigned dateDiff_(const Dates::XLDate& date1, const Dates::XLDate& date2) const;
	};

	class Thirty360Eur : public DayCount
	{
	public:
		virtual double operator() (const Dates::XLDate& date1, const Dates::XLDate& date2) const;
		virtual double yearFraction(const Dates::XLDate& date1, const Dates::XLDate& date2) const;

	private:
		// Maybe we should make this public and virtual on all derived classes (?)
		unsigned dateDiff_(const Dates::XLDate& date1, const Dates::XLDate& date2) const;
	};

	class Act365 : public DayCount
	{
	public:
		virtual double operator() (const Dates::XLDate& date1, const Dates::XLDate& date2) const;
		virtual double yearFraction(const Dates::XLDate& date1, const Dates::XLDate& date2) const;
	};

	class Act360 : public DayCount
	{
	public:
		virtual double operator() (const Dates::XLDate& date1, const Dates::XLDate& date2) const;
		virtual double yearFraction(const Dates::XLDate& date1, const Dates::XLDate& date2) const;
	};
};

#endif