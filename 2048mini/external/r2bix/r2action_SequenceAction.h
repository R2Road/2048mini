#pragma once

#include <vector>

#include "r2base_Action.h"

namespace r2action
{
	class SequenceAction : public r2base::Action
	{
	private:
		using ActionContainerT = std::vector<r2base::ActionUp>;

		SequenceAction();

	public:
		static std::unique_ptr<SequenceAction> Create();

		void Enter() override;
		bool Update( const float delta_time ) override;

		template<typename ActionT>
		ActionT* AddAction()
		{
			static_assert( std::is_base_of<r2base::Action, ActionT>() );

			auto action = ActionT::Create();
			auto ret = action.get();
			mActionContainer.push_back( std::move( action ) );

			return ret;
		}

	private:
		ActionContainerT mActionContainer;
		ActionContainerT::iterator mCurrentActionIndicator;
	};
}