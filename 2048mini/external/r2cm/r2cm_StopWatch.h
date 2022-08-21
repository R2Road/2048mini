#pragma once

#include <chrono>

namespace r2cm
{
	class StopWatch
	{
	public:
		StopWatch();

		void Start();
		void Stop();

		long long GetMilliTime() const;
		long long GetMicroTime() const;
		long long GetNanoTime() const;
		long long GetMaxTime() const { return mMaxTime; }
		long long GetMinTime() const { return mMinTime; }

		void PrintElapsedTime_MilliSeconds();
		void PrintElapsedTime_MicroSeconds();
		void PrintElapsedTime_NanoSeconds();
		void PrintElapsedTime_All();

		void PrintMinAndMaxTime();

	private:
		std::chrono::steady_clock::time_point mStartTime;
		std::chrono::steady_clock::time_point mEndTime;

		long long mMaxTime;
		long long mMinTime;
	};
}
