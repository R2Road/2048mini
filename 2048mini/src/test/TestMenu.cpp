#include "TestMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

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
		ret->AddItem( '1', test_p2048mini_stage::Generate() );
		ret->AddItem( '2', test_p2048mini_stage::Add_Remove_ClearAll() );
		ret->AddItem( '3', test_p2048mini_stage::IsIn() );
		ret->AddItem( '4', test_p2048mini_stage::NumberCount_EmptyCount_IsFull() );
		ret->AddItem( '5', test_p2048mini_stage::Lock() );
		ret->AddItem( '6', test_p2048mini_stage::Newcomer() );

		ret->AddLineFeed();

		ret->AddItem( 'q', test_p2048mini_gameprocessor::MoveReadyTest() );
		ret->AddItem( 'w', test_p2048mini_gameprocessor::MoveTest() );
		ret->AddItem( 'e', test_p2048mini_gameprocessor::MergeTest() );
		ret->AddItem( 'r', test_p2048mini_gameprocessor::MovableCheck() );

		ret->AddLineFeed();

		ret->AddItem( 'a', test_p2048mini_numbernode::Generate() );
		ret->AddItem( 's', test_p2048mini_numbernode::SetNumber() );

		ret->AddLineFeed();

		ret->AddItem( 'z', test_p2048mini_stageviewnode::Generate() );
		ret->AddItem( 'x', test_p2048mini_stageviewnode::Setup_Render() );
		ret->AddItem( 'c', test_p2048mini_stageviewnode::UpdateView() );


		ret->AddSplit();


		ret->AddItem(
			27
			, r2cm::eColor::FG_White
			, []()->const char* { return "Exit"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				return r2cm::eItemLeaveAction::Exit;
			}
		);
	}

	return ret;
}