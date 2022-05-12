#if defined( DEBUG ) || defined( _DEBUG )
	#include <vld.h>
#endif

#include "r2cm/r2cm_WindowUtility.h"

#define DEVELOPMENT_2048MINI 1

#if defined( DEVELOPMENT_2048MINI ) && ( DEVELOPMENT_2048MINI == 1 )

	#include "r2cm/r2cm_Director.h"
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
	r2cm::WindowUtility::ChangeTitle( L"2048mini" );

	//
	// Environment : Size
	//
	r2cm::WindowUtility::Resize( 960, 960 );

	//
	// Environment : Position
	//
	r2cm::WindowUtility::Move( 0, 0 );

	//
	// Setup & Run
	//
#if defined( DEVELOPMENT_2048MINI ) && ( DEVELOPMENT_2048MINI == 1 )

	r2cm::Director director;
	director.Setup( DevelopmentMenu::Create( director ) );
	director.Run();

#else

	r2base::Director director;
	director.Setup( p2048mini::GameScene::Create( director ) );
	director.Run();

#endif

	return 0;
}
