#include "TestMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "test/item/test_p2048mini_numbernode.h"
#include "test/item/test_p2048mini_stage.h"
#include "test/item/test_p2048mini_stageviewnode.h"

r2cm::MenuUp TestMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
	) );

	{
		ret->AddItem( '1', test_p2048mini_stage::Basic::GetInstance() );
		ret->AddItem( '2', test_p2048mini_stage::MoveReadyTest::GetInstance() );
		ret->AddItem( '3', test_p2048mini_stage::MoveTest::GetInstance() );
		ret->AddItem( '4', test_p2048mini_stage::MergeTest::GetInstance() );
		ret->AddItem( '5', test_p2048mini_stage::EmptyCheck::GetInstance() );
		ret->AddItem( '6', test_p2048mini_stage::MovableCheck::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( 'q', test_p2048mini_numbernode::Generate::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( 'a', test_p2048mini_stageviewnode::Generate::GetInstance() );
		ret->AddItem( 's', test_p2048mini_stageviewnode::Setup_Render::GetInstance() );
		ret->AddItem( 'd', test_p2048mini_stageviewnode::UpdateView::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Exit"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				return r2cm::eItemLeaveAction::Exit;
			}
		);
	}

	return ret;
}