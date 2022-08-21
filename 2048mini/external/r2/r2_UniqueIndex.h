#pragma once

namespace r2
{
	template<typename T, typename Index_T = unsigned long long, Index_T Start_Value = 1, Index_T Invalid_Value = 0>
	class UniqueIndex
	{
	private:
		using OwnerT = T;

	public:
		using MyT = UniqueIndex<T>;
		using ValueT = Index_T;

		explicit UniqueIndex() : mIndex( getNewIndex() ) {}

		bool operator==( const MyT& rhs ) const
		{
			return rhs.isEqual( Get() );
		}
		bool operator!=( const MyT& rhs ) const
		{
			return !rhs.isEqual( Get() );
		}

		ValueT Get() const
		{
			return mIndex;
		}

	private:
		bool isEqual( const ValueT& other_Index ) const
		{
			return Get() == other_Index;
		}

		static ValueT getNewIndex()
		{
			static ValueT temp_index = Start_Value;
			return temp_index++;
		}

	public:
		static ValueT GetInvalidIndex()
		{
			static const ValueT invalid_index = Invalid_Value; // 0 is invalid
			return invalid_index;
		}

	private:
		const ValueT mIndex;
	};
}
