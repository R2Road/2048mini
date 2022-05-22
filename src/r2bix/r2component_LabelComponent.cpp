#include "r2component_LabelComponent.h"

#include "r2component_CustomTextureComponent.h"
#include "r2component_TextureRenderComponent.h"

namespace r2component
{
	LabelComponent::LabelComponent( r2base::Node& owner_node ) : r2base::Component( owner_node )
		, mCustomTextureComponent( nullptr )
		, mTextureRenderComponent( nullptr )
		, mColorValue( r2base::eForegroundColor::FG_White | r2base::eBackgroundColor::BG_Black )
	{}

	std::unique_ptr<LabelComponent> LabelComponent::Create( r2base::Node& owner_node )
	{
		std::unique_ptr<LabelComponent> ret( new ( std::nothrow ) LabelComponent( owner_node ) );
		if( !ret || !ret->Init() )
		{
			ret.reset();
		}

		return ret;
	}

	void LabelComponent::SetString( const std::string_view str )
	{
		if( mText == str )
		{
			return;
		}

		mText = str;

		if( mCustomTextureComponent )
		{
			mCustomTextureComponent->GetTexture()->Reset( str );
			mCustomTextureComponent->GetTexture()->FillColorAll( mColorValue );
		}

		if( mTextureRenderComponent )
		{
			mTextureRenderComponent->ResetVisibleRect();
		}
	}
	void LabelComponent::SetColor( const r2base::ColorValue color_value )
	{
		if( color_value == mColorValue )
		{
			return;
		}

		mColorValue = color_value;

		if( mCustomTextureComponent )
		{
			mCustomTextureComponent->GetTexture()->FillColorAll( mColorValue );
		}
	}
}