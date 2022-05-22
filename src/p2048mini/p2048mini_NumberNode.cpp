#include "p2048mini_NumberNode.h"

#include <numeric>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2component_CustomTextureComponent.h"
#include "r2bix/r2component_LabelComponent.h"
#include "r2bix/r2component_PivotComponent.h"
#include "r2bix/r2component_TextureRenderComponent.h"
#include "r2bix/r2node_CustomTextureNode.h"
#include "r2bix/r2node_LabelNode.h"
#include "r2bix/r2node_PivotNode.h"
#include "r2bix/r2node_SpriteNode.h"

#include "p2048mini_Config.h"
#include "p2048mini_NumberComponent.h"
#include "p2048minitable_TextureTable.h"

namespace p2048mini
{
	r2base::NodeUp NumberNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			auto number_component = ret->AddComponent<p2048mini::NumberComponent>();

			//
			// Frame
			//
			{
				auto node = ret->AddChild<r2node::CustomTextureNode>( std::numeric_limits<int>::min() );
				node->GetComponent<r2component::CustomTextureComponent>()->GetTexture()->Reset( 8u, 3u, ' ' );
				node->GetComponent<r2component::TextureRenderComponent>()->SetTexture(
					node->GetComponent<r2component::CustomTextureComponent>()->GetTexture()
				);

				number_component->SetCustomTextureComponent( node->GetComponent<r2component::CustomTextureComponent>() );
			}

			//
			// Label
			//
			{
				auto node = ret->AddChild<r2node::LabelNode>();
				node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 0.f );
				node->GetComponent<r2component::TransformComponent>()->SetPosition( 2, 0 );
				node->GetComponent<r2component::LabelComponent>()->SetColor( r2base::eForegroundColor::FG_White | r2base::eBackgroundColor::BG_Black );

				number_component->SetLabelComponent( node->GetComponent<r2component::LabelComponent>() );
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