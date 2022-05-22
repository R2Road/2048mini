#pragma once
#include "r2base_ColorValue.h"

namespace r2base
{
	unsigned char GetForegroundColor( const ColorValue color_value )
	{
		static const uint8_t mask = static_cast<uint8_t>( -1 ) >> 4;
		return color_value & mask;
	}
	unsigned char GetBackgroundColor( const ColorValue color_value )
	{
		static const uint8_t mask = ( static_cast<uint8_t>( -1 ) >> 4 ) << 4;
		return color_value & mask;
	}
}