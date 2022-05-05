#include "pch.h"
#include "r2render_Texture.h"

#include <algorithm>
#include <cassert>

namespace r2render
{
	Texture::Texture( const std::string_view str ) :
		mGridIndexConverter( 1, 1 )
		, mChars()
	{
		Reset( str );
	}
	Texture::Texture( const uint32_t width, const std::string_view str ) :
		mGridIndexConverter( width, static_cast<int>( str.length() < 0 ? 1 : ( str.length() / width ) + ( str.length() % width < 1 ? 0 : 1 ) ) )
		, mChars( mGridIndexConverter.GetWidth() * mGridIndexConverter.GetHeight(), 32 )
	{
		assert( 0u < mGridIndexConverter.GetWidth() && 0u < mGridIndexConverter.GetHeight() );
		memcpy_s( &mChars[0], mChars.size(), str.data(), str.size() );
	}
	Texture::Texture( const uint32_t width, uint32_t height ) :
		mGridIndexConverter( width, height )
		, mChars( width * height, 32 )
	{
		assert( 0u < width && 0u < height );
	}
	Texture::Texture( const uint32_t width, const uint32_t height, const char fill_char ) :
		mGridIndexConverter( 1, 1 )
		, mChars()
	{
		Reset( width, height, fill_char );
	}
	Texture::Texture( const uint32_t width, const uint32_t height, const std::string_view str ) :
		mGridIndexConverter( width, height )
		, mChars( width * height, 32 )
	{
		assert( 0u < width && 0u < height );
		memcpy_s( &mChars[0], mChars.size(), str.data(), std::min( str.size(), mChars.size() ) );
	}
	Texture::Texture( const uint32_t width, uint32_t height, const char fill_char, const std::string_view str ) :
		mGridIndexConverter( width, height )
		, mChars( width * height, fill_char )
	{
		assert( 0u < width && 0u < height );
		memcpy_s( &mChars[0], mChars.size(), str.data(), std::min( str.size(), mChars.size() ) );
	}

	Texture::ValueT Texture::Get( const uint32_t x, const uint32_t y ) const
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		return mChars[target_linear_index];
	}
	std::string_view Texture::GetLine( const uint32_t y ) const
	{
		std::string_view temp( &mChars[0] );
		return temp.substr( mGridIndexConverter.To_Linear( 0, y ), mGridIndexConverter.GetWidth() );
	}

	void Texture::Reset( const std::string_view str )
	{
		assert( 0u < str.length() );

		mGridIndexConverter = r2::GridIndexConverter( static_cast<int>( str.length() ), 1 );
		mChars.clear();
		mChars.resize( mGridIndexConverter.GetWidth() * mGridIndexConverter.GetHeight(), 32 );

		//std::copy( str.begin(), str.end(), mChars.begin() );
		memcpy_s( &mChars[0], mChars.size(), str.data(), str.size() );
	}
	void Texture::Reset( const uint32_t width, const uint32_t height, const char fill_char )
	{
		assert( 0u < width && 0u < height );

		mGridIndexConverter = r2::GridIndexConverter( width, height );
		mChars.clear();
		mChars.resize( mGridIndexConverter.GetWidth() * mGridIndexConverter.GetHeight(), fill_char );
	}

	void Texture::FillAll( const char c )
	{
		memset( &mChars[0], c, mChars.size() );
	}

	void Texture::Fill( const uint32_t x, const uint32_t y, const char c )
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		mChars[target_linear_index] = c;
	}
}