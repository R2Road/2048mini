#pragma once

#include "r2tm_MenuProcessor.h"

namespace r2tm
{
	class iMenu;

	class Director
	{
	public:
		Director();

		void Setup( const iMenu& menu );

		void Run();

	private:
		MenuProcessor mMenuProcessor;
	};
}