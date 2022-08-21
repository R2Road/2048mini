#include "r2cm_StopWatch.h"

#include <numeric>

#include "r2cm/r2cm_ostream.h"

namespace r2cm
{
	StopWatch::StopWatch() :
		mStartTime( std::chrono::nanoseconds::duration( 0 ) )
		, mEndTime( std::chrono::nanoseconds::duration( 0 ) )

		, mMaxTime( 0ll )
		, mMinTime( std::numeric_limits<long long>::max() )
	{}

	void StopWatch::Start()
	{
		mEndTime = mStartTime = std::chrono::high_resolution_clock::now();
	}
	void StopWatch::Stop()
	{
		mEndTime = std::chrono::high_resolution_clock::now();

		const auto current_time = std::chrono::duration_cast<std::chrono::nanoseconds>( mEndTime - mStartTime ).count();
		if( current_time > mMaxTime )
		{
			mMaxTime = current_time;
		}
		if( current_time < mMinTime )
		{
			mMinTime = current_time;
		}
	}

	long long StopWatch::GetMilliTime() const
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>( mEndTime - mStartTime ).count();
	}
	long long StopWatch::GetMicroTime() const
	{
		return std::chrono::duration_cast<std::chrono::microseconds>( mEndTime - mStartTime ).count();
	}
	long long StopWatch::GetNanoTime() const
	{
		return std::chrono::duration_cast<std::chrono::nanoseconds>( mEndTime - mStartTime ).count();
	}

	void StopWatch::PrintElapsedTime_MilliSeconds()
	{
		std::cout << GetMilliTime() << "ms";
	}
	void StopWatch::PrintElapsedTime_MicroSeconds()
	{
		std::cout << GetMicroTime() << "¥ìs";
	}
	void StopWatch::PrintElapsedTime_NanoSeconds()
	{
		std::cout << GetNanoTime() << "ns";
	}
	void StopWatch::PrintElapsedTime_All()
	{
		PrintElapsedTime_MilliSeconds();
		std::cout << r2cm::tab;
		PrintElapsedTime_MicroSeconds();
		std::cout << r2cm::tab;
		PrintElapsedTime_NanoSeconds();
	}

	void StopWatch::PrintMinAndMaxTime()
	{
		std::cout << "Min : " << mMinTime << "ns";
		std::cout << r2cm::tab;
		std::cout << "Max : " << mMaxTime << "ns";
	}
}