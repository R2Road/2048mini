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

#include "p2048mini_Config.h"
#include "p2048mini_GameComponent.h"
#include "p2048mini_StageViewComponent.h"
#include "p2048mini_StageViewNode.h"
#include "p2048minitable_TextureTable.h"

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
			// Game Component
			//
			auto game_scene_component = ret->AddComponent<p2048mini::GameSceneComponent>();


			//
			// Title
			//
			{
				auto node = ret->AddChild<r2node::SpriteNode>();
				node->GetComponent<r2component::TextureFrameRenderComponent>()->SetTextureFrame( p2048minitable::TextureTable::GetInstance().GetTextureFrame( "title_0" ) );
				node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.11f )
				);
			}

			//
			// Stage View
			//
			{
				auto node = ret->AddChild<p2048mini::StageViewNode>( 1 );
				node->SetVisible( false );

				auto stage_view_component = node->GetComponent<p2048mini::StageViewComponent>();
				stage_view_component->Setup( game_scene_component->GetStage() );

				node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f ) - ( stage_view_component->GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f ) - ( stage_view_component->GetHeight() * 0.5f )
				);

				//
				//
				//
				game_scene_component->SetStageViewComponent( stage_view_component );
			}
			//
			// History View
			//
			{
				auto node = ret->AddChild<p2048mini::StageViewNode>( 2 );
				node->SetVisible( false );

				auto stage_view_component_4debug = node->GetComponent<p2048mini::StageViewComponent>();
				stage_view_component_4debug->Setup( game_scene_component->GetStage() );

				node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f ) - ( stage_view_component_4debug->GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f ) - ( stage_view_component_4debug->GetHeight() * 0.5f )
				);

				//
				//
				//
				game_scene_component->SetStageViewComponent4History( stage_view_component_4debug );
			}

			const int score_label_x = 38;
			const int score_number_x = score_label_x + 10;

			//
			// Max Number
			//
			{
				auto label_node = ret->AddChild<r2node::LabelNode>();
				label_node->GetComponent<r2component::LabelComponent>()->SetString( "Max : " );
				label_node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 0.f );
				label_node->GetComponent<r2component::TransformComponent>()->SetPosition( score_label_x, 9 );

				auto max_number_label_node = ret->AddChild<r2node::LabelNode>( 1 );
				max_number_label_node->GetComponent<r2component::LabelComponent>()->SetString( "0" );
				max_number_label_node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 0.f );
				max_number_label_node->GetComponent<r2component::TransformComponent>()->SetPosition( score_number_x, 9 );

				//
				//
				//
				game_scene_component->SetMaxNumberLabel( max_number_label_node );
			}

			//
			// Score
			//
			{
				auto label_node = ret->AddChild<r2node::LabelNode>();
				label_node->GetComponent<r2component::LabelComponent>()->SetString( "Score : " );
				label_node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 0.f );
				label_node->GetComponent<r2component::TransformComponent>()->SetPosition( score_label_x, 10 );

				auto total_score_label_node = ret->AddChild<r2node::LabelNode>( 1 );
				total_score_label_node->GetComponent<r2component::LabelComponent>()->SetString( "0" );
				total_score_label_node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 0.f );
				total_score_label_node->GetComponent<r2component::TransformComponent>()->SetPosition( score_number_x, 10 );

				//
				//
				//
				game_scene_component->SetTotalScoreLabel( total_score_label_node );
			}

			//
			// Recent Score
			//
			{
				auto label_node = ret->AddChild<r2node::LabelNode>();
				label_node->GetComponent<r2component::LabelComponent>()->SetString( "Recent : " );
				label_node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 0.f );
				label_node->GetComponent<r2component::TransformComponent>()->SetPosition( score_label_x, 11 );

				auto total_score_label_node = ret->AddChild<r2node::LabelNode>( 1 );
				total_score_label_node->GetComponent<r2component::LabelComponent>()->SetString( "0" );
				total_score_label_node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 0.f );
				total_score_label_node->GetComponent<r2component::TransformComponent>()->SetPosition( score_number_x, 11 );

				//
				//
				//
				game_scene_component->SetRecentScoreLabel( total_score_label_node );
			}

			//
			// Key Info
			//
			{
				auto node = ret->AddChild<r2node::SpriteNode>();
				node->GetComponent<r2component::TextureFrameRenderComponent>()->SetTextureFrame( p2048minitable::TextureTable::GetInstance().GetTextureFrame( "keyinfo_0" ) );
				node->GetComponent<r2component::TransformComponent>()->SetPosition( 22, 32 );
			}

			//
			// Exit
			//
			{
				auto node = ret->AddChild<r2node::LabelNode>();
				node->GetComponent<r2component::LabelComponent>()->SetString( "< ESC" );
				node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 0.f, 0.f );
			}

			//
			// You Win
			//
			{
				auto node = ret->AddChild<r2node::SpriteNode>( 2 );
				node->GetComponent<r2component::TextureFrameRenderComponent>()->SetTextureFrame( p2048minitable::TextureTable::GetInstance().GetTextureFrame( "you_win_0" ) );
				node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f )
				);
				node->SetVisible( false );

				auto action_process_component = node->AddComponent<r2component::ActionProcessComponent>();
				{
					auto sequence_action = r2action::SequenceAction::Create();

					auto moveto_action = sequence_action->AddAction<r2action::MoveToAction>();
					moveto_action->SetEndPoint( node->GetComponent<r2component::TransformComponent>()->GetPosition() );
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
				game_scene_component->SetYouWinNode( node );
			}

			//
			// Game Over
			//
			{
				auto node = ret->AddChild<r2node::SpriteNode>( 2 );
				node->GetComponent<r2component::TextureFrameRenderComponent>()->SetTextureFrame( p2048minitable::TextureTable::GetInstance().GetTextureFrame( "game_over_0" ) );
				node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f )
				);
				node->SetVisible( false );

				auto action_process_component = node->AddComponent<r2component::ActionProcessComponent>();
				{
					auto sequence_action = r2action::SequenceAction::Create();

					auto moveto_action = sequence_action->AddAction<r2action::MoveToAction>();
					moveto_action->SetEndPoint( node->GetComponent<r2component::TransformComponent>()->GetPosition() );
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
				game_scene_component->SetGameOverNode( node );
			}

			//
			// Debug
			//
			if( p2048mini::Config::GetNodeConfig().pivot )
			{
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