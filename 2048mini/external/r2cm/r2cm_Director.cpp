#include "r2cm_Director.h"

#include <conio.h>
#include <utility>

#include "r2cm_iItem.h"
#include "r2cm_ostream.h"

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
			//case eItemLeaveAction::None: break;

			case eItemLeaveAction::Pause:
				std::cout << r2cm::linefeed;
				system( "pause" );				
				break;

			case eItemLeaveAction::Exit:
				return;
			}
		}
	}
}