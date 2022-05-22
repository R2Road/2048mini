#pragma once

#include "r2render_Texture.h"

namespace r2render
{
	class TextureFrame
	{
	public:
		explicit TextureFrame( const Texture* const texture );

		//
		//
		//
		int GetWidth() const { return mVisibleRect.GetWidth(); }
		int GetHeight() const { return mVisibleRect.GetHeight(); }

		int GetMinX() const { return mVisibleRect.GetMinX(); }
		int GetMinY() const { return mVisibleRect.GetMinY(); }
		int GetMaxX() const { return mVisibleRect.GetMaxX(); }
		int GetMaxY() const { return mVisibleRect.GetMaxY(); }

		const r2::RectInt& GetVisibleRect() const { return mVisibleRect; }
		Texture::ValueT Get( const uint32_t x, const uint32_t y ) const;
		r2base::ColorValue GetColor( const uint32_t x, const uint32_t y ) const;

		//
		//
		//
		void SetVisibleRect( const r2::RectInt& rect ) { mVisibleRect = rect; }
		void SetVisibleRect( const int min_x, const int min_y, const int max_x, const int max_y ) { mVisibleRect.Set( min_x, min_y, max_x - min_x, max_y - min_y ); }
		void MoveVisibleOrigin( const int mx, const int my ) { mVisibleRect.MoveOrigin( mx, my ); }
		void MoveVisibleOrigin( const r2::PointInt& point ) { mVisibleRect.MoveOrigin( point.GetX(), point.GetY() ); }
		void ChangeVisibleSize( const int change_width, const int change_height ) { mVisibleRect.ChangeSize( change_width, change_height ); }

	private:
		const Texture* const mTexture;
		r2::RectInt mVisibleRect;
	};
}