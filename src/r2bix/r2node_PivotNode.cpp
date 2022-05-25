#include "r2node_PivotNode.h"

#include "r2base_Director.h"
#include "r2component_CustomTextureComponent.h"
#include "r2component_TextureRenderComponent.h"

namespace r2node
{
	r2base::NodeUp PivotNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			r2component::TextureRenderComponent* texture_render_component = ret->AddComponent<r2component::TextureRenderComponent>();
			r2component::CustomTextureComponent* custome_texture_component = ret->AddComponent<r2component::CustomTextureComponent>();
			custome_texture_component->GetTexture()->Reset( 1u, 1u, '+' );
			custome_texture_component->GetTexture()->FillColor( 1u, 1u, r2base::eForegroundColor::FG_Red | r2base::eBackgroundColor::BG_White );

			texture_render_component->SetTexture( custome_texture_component->GetTexture() );
		}

		return ret;
	}
}