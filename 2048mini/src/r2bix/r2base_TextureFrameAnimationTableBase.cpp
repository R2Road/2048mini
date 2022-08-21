#include "r2base_TextureFrameAnimationTableBase.h"

namespace r2base
{
	TextureFrameAnimationTableBase::TextureFrameAnimationTableBase() : mContainer()
	{}

	const r2base::TextureFrameAnimationInfo& TextureFrameAnimationTableBase::Get( const int index ) const
	{
		auto itr = mContainer.find( index );
		if( mContainer.end() != itr )
		{
			return itr->second;
		}

		static r2base::TextureFrameAnimationInfo dummy_package( std::move( r2base::TextureFrameAnimationInfo::AnimationPackageT() ) );
		return dummy_package;
	}
}