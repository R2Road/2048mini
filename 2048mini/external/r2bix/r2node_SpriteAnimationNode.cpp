#include "r2node_SpriteAnimationNode.h"

#include "r2base_Director.h"
#include "r2component_TextureFrameAnimationComponent.h"
#include "r2component_TextureFrameRenderComponent.h"

namespace r2node
{
	r2base::NodeUp SpriteAnimationNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			auto frame_render_component = ret->AddComponent<r2component::TextureFrameRenderComponent>();
			auto frame_animation_component = ret->AddComponent<r2component::TextureFrameAnimationComponent>();

			frame_animation_component->SetTextureFrameRenderComponent( frame_render_component );
		}

		return ret;
	}
}