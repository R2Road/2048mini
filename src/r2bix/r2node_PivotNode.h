#pragma once

#include "r2base_Node.h"

namespace r2base
{
	class Director;
}

namespace r2node
{
	class PivotNode : public r2base::Node
	{
	private:
		PivotNode() = delete;

	public:
		static r2base::NodeUp Create( r2base::Director& director );
	};
}