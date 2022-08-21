#pragma once

#include "r2base_Action.h"

#include "r2/r2_Timer_Float.h"

namespace r2action
{
	class DelayAction : public r2base::Action
	{
	private:
		DelayAction();

	public:
		static std::unique_ptr<DelayAction> Create();

		//
		//
		//
		void Enter() override;
		bool Update( const float delta_time ) override;

		void SetTimeLimit( const float time_limit )
		{
			mTimer.reset( time_limit );
		}

	private:
		r2::Timer_Float mTimer;
	};
}