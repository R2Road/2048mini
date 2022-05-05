#pragma once

#include "r2base_Action.h"

#include "r2/r2_Point_Int.h"
#include "r2/r2_Timer_Float.h"

namespace r2action
{
	class MoveByAction : public r2base::Action
	{
	private:
		MoveByAction();

	public:
		static std::unique_ptr<MoveByAction> Create();

		//
		//
		//
		void Enter() override;
		bool Update( const float delta_time ) override;

		//
		//
		//
		void SetMoveAmount( const r2::PointInt move_amount )
		{
			mMoveAmount = move_amount;
		}
		void SetTimeLimit( const float time_limit )
		{
			mTimer.reset( time_limit );
		}

	private:
		r2::PointInt mMoveAmount;

		r2::PointInt mStartPoint;
		r2::Timer_Float mTimer;
	};
}