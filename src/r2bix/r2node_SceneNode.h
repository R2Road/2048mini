#pragma once

#include "r2base_Node.h"

#include "r2render_Camera.h"
#include "r2render_Texture.h"

namespace r2base
{
	class Director;
}

namespace r2node
{
	using SceneNodeUp = std::unique_ptr<class SceneNode>;

	class SceneNode : public r2base::Node
	{
	public:
		SceneNode( r2base::Director& director );

		static SceneNodeUp Create( r2base::Director& director );

		//
		// Override
		//
	private:
		void Render( const r2render::Camera* const /*camera*/, r2render::iRenderTarget* const /*render_target*/, r2::PointInt /*offset*/ ) override {}

		//
		//
		//
	public:
		void Render();

	protected:
		r2render::Camera mCamera;
		r2render::Texture mRenderTarget;
	};
}