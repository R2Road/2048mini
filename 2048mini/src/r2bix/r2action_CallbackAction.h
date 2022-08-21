#pragma once

#include <functional>

#include "r2base_Action.h"

namespace r2action
{
	class CallbackAction : public r2base::Action
	{
	public:
		using CallbackT = std::function<void()>;

	private:
		CallbackAction();

	public:
		static std::unique_ptr<CallbackAction> Create();

		//
		//
		//
		void Enter() override;
		bool Update( const float delta_time ) override;

		void SetCallback( const CallbackT& callback )
		{
			mCallback = callback;
		}

	private:
		CallbackT mCallback;
	};
}