#pragma once

#include "r2base_Action.h"

namespace r2action
{
	class RepeatAction : public r2base::Action
	{
	private:
		RepeatAction();

	public:
		static std::unique_ptr<RepeatAction> Create();

		//
		//
		//
		void Enter() override;
		bool Update( const float delta_time ) override;

		//
		//
		//
		void SetAction( r2base::ActionUp action )
		{
			mAction = std::move( action );
		}

	private:
		r2base::ActionUp mAction;
	};
}