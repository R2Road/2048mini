#pragma once

#include "r2/r2_Point_Int.h"

namespace r2
{
	class GridIndexConverter
	{
	public:
		GridIndexConverter( const int width, const int height );

		int GetWidth() const { return mWidth; }
		int GetHeight() const { return mHeight; }
		int GetLinerEnd() const { return mLinearEnd; }

		r2::PointInt To_Point( const int linear_index ) const;
		int To_Linear( const r2::PointInt point_index ) const;
		int To_Linear( const int x, const int y ) const;

	private:
		int mWidth;
		int mHeight;
		int mLinearEnd;	
	};
}
