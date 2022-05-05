#pragma once

#include <unordered_map>

#include "r2base_TextureFrameAnimationInfo.h"

namespace r2base
{
	class TextureFrameAnimationTableBase
	{
	protected:
		using ContainerT = std::unordered_map<uint32_t, r2base::TextureFrameAnimationInfo>;

	public:
		TextureFrameAnimationTableBase();

		virtual void Load() = 0;

		const r2base::TextureFrameAnimationInfo& Get( const int index ) const;

	protected:
		ContainerT mContainer;
	};
}