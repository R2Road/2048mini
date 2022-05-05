#include "pch.h"
#include "p2048mini_GameScene.h"

#include <numeric>

#include "r2bix/r2action_SequenceAction.h"
#include "r2bix/r2action_DelayAction.h"
#include "r2bix/r2action_MoveByAction.h"
#include "r2bix/r2action_MoveToAction.h"
#include "r2bix/r2base_Director.h"
#include "r2bix/r2component_ActionProcessComponent.h"
#include "r2bix/r2component_CustomTextureComponent.h"
#include "r2bix/r2component_LabelComponent.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"
#include "r2bix/r2component_TextureRenderComponent.h"
#include "r2bix/r2node_CustomTextureNode.h"
#include "r2bix/r2node_LabelNode.h"
#include "r2bix/r2node_PivotNode.h"
#include "r2bix/r2node_SpriteNode.h"

#include "p2048mini_GameComponent.h"
#include "p2048mini_StageViewComponent.h"
#include "p2048mini_StageViewNode.h"
#include "p2048minitable_TextureTable.h"

#include "p2048mini_Config.h"

namespace p2048mini
{
	r2node::SceneNodeUp GameScene::Create( r2base::Director& director )
	{
		auto ret( r2node::SceneNode::Create( director ) );
		if( ret )
		{
			//
			// Table Load
			//
			p2048minitable::TextureTable::GetInstance().Load();

			//
			// Background
			//
			{
				auto node = ret->AddChild<r2node::CustomTextureNode>( std::numeric_limits<int>::min() );
				node->GetComponent<r2component::CustomTextureComponent>()->GetTexture()->Reset( 37, 17, '=' );
				node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 0.f, 0.f );
				node->GetComponent<r2component::TextureRenderComponent>()->ResetVisibleRect();

				node->mTransformComponent->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f ) - ( node->GetComponent<r2component::CustomTextureComponent>()->GetTexture()->GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f ) - ( node->GetComponent<r2component::CustomTextureComponent>()->GetTexture()->GetHeight() * 0.5f )
				);

