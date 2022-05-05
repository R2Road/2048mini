#pragma once

#include <chrono>

namespace r2
{
	class FPSTimer
	{
	public:
		FPSTimer( const std::size_t frame_count = 30u );

		void SetFPS( const std::size_t frame_count );
		float GetElapsedTime() const { return mElapsedTime; }

		void Reset();
		bool Update();

	private:
		long long mFPS;
		std::chrono::time_point<std::chrono::system_clock> mPivotTimePoint;
		std::chrono::milliseconds mCurrentTime;
		std::chrono::milliseconds mLastTime;

		float mElapsedTime;
	};
}