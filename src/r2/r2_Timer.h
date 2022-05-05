#pragma once

#include <type_traits>
#include <limits>
#include <algorithm>
#include <cassert>

namespace r2
{
	template<typename T>
	class Timer
	{
	public:
		using ValueT = T;
		const ValueT ValueMAX = std::numeric_limits<ValueT>::max();
		const ValueT ValueZERO = static_cast<ValueT>( 0 );
		const ValueT ValueONE = static_cast<ValueT>( 1 );

		Timer( const ValueT _limitTime, const bool _onTimer = false ) :
			onTimer( _onTimer )
			, mLimitTime( _limitTime )
			, mElapsedTime( ValueZERO )
		{
			static_assert(
				std::is_same<float, T>::value
				|| std::is_same<double, T>::value
				, "r2r::Timer - Not Allowed Type"
			);
		}

		void reset( const bool on_timer = true )
		{
			onTimer = on_timer;
			mElapsedTime = ValueZERO;
		}
		void reset( const ValueT limit_time, const bool on_timer = true )
		{
			mLimitTime = limit_time;
			reset( on_timer );
		}

		bool update( const ValueT dt )
		{
			if( !onTimer )
			{
				return false;
			}

			assert( dt <= ( ValueMAX - mElapsedTime ) );

			mElapsedTime += dt;

			if( mLimitTime <= mElapsedTime )
			{
				onTimer = false;
			}

			return onTimer;
		}

		bool isAlive() const { return onTimer; }
		bool isDie() const { return !onTimer; }
		ValueT getElapsedTime() const { return mElapsedTime; }
		ValueT getLimitTime() const { return mLimitTime; }

		ValueT getElapsedTimeRate() const
		{
			if( mElapsedTime >= mLimitTime )
			{
				return ValueONE;
			}
			else
			{
				return ( ValueZERO >= mLimitTime ? ValueZERO : mElapsedTime / mLimitTime );
			}
		}
		ValueT getElapsedTimeInverseRate() const
		{
			return 1.f - getElapsedTimeRate();
		}

		const ValueT getElapsedTimePureRate() const
		{
			return ( ValueZERO >= mLimitTime ? ValueZERO : mElapsedTime / mLimitTime );
		}

	private:
		bool onTimer;
		ValueT mLimitTime;
		ValueT mElapsedTime;
	};
}
