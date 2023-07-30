#include "DevelopmentMenu.h"

#include <string>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2base_VersionInfo.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_VersionInfo.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "p2048mini/p2048mini_GameScene.h"
#include "p2048mini/p2048mini_VersionInfo.h"

#include "test/TestMenu.h"

r2tm::TitleFunctionT DevelopmentMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string( "Development Menu" )
			+ " : " "<" + "C++17" + ">"
			+ ", " "<" + "MS C/C++ : " + std::to_string( _MSC_VER ) + ">"
			+ ", " "<" + r2tm::VersionInfo.String4Version + ">"
			+ ", " "<" + r2base::VersionInfo.String4Version + ">"
			+ ", " "<" + p2048mini::VersionInfo.String4Version + ">";
		return ret.c_str();
	};
}
r2tm::DescriptionFunctionT DevelopmentMenu::GetDescriptionFunction() const
{
	return []()->const char* { return p2048mini::VersionInfo.String4SubjectOfAProject; };
}
r2tm::WriteFunctionT DevelopmentMenu::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* ret )
	{
		ret->AddItem(
			'1'
			, r2tm::eColor::FG_White
			, []()->const char* { return "Test"; }
			, []()->r2tm::eDoLeaveAction
			{
				// 2022.04.11 by R2Road
				// 인자로 넘어온 director 를 사용해도 되지만 아래 코드와의 일관성을 위해 새 r2tm::Director를 만들어 돌린다.

				//
				// Setup
				//
				r2tm::Director director;
				director.Setup( TestMenu() );

				//
				// Process
				//
				director.Run();

				return r2tm::eDoLeaveAction::None;
			}
		);



		ret->AddLineFeed();



		ret->AddItem(
			32
			, r2tm::eColor::BG_Blue
			, []()->const char* { return "2048mini"; }
			, []()->r2tm::eDoLeaveAction
			{
				r2tm::WindowUtility::Resize( 562, 800 );
				r2tm::WindowUtility::Move( 0, 0 );

				{
					//
					// Setup
					//
					r2base::Director director;
					director.Setup( p2048mini::GameScene::Create( director ) );

					//
					// Environment : ScrollBar | Maximize Button
					//
					r2tm::WindowUtility::ScrollBarVisible( false );
					r2tm::WindowUtility::MaximizeButtonEnable( false );
					r2tm::WindowUtility::ResizingByDraggingEnable( false );

					//
					// Process
					//
					director.Run();
				}

				r2tm::WindowUtility::Resize( 960, 960 );
				r2tm::WindowUtility::Move( 0, 0 );
				r2tm::WindowUtility::ScrollBarVisible( true );
				r2tm::WindowUtility::MaximizeButtonEnable( true );
				r2tm::WindowUtility::ResizingByDraggingEnable( true );

				return r2tm::eDoLeaveAction::None;
			}
		);


		ret->AddSplit();


		ret->AddExit( 27 );
	};
}