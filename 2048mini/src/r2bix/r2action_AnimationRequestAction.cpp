#include "r2action_AnimationRequestAction.h"

#include <cassert>

#include "r2base_Node.h"
#include "r2component_TextureFrameAnimationComponent.h"

namespace r2action
{
	AnimationRequestAction::AnimationRequestAction() : mAnimationIndex( r2animation::eIndex::None )
	{}

	std::unique_ptr<AnimationRequestAction> AnimationRequestAction::Create()
	{
		std::unique_ptr<AnimationRequestAction> ret( new ( std::nothrow ) AnimationRequestAction() );
		return ret;
	}

	void AnimationRequestAction::Enter()
	{
		assert( nullptr != mOwnerNode->GetComponent<r2component::TextureFrameAnimationComponent>() );
	}
	bool AnimationRequestAction::Update( const float /*delta_time*/ )
	{
		switch( mOrder )
		{
		case eOrder::PlayOnce:
			mOwnerNode->GetComponent<r2component::TextureFrameAnimationComponent>()->RunAnimation_Once( mAnimationIndex );
			break;
		case eOrder::PlayRepeat:
			mOwnerNode->GetComponent<r2component::TextureFrameAnimationComponent>()->RunAnimation_Repeat( mAnimationIndex );
			break;
		case eOrder::Stop:
			mOwnerNode->GetComponent<r2component::TextureFrameAnimationComponent>()->StopAnimation();
			break;
		}
		return false;
	}
}