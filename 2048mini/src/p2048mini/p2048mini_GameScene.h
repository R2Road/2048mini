#pragma once

#include "r2bix/r2node_SceneNode.h"

namespace p2048mini
{
	class GameScene : public r2node::SceneNode
	{
	private:
		GameScene() = delete;

	public:
		static r2node::SceneNodeUp Create( r2base::Director& director );
	};
}