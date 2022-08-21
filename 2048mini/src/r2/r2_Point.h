#pragma once

#include <algorithm>
#include <cmath>

namespace r2
{
	template<typename T>
	class Point
	{
	public:
		using ValueT = T;
		using MyT = Point<T>;

		static const MyT& GetZERO()
		{
			static const MyT ZERO( 0, 0 );
			return ZERO;
		}
		static const MyT& GetMINUS_ONE()
		{
			static const MyT MINUS_ONE( -1, -1 );
			return MINUS_ONE;
		}

		Point() : mX( 0 ), mY( 0 )
		{
			static_assert(
				std::is_same<int, ValueT>::value
				|| std::is_same<float, ValueT>::value
				, "r2r::Point - Not Allowed Type"
			);
		}
		Point( const ValueT x, const ValueT y ) : mX( x ), mY( y )
		{
			static_assert(
				std::is_same<int, ValueT>::value
				|| std::is_same<float, ValueT>::value
				, "r2r::Point - Not Allowed Type"
			);
		}

		bool operator==( const MyT& right ) const
		{
			return right.mX == mX && right.mY == mY;
		}
		bool operator!=( const MyT& right ) const
		{
			return !( *this == right );
		}
		bool operator<( const MyT& right ) const
		{
			return ( mY < right.mY )
				? true
				: ( mY == right.mY ? mX < right.mX : false );
		}
		MyT operator-( const MyT& right ) const
		{
			return MyT( mX - right.mX, mY - right.mY );
		}
		MyT operator+( const MyT& right ) const
		{
			return MyT( mX + right.mX, mY + right.mY );
		}
		MyT operator+=( const MyT& right )
		{
			mX += right.mX;
			mY += right.mY;
			return *this;
		}
		MyT operator-=( const MyT& right )
		{
			mX -= right.mX;
			mY -= right.mY;
			return *this;
		}

		inline void SetZero()
		{
			mX = MyT::GetZERO().mX;
			mY = MyT::GetZERO().mY;
		}
		inline void SetMIinusOne()
		{
			mX = MyT::GetMINUS_ONE().mX;
			mY = MyT::GetMINUS_ONE().mY;
		}
		inline void Set( const ValueT x, const ValueT y )
		{
			mX = x;
			mY = y;
		}
		inline void SetX( const ValueT x ) { mX = x; }
		inline void SetY( const ValueT y ) { mY = y; }
		inline void Add( const ValueT add_x, const ValueT add_y )
		{
			mX += add_x;
			mY += add_y;
		}

		inline ValueT GetX() const { return mX; }
		inline ValueT GetY() const { return mY; }

		inline bool Equals( const MyT& point ) const
		{
			return point.mX == mX && point.mY == mY;
		}
		inline ValueT Distance( const MyT& target ) const
		{
			return Distance( target.mX, target.mY );
		}
		inline ValueT Distance( const ValueT x, const ValueT y ) const
		{
			return std::abs( mX - x ) + std::abs( mY - y );
		}
		inline ValueT Distance_DiagonalIsOne( const MyT& target ) const
		{
			const ValueT tempX = std::abs( mX - target.mX );
			const ValueT tempY = std::abs( mY - target.mY );
			return (
				tempX >= tempY
				? ( tempX + tempY ) - tempY
				: ( tempX + tempY ) - tempX
			);
		}

		inline ValueT Length() const
		{
			return std::abs( mX ) + std::abs( mY );
		}

	private:
		ValueT mX;
		ValueT mY;
	};
}