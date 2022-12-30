#include "DevelopmentMenu.h"

#include <string>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2base_VersionInfo.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_VersionInfo.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "p2048mini/p2048mini_GameScene.h"
#include "p2048mini/p2048mini_VersionInfo.h"

#include "test/TestMenu.h"

r2cm::TitleFunctionT DevelopmentMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string( "Development Menu" )
			+ " : <" + r2cm::VersionInfo.String4Version + ">"
			+ " : <" + r2base::VersionInfo.String4Version + ">"
			+ " : <" + p2048mini::VersionInfo.String4Version + ">";
		return ret.c_str();
	};
}
r2cm::DescriptionFunctionT DevelopmentMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2cm::WriteFunctionT DevelopmentMenu::GetWriteFunction() const
{
	return []( r2cm::MenuProcessor* ret )
	{
		ret->AddItem(
			'1'
			, r2cm::eColor::FG_White
			, []()->const char* { return "Test"; }
			, []()->r2cm::eDoLeaveAction
			{
				// 2022.04.11 by R2Road
				// ���ڷ� �Ѿ�� director �� ����ص� ������ �Ʒ� �ڵ���� �ϰ����� ���� �� r2cm::Director�� ����� ������.

				//
				// Setup
				//
				r2cm::Director director;
				director.Setup( TestMenu() );

				//
				// Process
				//
				director.Run();

				return r2cm::eDoLeaveAction::None;
			}
		);



		ret->AddLineFeed();



		ret->AddItem(
			32
			, r2cm::eColor::BG_Blue
			, []()->const char* { return "2048mini"; }
			, []()->r2cm::eDoLeaveAction
			{
				r2cm::WindowUtility::Resize( 562, 800 );
				r2cm::WindowUtility::Move( 0, 0 );

				{
					//
					// Setup
					//
					r2base::Director director;
					director.Setup( p2048mini::GameScene::Create( director ) );

					//
					// Environment : ScrollBar | Maximize Button
					//
					r2cm::WindowUtility::ScrollBarVisible( false );
					r2cm::WindowUtility::MaximizeButtonEnable( false );
					r2cm::WindowUtility::ResizingByDraggingEnable( false );

					//
					// Process
					//
					director.Run();
				}

				r2cm::WindowUtility::Resize( 960, 960 );
				r2cm::WindowUtility::Move( 0, 0 );
				r2cm::WindowUtility::ScrollBarVisible( true );
				r2cm::WindowUtility::MaximizeButtonEnable( true );
				r2cm::WindowUtility::ResizingByDraggingEnable( true );

				return r2cm::eDoLeaveAction::None;
			}
		);


		ret->AddSplit();


		ret->AddItem(
			27
			, r2cm::eColor::FG_White
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eDoLeaveAction
			{
				return r2cm::eDoLeaveAction::Exit;
			}
		);
	};
}