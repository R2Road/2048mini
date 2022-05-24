#include "Utility4Test.h"

#include <Windows.h>

#include "r2cm/r2cm_constant.h"
#include "r2bix/r2render_TextureFrame.h"

r2cm::eColor Convert_R2bixForegroundColor_to_R2CMColor( r2base::ColorValue color_value )
{
	const auto fgc = r2base::GetForegroundColor( color_value );

	switch( fgc )
	{
	case r2base::eForegroundColor::FG_Black:		return r2cm::eColor::FG_Black;
	case r2base::eForegroundColor::FG_Blue:			return r2cm::eColor::FG_Blue;
	case r2base::eForegroundColor::FG_Green:		return r2cm::eColor::FG_Green;
	case r2base::eForegroundColor::FG_Aqua:			return r2cm::eColor::FG_Aqua;
	case r2base::eForegroundColor::FG_Red:			return r2cm::eColor::FG_Red;
	case r2base::eForegroundColor::FG_Purple:		return r2cm::eColor::FG_Purple;
	case r2base::eForegroundColor::FG_Yellow:		return r2cm::eColor::FG_Yellow;
	case r2base::eForegroundColor::FG_White:		return r2cm::eColor::FG_White;
	case r2base::eForegroundColor::FG_Gray:			return r2cm::eColor::FG_Gray;
	case r2base::eForegroundColor::FG_LightBlue:	return r2cm::eColor::FG_LightBlue;
	case r2base::eForegroundColor::FG_LightGreen:	return r2cm::eColor::FG_LightGreen;
	case r2base::eForegroundColor::FG_LightAqua:	return r2cm::eColor::FG_LightAqua;
	case r2base::eForegroundColor::FG_LightLed:		return r2cm::eColor::FG_LightLed;
	case r2base::eForegroundColor::FG_LightPurple:	return r2cm::eColor::FG_LightPurple;
	case r2base::eForegroundColor::FG_LightYellow:	return r2cm::eColor::FG_LightYellow;
	case r2base::eForegroundColor::FG_BrightWhite:	return r2cm::eColor::FG_BrightWhite;
	}

	return r2cm::eColor::FG_White;
}

r2cm::eColor Convert_R2bixBackgroundColor_to_R2CMColor( r2base::ColorValue color_value )
{
	const auto bgc = r2base::GetBackgroundColor( color_value );

	switch( bgc )
	{
	case r2base::eBackgroundColor::BG_Black:		return r2cm::eColor::BG_Black;
	case r2base::eBackgroundColor::BG_Blue:			return r2cm::eColor::BG_Blue;
	case r2base::eBackgroundColor::BG_Green:		return r2cm::eColor::BG_Green;
	case r2base::eBackgroundColor::BG_Aqua:			return r2cm::eColor::BG_Aqua;
	case r2base::eBackgroundColor::BG_Red:			return r2cm::eColor::BG_Red;
	case r2base::eBackgroundColor::BG_Purple:		return r2cm::eColor::BG_Purple;
	case r2base::eBackgroundColor::BG_Yellow:		return r2cm::eColor::BG_Yellow;
	case r2base::eBackgroundColor::BG_White:		return r2cm::eColor::BG_White;
	case r2base::eBackgroundColor::BG_Gray:			return r2cm::eColor::BG_Gray;
	case r2base::eBackgroundColor::BG_LightBlue:	return r2cm::eColor::BG_LightBlue;
	case r2base::eBackgroundColor::BG_LightGreen:	return r2cm::eColor::BG_LightGreen;
	case r2base::eBackgroundColor::BG_LightAqua:	return r2cm::eColor::BG_LightAqua;
	case r2base::eBackgroundColor::BG_LightLed:		return r2cm::eColor::BG_LightLed;
	case r2base::eBackgroundColor::BG_LightPurple:	return r2cm::eColor::BG_LightPurple;
	case r2base::eBackgroundColor::BG_LightYellow:	return r2cm::eColor::BG_LightYellow;
	case r2base::eBackgroundColor::BG_BrightWhite:	return r2cm::eColor::BG_BrightWhite;
	}

	return r2cm::eColor::FG_White;
}

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
	std::cout << r2cm::tab << "rect min, max :" << " " << rect.GetMinX() << " " << rect.GetMinY() << " " << rect.GetMaxX() << " " << rect.GetMaxY() << r2cm::linefeed;
}

void Utility4Test::DrawTexture( const r2render::Texture& texture )
{
	for( int y = 0; y < texture.GetHeight(); ++y )
	{
		for( int x = 0; x < texture.GetWidth(); ++x )
		{
			std::cout 
				<< r2cm::clm( Convert_R2bixForegroundColor_to_R2CMColor( texture.GetColor( x, y ) ) )
				<< r2cm::clm( Convert_R2bixBackgroundColor_to_R2CMColor( texture.GetColor( x, y ) ) )
				<< texture.Get( x, y )
				<< r2cm::clm();
		}

		std::cout << r2cm::linefeed;
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

		std::cout << r2cm::linefeed;
	}
}