#pragma once

#include <vector>

#include "r2bix/r2base_Component.h"
#include "r2bix/r2base_ComponentStaticID.h"

namespace p2048mini
{
	class NumberComponent;
	class Stage;

	class StageViewComponent : public r2base::Component
	{
	private:
		StageViewComponent( r2base::Node& owner_node );

	public:
		int GetStaticID() const override { return r2base::ComponentStaticID<StageViewComponent>::Get(); }
		static std::unique_ptr<StageViewComponent> Create( r2base::Node& owner_node );

		void Setup( const p2048mini::Stage& stage );
		void UpdateView();

		//
		//
		//
		int32_t GetWidth() const { return mWidth; }
		int32_t GetHeight() const { return mHeight; }

	private:
		const p2048mini::Stage* mStage;
		int32_t mWidth;
		int32_t mHeight;
		std::vector<p2048mini::NumberComponent*> mLabelContainer;
	};
}