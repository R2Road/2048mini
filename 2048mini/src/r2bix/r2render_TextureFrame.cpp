#include "r2render_TextureFrame.h"

namespace r2render
{
	TextureFrame::TextureFrame( const Texture* const texture ) :
		mTexture( texture )
		, mVisibleRect( 0, 0, texture->GetWidth() - 1, texture->GetHeight() - 1 )
	{}

	Texture::ValueT TextureFrame::Get( const uint32_t x, const uint32_t y ) const
	{
		const auto target_x = x + mVisibleRect.GetOrigin().GetX();
		const auto target_y = y + mVisibleRect.GetOrigin().GetY();

		return mTexture->Get( target_x, target_y );
	}
	r2base::ColorValue TextureFrame::GetColor( const uint32_t x, const uint32_t y ) const
	{
		const auto target_x = x + mVisibleRect.GetOrigin().GetX();
		const auto target_y = y + mVisibleRect.GetOrigin().GetY();

		return mTexture->GetColor( target_x, target_y );
	}
}