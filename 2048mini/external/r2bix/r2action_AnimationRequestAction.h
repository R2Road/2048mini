#pragma once

#include "r2base_Action.h"
#include "r2animation_constant.h"

namespace r2action
{
	class AnimationRequestAction : public r2base::Action
	{
	public:
		enum class eOrder
		{
			PlayOnce,
			PlayRepeat,
			Stop,
		};
	private:
		AnimationRequestAction();

	public:
		static std::unique_ptr<AnimationRequestAction> Create();

		//
		//
		//
		void Enter() override;
		bool Update( const float delta_time ) override;

		void SetOrder( const eOrder order )
		{
			mOrder = order;
		}
		void SetAnimationIndex( const r2animation::eIndex animation_index )
		{
			mAnimationIndex = animation_index;
		}

	private:
		eOrder mOrder;
		r2animation::eIndex mAnimationIndex;
	};
}