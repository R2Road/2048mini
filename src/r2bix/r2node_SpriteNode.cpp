#include "r2node_SpriteNode.h"

#include "r2base_Director.h"
#include "r2component_TextureFrameRenderComponent.h"

namespace r2node
{
	r2base::NodeUp SpriteNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			ret->AddComponent<r2component::TextureFrameRenderComponent>();
		}

		return ret;
	}
}