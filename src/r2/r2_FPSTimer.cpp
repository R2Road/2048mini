#include "pch.h"
#include "r2_FPSTimer.h"

#include <cassert>

namespace r2
{
	FPSTimer::FPSTimer( const std::size_t frame_count ) :
		mFPS( 0ll )
		, mPivotTimePoint()
		, mCurrentTime()
		, mLastTime()

		, mElapsedTime( 0.f )
	{
		SetFPS( frame_count );
	}

	void FPSTimer::SetFPS( const std::size_t frame_count )
	{
		assert( 0 < frame_count );

		mFPS = 1000 / frame_count;
		mElapsedTime = 1.f / frame_count;
	}

	void FPSTimer::Reset()
	{
		mPivotTimePoint = std::chrono::system_clock::now();
		mCurrentTime = std::chrono::duration_cast<std::chrono::milliseconds>( mPivotTimePoint - mPivotTimePoint );
		mLastTime = mCurrentTime;
	}
	bool FPSTimer::Update()
	{
		mCurrentTime = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::system_clock::now() - mPivotTimePoint );
		if( mFPS > ( mCurrentTime.count() - mLastTime.count() ) )
		{
			return false;
		}

		mLastTime = mCurrentTime;

		return true;
	}
}