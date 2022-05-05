#include "pch.h"
#include "p2048mini_Stage.h"

#include <algorithm>

#include "r2/r2_Point_Int.h"

namespace p2048mini
{
	Stage::Stage( const uint32_t width, const uint32_t height ) :
		mGridIndexConverter( width, height )
		, mContainer( width * height )
		, mCurrentNumberCount( 0 )
	{}

	bool Stage::IsIn( const int32_t x, const int32_t y ) const
	{
		return ( 0 <= x && 0 <= y && static_cast<int>( GetWidth() ) > x && static_cast<int>( GetHeight() ) > y );
	}

	const Stage::Cell Stage::Get( const uint32_t linear_index ) const
	{
		return mContainer[linear_index];
	}
	Stage::Cell& Stage::Get( const uint32_t linear_index )
	{
		return mContainer[linear_index];
	}

	uint32_t Stage::GetNumber( const uint32_t linear_index ) const
	{
		return Get( linear_index ).number;
	}
	uint32_t Stage::GetNumber( const uint32_t x, const uint32_t y ) const
	{
		return GetNumber( mGridIndexConverter.To_Linear( x, y ) );
	}
	bool Stage::IsLock( const uint32_t x, const uint32_t y ) const
	{
		return Get( mGridIndexConverter.To_Linear( x, y ) ).merge_lock;
	}

	void Stage::ClearAll()
	{
		mCurrentNumberCount = 0;
		for( auto& cell : mContainer )
		{
			cell.number = 0;
			cell.merge_lock = false;
		}
	}

	void Stage::Add( const uint32_t linear_index, const uint32_t val )
	{
		if( 0 == Get( linear_index ).number )
		{
			++mCurrentNumberCount;
		}

		Get( linear_index ).number = val;
	}
	void Stage::Add( const uint32_t x, const uint32_t y, const uint32_t val )
	{
		Add( mGridIndexConverter.To_Linear( x, y ), val );
	}

	void Stage::Remove( const uint32_t x, const uint32_t y )
	{
		const int linear_index = mGridIndexConverter.To_Linear( x, y );
		if( 0 == Get( linear_index ).number )
		{
			return;
		}

		--mCurrentNumberCount;
		Get( linear_index ).number = 0;
	}

	void Stage::ClearAllLocks()
	{
		for( auto& cell : mContainer )
		{
			cell.merge_lock = false;
		}
	}
	void Stage::Lock( const uint32_t x, const uint32_t y )
	{
		Get( mGridIndexConverter.To_Linear( x, y ) ).merge_lock = true;
	}
}