#pragma once

#include "r2bix/r2base_Component.h"
#include "r2bix/r2base_ComponentStaticID.h"

#include "r2bix/r2input_KeyboardInputListener.h"

#include "p2048mini_GameProcessor.h"
#include "p2048mini_Stage.h"

#include "r2/r2_Direction4.h"

namespace p2048mini
{
	class StageViewComponent;

	class GameComponent : public r2base::Component
	{
	private:
		enum class eStep
		{
			GameReset,
			GameReady,
			GameStart,
			GameUpdate,
			GameEnd,
			GameClear,
			GameStop,
		};

		GameComponent( r2base::Node& owner_node );
	public:
		~GameComponent();

		int GetStaticID() const override { return r2base::ComponentStaticID<GameComponent>::Get(); }
		static std::unique_ptr<GameComponent> Create( r2base::Node& owner_node );

	public:
		void Update( const float delta_time ) override;

		const Stage& GetStage() const { return mStage; }

		void SetStageViewComponent( p2048mini::StageViewComponent* const stage_view_component ) { mStageViewComponent = stage_view_component; }
		void SetStageViewComponent4Debug( p2048mini::StageViewComponent* const stage_view_component ) { mStageViewComponent4Debug = stage_view_component; }
		void SetMaxNumberLabel( r2base::Node* const node ) { mMaxNumberLabel = node; }
		void SetTotalScoreLabel( r2base::Node* const node ) { mTotalScoreLabel = node; }
		void SetRecentScoreLabel( r2base::Node* const node ) { mRecentScoreLabel = node; }
		void SetYouWinNode( r2base::Node* const node ) { mYouWinNode = node; }
		void SetGameOverNode( r2base::Node* const node ) { mGameOverNode = node; }

	private:
		bool MoveNumber( const r2::Direction4::eState move_direction );

	private:
		eStep mStep;
		Stage mStage;
		GameProcessor mGameProcessor;

		p2048mini::StageViewComponent* mStageViewComponent;
		p2048mini::StageViewComponent* mStageViewComponent4Debug;
		r2base::Node* mMaxNumberLabel;
		r2base::Node* mTotalScoreLabel;
		r2base::Node* mRecentScoreLabel;

		r2base::Node* mYouWinNode;
		r2base::Node* mGameOverNode;

		r2input::KeyboardInputListener mKeyboardInputListener;
	};
}