				//
				// Debug
				//
				if( p2048mini::Config::GetNodeConfig().pivot )
				{
					node->AddChild<r2node::PivotNode>( std::numeric_limits<int>::max() );
				}
			}

			//
			// Game Component
			//
			auto game_component = ret->AddComponent<p2048mini::GameComponent>();


			//
			// Title
			//
			{
				auto sprite_node = ret->AddChild<r2node::SpriteNode>();
				sprite_node->GetComponent<r2component::TextureFrameRenderComponent>()->SetTextureFrame( p2048minitable::TextureTable::GetInstance().GetTextureFrame( "title_0" ) );
				sprite_node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.18f )
				);
			}

			//
			// Stage
			//
			{
				auto stage_view_node = ret->AddChild<p2048mini::StageViewNode>( 1 );
				stage_view_node->SetVisible( false );

				auto stage_view_component = stage_view_node->GetComponent<p2048mini::StageViewComponent>();
				stage_view_component->Setup( game_component->GetStage() );

				stage_view_node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f ) - ( stage_view_component->GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f ) - ( stage_view_component->GetHeight() * 0.5f )
				);

				//
				//
				//
				game_component->SetStageViewComponent( stage_view_component );
			}

			//
			// Max Number
			//
			{
				auto label_node = ret->AddChild<r2node::LabelNode>();
				label_node->GetComponent<r2component::LabelComponent>()->SetString( "Max : " );
				label_node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 0.f );
				label_node->GetComponent<r2component::TransformComponent>()->SetPosition( 62, 14 );

				auto max_number_label_node = ret->AddChild<r2node::LabelNode>( 1 );
				max_number_label_node->GetComponent<r2component::LabelComponent>()->SetString( "0" );
				max_number_label_node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 0.f );
				max_number_label_node->GetComponent<r2component::TransformComponent>()->SetPosition( 72, 14 );

				//
				//
				//
				game_component->SetMaxNumberLabel( max_number_label_node );
			}

			//
			// Score
			//
			{
				auto label_node = ret->AddChild<r2node::LabelNode>();
				label_node->GetComponent<r2component::LabelComponent>()->SetString( "Score : " );
				label_node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 0.f );
				label_node->GetComponent<r2component::TransformComponent>()->SetPosition( 62, 15 );

				auto total_score_label_node = ret->AddChild<r2node::LabelNode>( 1 );
				total_score_label_node->GetComponent<r2component::LabelComponent>()->SetString( "0" );
				total_score_label_node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 0.f );
				total_score_label_node->GetComponent<r2component::TransformComponent>()->SetPosition( 72, 15 );

				//
				//
				//
				game_component->SetTotalScoreLabel( total_score_label_node );
			}

			//
			// Recent Score
			//
			{
				auto label_node = ret->AddChild<r2node::LabelNode>();
				label_node->GetComponent<r2component::LabelComponent>()->SetString( "Recent : " );
				label_node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 0.f );
				label_node->GetComponent<r2component::TransformComponent>()->SetPosition( 62, 16 );

				auto total_score_label_node = ret->AddChild<r2node::LabelNode>( 1 );
				total_score_label_node->GetComponent<r2component::LabelComponent>()->SetString( "0" );
				total_score_label_node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 0.f );
				total_score_label_node->GetComponent<r2component::TransformComponent>()->SetPosition( 72, 16 );

				//
				//
				//
				game_component->SetRecentScoreLabel( total_score_label_node );
			}

			//
			// Key Info
			//
			{
				auto sprite_node = ret->AddChild<r2node::SpriteNode>();
				sprite_node->GetComponent<r2component::TextureFrameRenderComponent>()->SetTextureFrame( p2048minitable::TextureTable::GetInstance().GetTextureFrame( "keyinfo_0" ) );
				sprite_node->GetComponent<r2component::TransformComponent>()->SetPosition( 46, 37 );
			}

			//
			// You Win
			//
			{
				auto you_win_node = ret->AddChild<r2node::SpriteNode>( 2 );
				you_win_node->GetComponent<r2component::TextureFrameRenderComponent>()->SetTextureFrame( p2048minitable::TextureTable::GetInstance().GetTextureFrame( "you_win_0" ) );
				you_win_node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f )
				);
				you_win_node->SetVisible( false );

				auto action_process_component = you_win_node->AddComponent<r2component::ActionProcessComponent>();
				{
					auto sequence_action = r2action::SequenceAction::Create();

					auto moveto_action = sequence_action->AddAction<r2action::MoveToAction>();
					moveto_action->SetEndPoint( you_win_node->GetComponent<r2component::TransformComponent>()->GetPosition() );
					moveto_action->SetTimeLimit( 0.f );

					auto delay_action = sequence_action->AddAction<r2action::DelayAction>();
					delay_action->SetTimeLimit( 1.f );

					auto moveby_action = sequence_action->AddAction<r2action::MoveByAction>();
					moveby_action->SetMoveAmount( r2::PointInt( 0, 17 ) );
					moveby_action->SetTimeLimit( 1.2f );

					action_process_component->SetAction( std::move( sequence_action ) );
				}

				//
				//
				//
				game_component->SetYouWinNode( you_win_node );
			}

			//
			// Game Over
			//
			{
				auto game_over_node = ret->AddChild<r2node::SpriteNode>( 2 );
				game_over_node->GetComponent<r2component::TextureFrameRenderComponent>()->SetTextureFrame( p2048minitable::TextureTable::GetInstance().GetTextureFrame( "game_over_0" ) );
				game_over_node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f )
				);
				game_over_node->SetVisible( false );

				auto action_process_component = game_over_node->AddComponent<r2component::ActionProcessComponent>();
				{
					auto sequence_action = r2action::SequenceAction::Create();

					auto moveto_action = sequence_action->AddAction<r2action::MoveToAction>();
					moveto_action->SetEndPoint( game_over_node->GetComponent<r2component::TransformComponent>()->GetPosition() );
					moveto_action->SetTimeLimit( 0.f );

					auto delay_action = sequence_action->AddAction<r2action::DelayAction>();
					delay_action->SetTimeLimit( 1.f );

					auto moveby_action = sequence_action->AddAction<r2action::MoveByAction>();
					moveby_action->SetMoveAmount( r2::PointInt( 0, 17 ) );
					moveby_action->SetTimeLimit( 1.2f );

					action_process_component->SetAction( std::move( sequence_action ) );
				}

				//
				//
				//
				game_component->SetGameOverNode( game_over_node );
			}

			//
			// Debug
			//
			if( p2048mini::Config::GetDebugConfig().bLastStage )
			{
				auto stage_view_node = ret->AddChild<p2048mini::StageViewNode>( 1 );

				auto stage_view_component_4debug = stage_view_node->GetComponent<p2048mini::StageViewComponent>();
				stage_view_component_4debug->Setup( game_component->GetStage() );

				stage_view_node->GetComponent<r2component::TransformComponent>()->SetPosition(
					0.f
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f ) - ( stage_view_component_4debug->GetHeight() * 0.5f )
				);

				//
				//
				//
				game_component->SetStageViewComponent4Debug( stage_view_component_4debug );
			}
			if( p2048mini::Config::GetNodeConfig().pivot )
			{
				//
				//
				//
				ret->AddChild<r2node::PivotNode>( std::numeric_limits<int>::max() );
				ret->AddChild<r2node::PivotNode>( std::numeric_limits<int>::max() )->mTransformComponent->SetPosition( director.GetScreenBufferSize().GetWidth() - 1, 0 );
				ret->AddChild<r2node::PivotNode>( std::numeric_limits<int>::max() )->mTransformComponent->SetPosition( director.GetScreenBufferSize().GetWidth() - 1, director.GetScreenBufferSize().GetHeight() - 1 );
				ret->AddChild<r2node::PivotNode>( std::numeric_limits<int>::max() )->mTransformComponent->SetPosition( 0, director.GetScreenBufferSize().GetHeight() - 1 );

				ret->AddChild<r2node::PivotNode>( std::numeric_limits<int>::max() )->mTransformComponent->SetPosition( director.GetScreenBufferSize().GetWidth() * 0.5f, director.GetScreenBufferSize().GetHeight() * 0.5f );
			}
		}

		return ret;
	}
}