#include "TestMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "test/item/test_p2048mini_gameprocessor.h"
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
		ret->AddItem( '1', test_p2048mini_stage::Generate::GetInstance() );
		ret->AddItem( '2', test_p2048mini_stage::Add_And_Remove::GetInstance() );
		ret->AddItem( '3', test_p2048mini_stage::IsIn::GetInstance() );
		ret->AddItem( '4', test_p2048mini_stage::EmptyCheck::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( 'q', test_p2048mini_gameprocessor::MoveReadyTest::GetInstance() );
		ret->AddItem( 'w', test_p2048mini_gameprocessor::MoveTest::GetInstance() );
		ret->AddItem( 'e', test_p2048mini_gameprocessor::MergeTest::GetInstance() );
		ret->AddItem( 'r', test_p2048mini_gameprocessor::MovableCheck::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( 'a', test_p2048mini_numbernode::Generate::GetInstance() );
		ret->AddItem( 's', test_p2048mini_numbernode::SetNumber::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( 'z', test_p2048mini_stageviewnode::Generate::GetInstance() );
		ret->AddItem( 'x', test_p2048mini_stageviewnode::Setup_Render::GetInstance() );
		ret->AddItem( 'c', test_p2048mini_stageviewnode::UpdateView::GetInstance() );


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