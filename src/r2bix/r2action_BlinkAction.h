#pragma once

#include "r2base_Action.h"

#include "r2/r2_Timer_Float.h"

namespace r2action
{
	class BlinkAction : public r2base::Action
	{
	public:
		enum class eStep
		{
			Sleep,
			Show,
			Hide,
		};
	private:
		BlinkAction();

	public:
		static std::unique_ptr<BlinkAction> Create();

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
		bool mbLastVisible;
		r2::Timer_Float mTimer;
	};
}