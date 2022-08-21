#pragma once

#include "r2base_Action.h"

namespace r2action
{
	class TickAction : public r2base::Action
	{
	private:
		TickAction();

	public:
		static std::unique_ptr<TickAction> Create();

		//
		// override
		//
		void Enter() override;
		bool Update( const float delta_time ) override;

		//
		//
		//
		void SetTickLimit( const uint32_t tick_limit )
		{
			mTickLimit = tick_limit;
		}

	private:
		uint32_t mTickLimit;
		uint32_t mCurrentTick;
	};
}