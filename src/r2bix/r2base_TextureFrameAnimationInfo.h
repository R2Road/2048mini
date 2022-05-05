#pragma once

#include <vector>

#include "r2animation_constant.h"

namespace r2render
{
	class TextureFrame;
}

namespace r2base
{
	class TextureFrameAnimationInfo
	{
	public:
		struct AnimationFrame
		{
			float TimeLimit;
			const r2render::TextureFrame* Frame = nullptr;
		};
		struct Animation
		{
			r2animation::eIndex Index;
			std::vector<AnimationFrame> Container;
		};
		using AnimationPackageT = std::vector<Animation>;

		TextureFrameAnimationInfo( AnimationPackageT&& animation_package );

		const AnimationPackageT& Get() const { return mAnimationPackage; }

	private:
		const AnimationPackageT mAnimationPackage;
	};
}