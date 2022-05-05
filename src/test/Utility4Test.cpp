#include "pch.h"
#include "Utility4Test.h"

#include <Windows.h>

#include "r2bix/r2render_TextureFrame.h"

void Utility4Test::DrawRect( const int offset_y, const r2::RectInt& rect, const char c )
{
	HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );

	for( int y = rect.GetMinY(); rect.GetMaxY() >= y; ++y )
	{
		for( int x = rect.GetMinX(); rect.GetMaxX() >= x; ++x )
		{
			SetConsoleCursorPosition( stdHandle, { static_cast<short>( x ), static_cast<short>( offset_y + y ) } );

			std::cout << c;
		}
	}
}

void Utility4Test::DrawRectInfo_Min_Max( const r2::RectInt& rect )
{
	std::cout << r2::tab << "rect min, max :" << " " << rect.GetMinX() << " " << rect.GetMinY() << " " << rect.GetMaxX() << " " << rect.GetMaxY() << r2::linefeed;
}

void Utility4Test::DrawTexture( const r2render::Texture& texture )
{
	std::size_t x = 0;
	for( const char element : texture )
	{
		std::cout << element;

		++x;
		if( texture.GetWidth() <= x )
		{
			x = 0u;
			std::cout << r2::linefeed;
		}
	}
	if( 0u != x )
	{
		std::cout << r2::linefeed;
	}
}
void Utility4Test::DrawTextureFrame( const r2render::TextureFrame& frame )
{
	for( int y = 0; y < frame.GetHeight(); ++y )
	{
		for( int x = 0; x < frame.GetWidth(); ++x )
		{
			std::cout << frame.Get( x, y );
		}

		std::cout << r2::linefeed;
	}
}