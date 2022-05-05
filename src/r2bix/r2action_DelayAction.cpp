#include "pch.h"
#include "r2action_DelayAction.h"

#include "r2base_Node.h"

namespace r2action
{
	DelayAction::DelayAction() :
		mTimer( 1.f )
	{}

	std::unique_ptr<DelayAction> DelayAction::Create()
	{
		std::unique_ptr<DelayAction> ret( new ( std::nothrow ) DelayAction() );
		return ret;
	}

	void DelayAction::Enter()
	{
		mTimer.reset();
	}
	bool DelayAction::Update( const float delta_time )
	{
		mTimer.update( delta_time );

		return mTimer.isAlive();
	}
}