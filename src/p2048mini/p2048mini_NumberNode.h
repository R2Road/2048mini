#pragma once

#include "r2bix/r2base_Node.h"

namespace r2base
{
	class Director;
}

namespace p2048mini
{
	class NumberNode : public r2base::Node
	{
	private:
		NumberNode() = delete;

	public:
		static r2base::NodeUp Create( r2base::Director& director );
	};
}