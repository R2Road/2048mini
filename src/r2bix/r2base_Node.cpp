#include "r2base_Node.h"

namespace r2base
{
	Node::Node( Director& director ) :
		mDirector( director )
		, mbVisible( true )
		, mComponentContainer()
		, mChildContainer()

		, mTransformComponent( nullptr )
	{}

	std::unique_ptr<Node> Node::Create( r2base::Director& director )
	{
		std::unique_ptr<Node> ret( new ( std::nothrow ) Node( director ) );
		if( !ret || !ret->Init() )
		{
			ret.reset();
		}

		return ret;
	}

	bool Node::Init()
	{
		//
		// Transform
		//
		mTransformComponent = AddComponent<r2component::TransformComponent>();

		return true;
	}

	void Node::Update( const float delta_time )
	{
		for( auto& c : mComponentContainer )
		{
			c->Update( delta_time );
		}

		for( auto& c : mChildContainer )
		{
			c->Update( delta_time );
		}
	}

	void Node::Render( const r2render::Camera* const camera, r2render::iRenderTarget* const render_target, r2::PointInt offset )
	{
		if( !mbVisible )
		{
			return;
		}

		for( auto& c : mComponentContainer )
		{
			c->Render( camera, render_target, offset );
		}

		offset += mTransformComponent->GetPosition();
		for( auto& c : mChildContainer )
		{
			c->Render( camera, render_target, offset );
		}
	}
}