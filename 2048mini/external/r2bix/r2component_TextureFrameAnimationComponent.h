#pragma once

#include <vector>

#include "r2base_Component.h"
#include "r2base_ComponentStaticID.h"
#include "r2/r2_Timer_Float.h"
#include "r2base_TextureFrameAnimationInfo.h"

namespace r2component
{
	class TextureFrameRenderComponent;
}

namespace r2render
{
	class TextureFrame;
}

namespace r2component
{
	class TextureFrameAnimationComponent : public r2base::Component
	{
	private:
		struct AnimationFrame
		{
			r2::Timer_Float Timer;
			const r2render::TextureFrame* Frame = nullptr;
		};
		struct Animation
		{
			r2animation::eIndex Index;
			std::vector<AnimationFrame> Container;
		};
		using AnimationPackageT = std::vector<Animation>;

		TextureFrameAnimationComponent( r2base::Node& owner_node );

	public:
		int GetStaticID() const override { return r2base::ComponentStaticID<TextureFrameAnimationComponent>::Get(); }
		static std::unique_ptr<TextureFrameAnimationComponent> Create( r2base::Node& owner_node );

		//
		//
		//
		void Update( const float delta_time ) override;

		//
		//
		//
		r2component::TextureFrameRenderComponent* const GetTextureFrameRenderComponent()
		{
			return mTextureFrameRenderComponent;
		}
		void SetTextureFrameRenderComponent( r2component::TextureFrameRenderComponent* const texture_frame_render_component )
		{
			mTextureFrameRenderComponent = texture_frame_render_component;
		}

		//
		//
		//
		void LoadAnimation( const r2base::TextureFrameAnimationInfo& info );
		bool HasAnimation( const r2animation::eIndex animation_index ) const;
		void RunAnimation_Once( const r2animation::eIndex animation_index );
		void RunAnimation_Repeat( const r2animation::eIndex animation_index );
		bool IsRunning() const { return mAnimationPackage.end() != mCurrentAnimation; }
		void StopAnimation();
		const r2animation::eIndex GetCurrentAnimationIndex() const;

	private:
		r2component::TextureFrameRenderComponent* mTextureFrameRenderComponent;

		bool mbRepeat;
		AnimationPackageT mAnimationPackage;
		AnimationPackageT::iterator mCurrentAnimation;
		uint32_t mCurrentAnimationFrameIndex;
	};
}