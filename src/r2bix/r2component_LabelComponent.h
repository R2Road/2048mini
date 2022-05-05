#pragma once

#include <string>
#include <string_view>

#include "r2base_Component.h"
#include "r2base_ComponentStaticID.h"

#include "r2render_Texture.h"

namespace r2render
{
	class Texture;
}

namespace r2component
{
	class CustomTextureComponent;
	class TextureRenderComponent;

	class LabelComponent : public r2base::Component
	{
	private:
		LabelComponent( r2base::Node& owner_node );

	public:
		int GetStaticID() const override { return r2base::ComponentStaticID<LabelComponent>::Get(); }
		static std::unique_ptr<LabelComponent> Create( r2base::Node& owner_node );

		//
		//
		//
		CustomTextureComponent* const GetCustomTextureComponent() const { return mCustomTextureComponent; }
		TextureRenderComponent* const GetTextureRenderComponent() const { return mTextureRenderComponent; }
		std::string_view GetString() const { return mText; }
		int32_t GetWidth() const { return static_cast<int32_t>( mText.length() ); }

		//
		// Setter
		//
		void SetCustomTextureComponent( CustomTextureComponent* const custom_texture_component )
		{
			mCustomTextureComponent = custom_texture_component;
		}
		void SetTextureRenderComponent(	TextureRenderComponent* const texture_render_component )
		{
			mTextureRenderComponent = texture_render_component;
		}
		void SetString( const std::string_view str );

	private:
		std::string mText;
		CustomTextureComponent* mCustomTextureComponent;
		TextureRenderComponent* mTextureRenderComponent;
	};
}