#include "r2node_SceneNode.h"

#include "r2base_Director.h"
#include "r2component_TransformComponent.h"

namespace r2node
{
	SceneNode::SceneNode( r2base::Director& director ) : r2base::Node( director )
		, mCamera( { director.GetScreenBufferSize().GetWidth() / 2, director.GetScreenBufferSize().GetHeight() / 2 }, director.GetScreenBufferSize() )
		, mRenderTarget( director.GetScreenBufferSize().GetWidth(), director.GetScreenBufferSize().GetHeight(), '@' )
	{}

	SceneNodeUp SceneNode::Create( r2base::Director& director )
	{
		SceneNodeUp ret( new ( std::nothrow ) SceneNode( director ) );
		if( !ret || !ret->Init() )
		{
			ret.reset();
		}

		return ret;
	}

	void SceneNode::Render()
	{
		mRenderTarget.FillAll( ' ' );

		r2base::Node::Render( &mCamera, &mRenderTarget, mTransformComponent->GetPosition() );

		mDirector.Write2BackBuffer( &mRenderTarget );
	}
}