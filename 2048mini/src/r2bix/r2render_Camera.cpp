#include "r2render_Camera.h"

namespace r2render
{
	Camera::Camera( const r2::RectInt::MyPointT& position, const r2::RectInt::MySizeT& size ) :
		mPosition( position )
		, mCameraSpaceRect()
		, mWorldSpaceRect()
	{
		buildRect( mPosition, { size.GetWidth() - 1, size.GetHeight() - 1 } );
	}

	void Camera::SetPoint( const r2::RectInt::MyPointT& point )
	{
		mPosition = point;

		buildRect( mPosition, mWorldSpaceRect.GetSize() );
	}
	void Camera::SetPoint( const int x, const int y )
	{
		mPosition.Set( x, y );

		buildRect( mPosition, mWorldSpaceRect.GetSize() );
	}

	void Camera::buildRect( const r2::RectInt::MyPointT& position, const r2::RectInt::MySizeT& size )
	{
		const int half_width = size.GetWidth() / 2;
		const int half_height = size.GetHeight() / 2;

		mCameraSpaceRect.Set( -half_width, -half_height, size.GetWidth(), size.GetHeight() );

		const int min_x = position.GetX() - half_width;
		const int min_y = position.GetY() - half_height;
		mWorldSpaceRect.Set( min_x, min_y, size.GetWidth(), size.GetHeight() );
	}
}