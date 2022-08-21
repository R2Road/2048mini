#include "r2action_TickAction.h"

#include "r2base_Node.h"

namespace r2action
{
	TickAction::TickAction() : mTickLimit( 0u ), mCurrentTick( 0u )
	{}

	std::unique_ptr<TickAction> TickAction::Create()
	{
		std::unique_ptr<TickAction> ret( new ( std::nothrow ) TickAction() );
		return ret;
	}

	void TickAction::Enter()
	{
		mCurrentTick = 0u;
	}
	bool TickAction::Update( const float /*delta_time*/ )
	{
		++mCurrentTick;
		return mCurrentTick > mCurrentTick;
	}
}