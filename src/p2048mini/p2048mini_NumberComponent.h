#pragma once

#include "r2bix/r2base_Component.h"
#include "r2bix/r2base_ComponentStaticID.h"

namespace r2component
{
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
		void SetNumber( const int new_number );

	private:
		r2component::LabelComponent* mLabelComponent;
	};
}