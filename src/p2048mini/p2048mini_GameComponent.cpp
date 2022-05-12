#include "p2048mini_GameComponent.h"

#include "r2bix/r2base_Director.h"
#include "r2bix/r2base_Node.h"
#include "r2bix/r2component_ActionProcessComponent.h"
#include "r2bix/r2component_LabelComponent.h"
#include "r2bix/r2utility_InputUtil.h"
#include "r2bix/r2utility_StringBuilder.h"

#include "p2048mini_Config.h"
#include "p2048mini_StageViewComponent.h"

namespace p2048mini
{
	GameComponent::GameComponent( r2base::Node& owner_node ) : r2base::Component( owner_node )
		, mStep( eStep::GameReady )
		, mStage( 4u, 4u )
		, mGameProcessor( &mStage )
		, mStageViewComponent( nullptr )
		, mStageViewComponent4Debug( nullptr )

		, mMaxNumberLabel( nullptr )
		, mTotalScoreLabel( nullptr )
		, mRecentScoreLabel( nullptr )

		, mYouWinNode( nullptr )
		, mGameOverNode( nullptr )

		, mKeyboardInputListener( {
			0x1B		// esc
			, 0x41		// a - left
			, 0x44		// d - right
			, 0x53		// s - down
			, 0x57		// w - up
			, 0x52		// r - reset
		} )
	{
		GetOwnerNode().GetDirector().AddInputListener( &mKeyboardInputListener );
	}
	GameComponent::~GameComponent()
	{
		GetOwnerNode().GetDirector().RemoveInputListener( &mKeyboardInputListener );
	}

	std::unique_ptr<GameComponent> GameComponent::Create( r2base::Node& owner_node )
	{
		std::unique_ptr<GameComponent> ret( new ( std::nothrow ) GameComponent( owner_node ) );
		if( !ret || !ret->Init() )
		{
			ret.reset();
		}

		return ret;
	}

	void GameComponent::Update( const float delta_time )
	{
		mKeyboardInputListener.Update();

		switch( mStep )
		{
		case eStep::GameReset:
			mStageViewComponent->GetOwnerNode().SetVisible( false );
			mGameProcessor.Reset();
			mStep = eStep::GameReady;
			mMaxNumberLabel->GetComponent<r2component::LabelComponent>()->SetString( r2utility::StringBuilder::Build( "0" ) );
			mTotalScoreLabel->GetComponent<r2component::LabelComponent>()->SetString( r2utility::StringBuilder::Build( "0" ) );
			mRecentScoreLabel->GetComponent<r2component::LabelComponent>()->SetString( r2utility::StringBuilder::Build( "0" ) );
			mGameOverNode->SetVisible( false );
			mYouWinNode->SetVisible( false );
			break;

		case eStep::GameReady:
		{
			// Make 2 Number
			for( int i = 0; 2 > i; ++i )
			{
				mGameProcessor.AddNumber( 2u, 2u );
			}

			mStep = eStep::GameStart;
		}
		break;

		case eStep::GameStart:
			// Show Stage, On Input
			mStageViewComponent->UpdateView();
			mStageViewComponent->GetOwnerNode().SetVisible( true );
			mStep = eStep::GameUpdate;
			break;

		case eStep::GameUpdate:
		{
			// Input Process, Game End Check
			r2::Direction4::eState input_direction = r2::Direction4::eState::None;
			if( mKeyboardInputListener.IsPushed( 1 ) ) // A
			{
				input_direction = r2::Direction4::eState::Left;
			}
			else if( mKeyboardInputListener.IsPushed( 2 ) ) // D
			{
				input_direction = r2::Direction4::eState::Right;
			}
			else if( mKeyboardInputListener.IsPushed( 3 ) ) // S
			{
				input_direction = r2::Direction4::eState::Up;
			}
			else if( mKeyboardInputListener.IsPushed( 4 ) ) // W
			{
				input_direction = r2::Direction4::eState::Down;
			}

			if( r2::Direction4::eState::None != input_direction )
			{
				if( p2048mini::Config::GetDebugConfig().bLastStage )
				{
					mStageViewComponent4Debug->UpdateView();
				}

				if( !MoveNumber( input_direction ) )
				{
					if( mGameProcessor.IsGameClear() )
					{
						mStep = eStep::GameClear;
					}
					else
					{
						mStep = eStep::GameEnd;
					}
				}
			}
		}
		break;

		case eStep::GameEnd:
			mGameOverNode->SetVisible( true );
			mGameOverNode->GetComponent<r2component::ActionProcessComponent>()->StartAction();
			mStep = eStep::GameStop;
			break;

		case eStep::GameClear:
			mYouWinNode->SetVisible( true );
			mYouWinNode->GetComponent<r2component::ActionProcessComponent>()->StartAction();
			mStep = eStep::GameStop;
			break;
		}

		if( mKeyboardInputListener.IsPushed( 5 ) )
		{
			mStep = eStep::GameReset;
		}
		else if( mKeyboardInputListener.IsRelease( 0 ) )
		{
			r2utility::ClearCInputBuffer();
			GetOwnerNode().GetDirector().RequestAbort();
		}

		r2base::Component::Update( delta_time );
	}

	bool GameComponent::MoveNumber( const r2::Direction4::eState move_direction )
	{
		const auto move_result = mGameProcessor.Move( move_direction );
		if( move_result.has_moved )
		{
			mGameProcessor.AddNumber( 2u, 4u );
			mStageViewComponent->UpdateView();

			//
			// Score View Update
			//
			if( 0 < mGameProcessor.GetSum4Merged() )
			{
				mMaxNumberLabel->GetComponent<r2component::LabelComponent>()->SetString( r2utility::StringBuilder::Build( "%d"
					, mGameProcessor.GetMaxNumber()
				) );

				mTotalScoreLabel->GetComponent<r2component::LabelComponent>()->SetString( r2utility::StringBuilder::Build( "%d"
					, mGameProcessor.GetScore()
				) );
				
				mRecentScoreLabel->GetComponent<r2component::LabelComponent>()->SetString( r2utility::StringBuilder::Build( "+ %d"
					, mGameProcessor.GetSum4Merged()
				) );
			}
		}

		return !mGameProcessor.IsGameEnd();
	}
}