#include "r2cm_Director.h"

#include <conio.h>

#include "r2cm_iMenu.h"

namespace r2cm
{
	Director::Director() : mMenuProcessor( *this )
	{}

	void Director::Setup( const iMenu& menu )
	{
		mMenuProcessor.Reset( menu.GetTitleFunction(), menu.GetDescriptionFunction(), menu.GetWriteFunction() );
	}

	void Director::Run()
	{
		int input = 0;
		while( true )
		{
			system( "cls" );

			mMenuProcessor.ShowTitle();
			mMenuProcessor.ShowDescription();
			mMenuProcessor.ShowItems();
			input = _getch();

			system( "cls" );

			switch( mMenuProcessor.Do( input ) )
			{
			//case eDoLeaveAction::None: break;

			case eDoLeaveAction::Pause:
				system( "pause" );				
				break;

			case eDoLeaveAction::Exit:
				return;
			}
		}
	}
}