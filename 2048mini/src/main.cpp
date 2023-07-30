#if defined( DEBUG ) || defined( _DEBUG )
	#include "vld/include/vld.h"
#endif

#include "r2tm/r2tm_WindowUtility.h"
#include "p2048mini/p2048mini_VersionInfo.h"

#define DEVELOPMENT_2048MINI 1

#if defined( DEVELOPMENT_2048MINI ) && ( DEVELOPMENT_2048MINI == 1 )

	#include "r2tm/r2tm_Director.h"
	#include "DevelopmentMenu.h"

#else

	#include "r2bix/r2base_Director.h"
	#include "p2048mini/p2048mini_GameScene.h"

#endif

int main()
{
	//
	// Environment : Title
	//
	r2tm::WindowUtility::ChangeTitle( p2048mini::VersionInfo.String4Version );

#if defined( DEVELOPMENT_2048MINI ) && ( DEVELOPMENT_2048MINI == 1 )

	//
	// Environment : Size
	//
	r2tm::WindowUtility::Resize( 960, 960 );

	//
	// Environment : Position
	//
	r2tm::WindowUtility::Move( 0, 0 );

	//
	// Setup & Run
	//
	r2tm::Director director;
	director.Setup( DevelopmentMenu() );
	director.Run();

#else

	//
	// Environment : Size
	//
	r2tm::WindowUtility::Resize( 562, 800 );

	//
	// Environment : Position
	//
	r2tm::WindowUtility::Move( 0, 0 );

	//
	// Setup
	//
	r2base::Director director;
	director.Setup( p2048mini::GameScene::Create( director ) );

	//
	// Environment : ScrollBar | Maximize Button | Frame Lock
	//
	r2tm::WindowUtility::ScrollBarVisible( false );
	r2tm::WindowUtility::MaximizeButtonEnable( false );
	r2tm::WindowUtility::ResizingByDraggingEnable( false );
	r2tm::WindowUtility::QuickEditEnable( false );

	//
	// Run
	//
	director.Run();

#endif

	return 0;
}
