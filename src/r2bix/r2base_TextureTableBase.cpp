#include "r2base_TextureTableBase.h"

#include "r2render_Texture.h"
#include "r2render_TextureFrame.h"

namespace r2base
{
	TextureTableBase::TextureTableBase() : mTextureContainer()
	{}

	bool TextureTableBase::AddTexture( const char* const key_name, const uint32_t width, const uint32_t height, const char fill_char )
	{
		auto itr = mTextureContainer.find( key_name );
		if( mTextureContainer.end() != itr )
		{
			return false;
		}

		mTextureContainer.emplace( key_name, TextureValueT( new ( std::nothrow ) r2render::Texture( width, height, fill_char ) ) );

		return true;
	}
	bool TextureTableBase::RemoveTexture( const char* const key_name )
	{
		auto itr = mTextureContainer.find( key_name );
		if( mTextureContainer.end() == itr )
		{
			return false;
		}

		mTextureContainer.erase( itr );

		return true;
	}

	r2render::Texture* const TextureTableBase::GetTexture( const char* const key_name ) const
	{
		auto itr = mTextureContainer.find( key_name );
		if( mTextureContainer.end() != itr )
		{
			return itr->second.get();
		}

		static r2render::Texture temp_texture( "Invalid Texture" );
		return &temp_texture;
	}
	r2render::TextureFrame* const TextureTableBase::GetTextureFrame( const char* const key_name ) const
	{
		auto itr = mTextureFrameContainer.find( key_name );
		if( mTextureFrameContainer.end() != itr )
		{
			return itr->second.get();
		}

		static r2render::Texture temp_texture( "Invalid Texture" );
		static r2render::TextureFrame temp_texture_frame( &temp_texture );
		return &temp_texture_frame;
	}
}