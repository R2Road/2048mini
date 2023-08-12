#pragma once

#include <iomanip>
#include <iostream>

#include "p2048mini/p2048mini_Stage.h"

namespace p2048minihelper
{
	class STDPrinter4Stage
	{
	private:
		STDPrinter4Stage() = delete;



	public:
		inline static void Print( const p2048mini::Stage& v )
		{
			int val = 0;
			for( uint32_t y = 0; v.GetHeight() > y; ++y )
			{
				for( uint32_t x = 0; v.GetWidth() > x; ++x )
				{
					val = v.GetNumber( x, y );

					std::cout << std::setw( 2 ) << std::right << val;
					std::cout << std::setw( 1 ) << std::left; // roll back

					std::cout << '\t';
				}

				std::cout << '\n';
			}
		}
	};
}