#include "pch.h"
#include "r2cm_Director.h"

#include <conio.h>
#include <utility>

#include "r2cm_eTestEndAction.h"

namespace r2cm
{
	Director::Director() : mMenu()
	{}

	void Director::Setup( MenuUp menu )
	{
		mMenu = std::move( menu );
	}

	void Director::Run()
	{
		int input = 0;
		while( true )
		{
			system( "cls" );

			mMenu->ShowTitle();
			mMenu->ShowDescription();
			mMenu->ShowMenu();
			input = _getch();

			system( "cls" );

			switch( mMenu->Do( input ) )
			{
			//case eTestEndAction::None: break;

			case eTestEndAction::Pause:
				std::cout << r2::linefeed;
				system( "pause" );				
				break;

			case eTestEndAction::Exit:
				return;
			}
		}
	}
}