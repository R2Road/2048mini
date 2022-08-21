#pragma once

#include <type_traits>

namespace r2
{
	template<typename T>
	class Size
	{
	public:
		using ValueT = T;
		using MyT = Size<ValueT>;

		Size() : mWidth( 0 ), mHeight( 0 )
		{
			static_assert(
				std::is_same<char, ValueT>::value
				|| std::is_same<short, ValueT>::value
				|| std::is_same<int, ValueT>::value
				|| std::is_same<long long int, ValueT>::value
				|| std::is_same<float, ValueT>::value
				|| std::is_same<double, ValueT>::value
				, "r2r::Size - Not Allowed Type"
			);
		}
		Size( const ValueT width, const ValueT height ) : mWidth( width ), mHeight( height )
		{
			static_assert(
				std::is_same<char, ValueT>::value
				|| std::is_same<short, ValueT>::value
				|| std::is_same<int, ValueT>::value
				|| std::is_same<long long int, ValueT>::value
				|| std::is_same<float, ValueT>::value
				|| std::is_same<double, ValueT>::value
				, "r2r::Size - Not Allowed Type"
			);
		}
		Size( const MyT& other ) : mWidth( other.mWidth ), mHeight( other.mHeight )
		{
			static_assert(
				std::is_same<char, ValueT>::value
				|| std::is_same<short, ValueT>::value
				|| std::is_same<int, ValueT>::value
				|| std::is_same<long long int, ValueT>::value
				|| std::is_same<float, ValueT>::value
				|| std::is_same<double, ValueT>::value
				, "r2r::Size - Not Allowed Type"
			);
		}

		static MyT GetZero() { return MyT(); }

		MyT operator+ ( const MyT& _other ) const
		{
			return MyT( mWidth + _other.mWidth, mHeight + _other.mHeight );
		}
		MyT& operator= ( const MyT& other )
		{
			Set( other.mWidth, other.mHeight );
			return *this;
		}
		bool operator== ( const MyT& _other ) const
		{
			return mWidth == _other.mWidth && mHeight == _other.mHeight;
		}
		bool operator!= ( const MyT& _other ) const
		{
			return mWidth != _other.mWidth || mHeight != _other.mHeight;
		}

		bool equals( const MyT& other ) const
		{
			return ( mWidth == other.mWidth ) && ( mHeight == other.mHeight );
		}

		inline void Set( const ValueT width, const ValueT height )
		{
			mWidth = width;
			mHeight = height;
		}
		inline void SetWidth( const ValueT width )
		{
			mWidth = width;
		}
		inline void SetHeight( const ValueT height )
		{
			mHeight = height;
		}
		inline void Add( const ValueT change_w, const ValueT change_h )
		{
			mWidth += change_w;
			mHeight += change_h;
		}

		inline ValueT GetWidth() const
		{
			return mWidth;
		}
		inline ValueT GetHeight() const
		{
			return mHeight;
		}

	private:
		ValueT mWidth;
		ValueT mHeight;
	};
}