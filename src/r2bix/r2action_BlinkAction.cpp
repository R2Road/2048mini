#include "pch.h"
#include "r2action_BlinkAction.h"

#include "r2base_Node.h"

namespace r2action
{
	BlinkAction::BlinkAction() :
		mbLastVisible( false )
		, mTimer( 1.f )
	{}

	std::unique_ptr<BlinkAction> BlinkAction::Create()
	{
		std::unique_ptr<BlinkAction> ret( new ( std::nothrow ) BlinkAction() );
		return ret;
	}

	void BlinkAction::Enter()
	{
		mbLastVisible = mOwnerNode->IsVisible();
		mOwnerNode->SetVisible( !mbLastVisible );

		mTimer.reset();
	}
	bool BlinkAction::Update( const float delta_time )
	{
		if( !mTimer.update( delta_time ) )
		{
			mOwnerNode->SetVisible( mbLastVisible );
		}

		return mTimer.isAlive();
	}
}