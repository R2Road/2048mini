#include "pch.h"
#include "p2048mini_StageViewNode.h"

#include <numeric>

#include "r2bix/r2base_Director.h"

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
			ret->AddComponent<p2048mini::StageViewComponent>();

			//
			// Background
			//
			{
				ret->AddChild<r2node::CustomTextureNode>();
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