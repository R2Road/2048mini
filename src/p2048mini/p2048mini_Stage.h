#pragma once

#include <vector>

#include "r2/r2_Direction4.h"
#include "r2/r2_GridIndexConverter.h"

namespace p2048mini
{
	class Stage
	{
	public:
		struct Cell
		{
			uint32_t number = 0;
			bool merge_lock = false;
		};
		using ContainerT = std::vector<Cell>;
		using ConstIteratorT = typename ContainerT::const_iterator;

		Stage( const uint32_t width, const uint32_t height );

		//
		// Iteration
		//
		ConstIteratorT begin() const { return mContainer.begin(); }
		ConstIteratorT end() const { return mContainer.end(); }

		//
		// Getter
		//
		uint32_t GetWidth() const { return mGridIndexConverter.GetWidth(); }
		uint32_t GetHeight() const { return mGridIndexConverter.GetHeight(); }
		uint32_t GetMaxX() const { return mGridIndexConverter.GetWidth() - 1; }
		uint32_t GetMaxY() const { return mGridIndexConverter.GetHeight() - 1; }
		uint32_t Size() const { return static_cast<uint32_t>( mContainer.size() ); }
		bool IsIn( const int32_t x, const int32_t y ) const;

	private:
		const Cell Get( const uint32_t linear_index ) const;
		Cell& Get( const uint32_t linear_index );
	public:
		uint32_t GetNumber( const uint32_t linear_index ) const;
		uint32_t GetNumber( const uint32_t x, const uint32_t y ) const;
		int32_t GetCurrentNumberCount() const { return mCurrentNumberCount; }
		int32_t GetEmptySpaceCount() const { return static_cast<int32_t>( mContainer.size() ) - GetCurrentNumberCount(); }
		bool IsFull() const { return mContainer.size() == mCurrentNumberCount; }
		bool IsLock( const uint32_t x, const uint32_t y ) const;

		//
		//
		//
		void ClearAll();
		void Add( const uint32_t linear_index, const uint32_t val );
		void Add( const uint32_t x, const uint32_t y, const uint32_t val );
		void Remove( const uint32_t x, const uint32_t y );
		void ClearAllLocks();
		void Lock( const uint32_t x, const uint32_t y );

	private:
		r2::GridIndexConverter mGridIndexConverter;
		ContainerT mContainer;
		int32_t mCurrentNumberCount;
	};
}