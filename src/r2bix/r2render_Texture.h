#pragma once

#include <string_view>
#include <vector>

#include "r2base_ColorValue.h"
#include "r2render_iRenderTarget.h"

#include "r2/r2_GridIndexConverter.h"
#include "r2/r2_Rect_Int.h"

namespace r2render
{
	class Texture : public iRenderTarget
	{
	public:
		using ValueT = char;
		using ContainerT = std::vector<ValueT>;
		using ConstIteratorT = typename ContainerT::const_iterator;

		using ColorContainerT = std::vector<r2base::ColorValue>;

		explicit Texture( const std::string_view str );
		explicit Texture( const uint32_t width, const std::string_view str );
		explicit Texture( const uint32_t width, const uint32_t height );
		explicit Texture( const uint32_t width, const uint32_t height, const char fill_char );
		explicit Texture( const uint32_t width, const uint32_t height, const std::string_view str );
		explicit Texture( const uint32_t width, const uint32_t height, const char fill_char, const std::string_view str );

	public:
		//
		// Iteration
		//
		ConstIteratorT begin() const { return mChars.begin(); }
		ConstIteratorT end() const { return mChars.end(); }

		//
		// Getter
		//
		int GetWidth() const { return mGridIndexConverter.GetWidth(); }
		int GetHeight() const { return mGridIndexConverter.GetHeight(); }

		int GetXEnd() const { return mGridIndexConverter.GetWidth() - 1; }
		int GetYEnd() const { return mGridIndexConverter.GetHeight() - 1; }

		int GetLength() const { return static_cast<int>( mChars.size() ); }

		const ContainerT& GetContainer() const { return mChars; }
		ValueT Get( const uint32_t x, const uint32_t y ) const;
		std::string_view GetLine( const uint32_t y ) const;

		const ColorContainerT& GetColorContainer() const { return mColors; }
		r2base::ColorValue GetColor( const uint32_t x, const uint32_t y ) const;
		const r2base::ColorValue* GetColorLine( const uint32_t y ) const;

		//
		//
		//
		void Reset( const std::string_view str );
		void Reset( const uint32_t width, const uint32_t height, const char fill_char );


		//
		// Override
		//
		void FillCharacterAll( const char c ) override;
		void FillCharacter( const uint32_t x, const uint32_t y, const char c ) override;
		void FillColorAll( const r2base::ColorValue color_value ) override;
		void FillColor( const uint32_t x, const uint32_t y, const r2base::ColorValue color_value ) override;
		r2::RectInt GetRect() const override { return r2::RectInt( 0, 0, GetWidth(), GetHeight() ); };

	private:
		r2::GridIndexConverter mGridIndexConverter;
		ContainerT mChars;
		ColorContainerT mColors;
	};
}