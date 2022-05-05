#include "pch.h"
#include "r2action_MoveToAction.h"

#include "r2base_Node.h"

namespace r2action
{
	MoveToAction::MoveToAction() :
		mMoveAmount()
		, mStartPoint()
		, mEndPoint()
		, mTimer( 1.f )
	{}

	std::unique_ptr<MoveToAction> MoveToAction::Create()
	{
		std::unique_ptr<MoveToAction> ret( new ( std::nothrow ) MoveToAction() );
		return ret;
	}

	void MoveToAction::Enter()
	{
		mStartPoint = mOwnerNode->mTransformComponent->GetPosition();
		mMoveAmount = mEndPoint - mStartPoint;
		mTimer.reset();
	}
	bool MoveToAction::Update( const float delta_time )
	{
		if( mTimer.update( delta_time ) )
		{
			mOwnerNode->mTransformComponent->SetPosition(
				mStartPoint.GetX() + ( mMoveAmount.GetX() * mTimer.getElapsedTimeRate() )
				, mStartPoint.GetY() + ( mMoveAmount.GetY() * mTimer.getElapsedTimeRate() )
			);
		}
		else
		{
			mOwnerNode->mTransformComponent->SetPosition( mEndPoint );
		}

		return mTimer.isAlive();
	}
}