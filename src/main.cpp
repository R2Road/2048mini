#include "pch.h"

#if defined( DEBUG ) || defined( _DEBUG )
	#include <vld.h>
#endif

#include "r2cm/r2cm_Director.h"
#include "r2bix/r2utility_WindowUtil.h"

#include "DevelopmentMenu.h"

int main()
{
	//
	// Environment : Title
	//
	r2utility::ChangeWindowTitle( L"r2bix" );

	//
	// Environment : Size
	//
	r2utility::ResizeWindow( 960, 960 );

	//
	// Environment : Position
	//
	r2utility::MoveWindow( 0, 0 );

	//
	// Setup
	//
	r2cm::Director director;
	director.Setup( DevelopmentMenu::Create( director ) );

	//
	// Process
	//
	director.Run();

	return 0;
}
