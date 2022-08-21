#pragma once

#include <stdint.h>

#include "r2/r2_Rect_Int.h"
#include "r2base_ColorValue.h"

namespace r2render
{
	class iRenderTarget
	{
	public:
		virtual void FillCharacterAll( const char c ) = 0;
		virtual void FillCharacter( const uint32_t x, const uint32_t y, const char c ) = 0;
		virtual void FillColorAll( const r2base::ColorValue color_value ) = 0;
		virtual void FillColor( const uint32_t x, const uint32_t y, const r2base::ColorValue color_value ) = 0;

		virtual r2::RectInt GetRect() const = 0;
	};
}