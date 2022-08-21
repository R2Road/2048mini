#include "r2action_SequenceAction.h"

namespace r2action
{
	SequenceAction::SequenceAction() :
		mActionContainer()
		, mCurrentActionIndicator( mActionContainer.end() )
	{}

	std::unique_ptr<SequenceAction> SequenceAction::Create()
	{
		std::unique_ptr<SequenceAction> ret( new ( std::nothrow ) SequenceAction() );
		return ret;
	}

	void SequenceAction::Enter()
	{
		mCurrentActionIndicator = mActionContainer.begin();

		if( mActionContainer.end() != mCurrentActionIndicator )
		{
			( *mCurrentActionIndicator )->SetOwnerNode( mOwnerNode );
			( *mCurrentActionIndicator )->Enter();
		}
	}

	bool SequenceAction::Update( const float delta_time )
	{
		if( mActionContainer.end() != mCurrentActionIndicator )
		{
			if( !( *mCurrentActionIndicator )->Update( delta_time ) )
			{
				++mCurrentActionIndicator;
				if( mActionContainer.end() != mCurrentActionIndicator )
				{
					( *mCurrentActionIndicator )->SetOwnerNode( mOwnerNode );
					( *mCurrentActionIndicator )->Enter();
				}
			}
		}		

		return mActionContainer.end() != mCurrentActionIndicator;
	}
}