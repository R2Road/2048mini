#pragma once

#include "r2bix/r2base_Component.h"
#include "r2bix/r2base_ComponentStaticID.h"

namespace r2component
{
	class CustomTextureComponent;
	class LabelComponent;
}

namespace p2048mini
{
	class NumberComponent : public r2base::Component
	{
	private:
		NumberComponent( r2base::Node& owner_node );

	public:
		int GetStaticID() const override { return r2base::ComponentStaticID<NumberComponent>::Get(); }
		static std::unique_ptr<NumberComponent> Create( r2base::Node& owner_node );

		void SetLabelComponent( r2component::LabelComponent* const label_component )
		{
			mLabelComponent = label_component;
		}
		void SetCustomTextureComponent( r2component::CustomTextureComponent* const custom_texture_component )
		{
			mCustomTextureComponent = custom_texture_component;
		}
		void SetNumber( const int new_number, const bool merged, const bool newcomer );

	private:
		r2component::LabelComponent* mLabelComponent;
		r2component::CustomTextureComponent* mCustomTextureComponent;
	};
}