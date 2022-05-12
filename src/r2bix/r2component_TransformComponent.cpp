#include "r2component_TransformComponent.h"

namespace r2component
{
	TransformComponent::TransformComponent( r2base::Node& owner_node ) : r2base::Component( owner_node )
		, mPosition()
		, mZOrder( 0 )
	{}

	std::unique_ptr<TransformComponent> TransformComponent::Create( r2base::Node& owner_node )
	{
		std::unique_ptr<TransformComponent> ret( new ( std::nothrow ) TransformComponent( owner_node ) );
		if( !ret || !ret->Init() )
		{
			ret.reset();
		}

		return ret;
	}
}