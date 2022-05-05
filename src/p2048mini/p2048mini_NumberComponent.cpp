#include "pch.h"
#include "p2048mini_NumberComponent.h"

#include "r2bix/r2component_LabelComponent.h"

namespace p2048mini
{
	NumberComponent::NumberComponent( r2base::Node& owner_node ) : r2base::Component( owner_node )
		, mLabelComponent( nullptr )
	{}

	std::unique_ptr<NumberComponent> NumberComponent::Create( r2base::Node& owner_node )
	{
		std::unique_ptr<NumberComponent> ret( new ( std::nothrow ) NumberComponent( owner_node ) );
		if( !ret || !ret->Init() )
		{
			ret.reset();
		}

		return ret;
	}

	void NumberComponent::SetNumber( const int new_number )
	{
		mLabelComponent->SetString( std::to_string( new_number ) );
	}
}