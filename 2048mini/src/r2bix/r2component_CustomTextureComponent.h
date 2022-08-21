#pragma once

#include "r2base_Component.h"
#include "r2base_ComponentStaticID.h"

#include "r2render_Texture.h"

namespace r2component
{
	class CustomTextureComponent : public r2base::Component
	{
	private:
		CustomTextureComponent( r2base::Node& owner_node );

	public:
		int GetStaticID() const override { return r2base::ComponentStaticID<CustomTextureComponent>::Get(); }
		static std::unique_ptr<CustomTextureComponent> Create( r2base::Node& owner_node );

		//
		// Getter
		//
		const r2render::Texture* const GetTexture() const
		{
			return &mTexture;
		}
		r2render::Texture* const GetTexture()
		{
			return &mTexture;
		}

	private:
		r2render::Texture mTexture;
	};
}