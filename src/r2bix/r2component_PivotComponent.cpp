#include "r2component_PivotComponent.h"

namespace r2component
{
	PivotComponent::PivotComponent( r2base::Node& owner_node ) : r2base::Component( owner_node )
		, mTexture( "+" )
	{}

	std::unique_ptr<PivotComponent> PivotComponent::Create( r2base::Node& owner_node )
	{
		std::unique_ptr<PivotComponent> ret( new ( std::nothrow ) PivotComponent( owner_node ) );
		if( !ret || !ret->Init() )
		{
			ret.reset();
		}

		return ret;
	}
}