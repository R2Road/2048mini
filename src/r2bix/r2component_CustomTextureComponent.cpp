#include "r2component_CustomTextureComponent.h"

#include "r2base_DebugConfig.h"
#include "r2base_Node.h"
#include "r2component_TransformComponent.h"
#include "r2render_Camera.h"

namespace r2component
{
	CustomTextureComponent::CustomTextureComponent( r2base::Node& owner_node ) : r2base::Component( owner_node )
		, mTexture( 1, 1, ' ')
	{}

	std::unique_ptr<CustomTextureComponent> CustomTextureComponent::Create( r2base::Node& owner_node )
	{
		std::unique_ptr<CustomTextureComponent> ret( new ( std::nothrow ) CustomTextureComponent( owner_node ) );
		if( !ret || !ret->Init() )
		{
			ret.reset();
		}

		return ret;
	}
}