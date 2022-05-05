#pragma once

#include "r2/r2_Rect_Int.h"

namespace r2render
{
	class Camera
	{
	public:
		Camera( const r2::RectInt::MyPointT& position, const r2::RectInt::MySizeT& size );

		//
		// Getter
		//
		int GetX() const
		{
			return mPosition.GetX();
		}
		int GetY() const
		{
			return mPosition.GetY();
		}
		r2::RectInt::MyPointT GetPoint() const
		{
			return mPosition;
		}
		r2::RectInt::MySizeT::ValueT GetWidth() const
		{
			return mCameraSpaceRect.GetWidth();
		}
		r2::RectInt::MySizeT::ValueT GetHeight() const
		{
			return mCameraSpaceRect.GetHeight();
		}
		r2::RectInt GetCameraSpaceRect() const
		{
			return mCameraSpaceRect;
		}
		r2::RectInt GetRect() const
		{
			return mWorldSpaceRect;
		}

		//
		// Setter
		//
		void SetPoint( const r2::RectInt::MyPointT& point );
		void SetPoint( const int x, const int y );

	private:
		void buildRect( const r2::RectInt::MyPointT& position, const r2::RectInt::MySizeT& size );

	private:
		r2::RectInt::MyPointT mPosition;
		r2::RectInt mCameraSpaceRect;
		r2::RectInt mWorldSpaceRect;
	};
}