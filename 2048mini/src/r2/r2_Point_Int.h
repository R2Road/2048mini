#pragma once

#include "r2_Point.h"

namespace r2
{
	using PointInt = r2::Point<int>;

	struct Hash4PointInt
	{
		std::size_t operator()( const r2::PointInt& point ) const { return ( point.GetY() * 10000 ) + point.GetX(); }
	};
}