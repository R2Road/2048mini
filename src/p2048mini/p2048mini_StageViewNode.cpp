#include "p2048mini_StageViewNode.h"

#include <numeric>

#include "r2bix/r2base_Director.h"

#include "r2bix/r2component_CustomTextureComponent.h"
#include "r2bix/r2component_TextureRenderComponent.h"
#include "r2bix/r2node_CustomTextureNode.h"
#include "r2bix/r2node_PivotNode.h"

#include "p2048mini_Config.h"
#include "p2048mini_StageViewComponent.h"

namespace p2048mini
{
	r2base::NodeUp StageViewNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			auto stage_view_component = ret->AddComponent<p2048mini::StageViewComponent>();

			//
			// Background
			//
			{
				auto node = ret->AddChild<r2node::CustomTextureNode>( std::numeric_limits<int>::min() );
				node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 0.f, 0.f );
				node->mTransformComponent->SetPosition( -1, -1 );

				stage_view_component->SetBackgroundNode( node );

				//
				// Debug
				//
				if( p2048mini::Config::GetNodeConfig().pivot )
				{
					node->AddChild<r2node::PivotNode>( std::numeric_limits<int>::max() );
				}
			}

			//
			// Debug
			//
			if( p2048mini::Config::GetNodeConfig().pivot )
			{
				ret->AddChild<r2node::PivotNode>( std::numeric_limits<int>::max() );
			}
		}

		return ret;
	}
}