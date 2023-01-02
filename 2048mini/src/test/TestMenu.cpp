#include "TestMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test/item/test_p2048mini_gameprocessor.h"
#include "test/item/test_p2048mini_numbernode.h"
#include "test/item/test_p2048mini_stage.h"
#include "test/item/test_p2048mini_stageviewnode.h"

r2cm::TitleFunctionT TestMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Test Menu";
	};
}
r2cm::DescriptionFunctionT TestMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2cm::WriteFunctionT TestMenu::GetWriteFunction() const
{
	return []( r2cm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_p2048mini_stage::Generate() );
		ret->AddItem( '2', test_p2048mini_stage::Add_Remove() );
		ret->AddItem( '3', test_p2048mini_stage::IsIn() );
		ret->AddItem( '4', test_p2048mini_stage::NumberCount_EmptyCount_IsFull() );
		ret->AddItem( '5', test_p2048mini_stage::Lock() );
		ret->AddItem( '6', test_p2048mini_stage::Newcomer() );
		ret->AddItem( '7', test_p2048mini_stage::Reset() );

		ret->AddLineFeed();

		ret->AddItem( 'q', test_p2048mini_gameprocessor::MoveReady_Pivot_1() );
		ret->AddItem( 'w', test_p2048mini_gameprocessor::MoveReady_Pivot_2() );
		ret->AddItem( 'e', test_p2048mini_gameprocessor::MoveReady_Pivot_3() );
		ret->AddItem( 'r', test_p2048mini_gameprocessor::Move() );
		ret->AddItem( 't', test_p2048mini_gameprocessor::Merge() );
		ret->AddItem( 'y', test_p2048mini_gameprocessor::MovableCheck() );

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
			, r2cm::eColor::BG_Purple
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eDoLeaveAction
			{
				return r2cm::eDoLeaveAction::Exit;
			}
		);
	};
}