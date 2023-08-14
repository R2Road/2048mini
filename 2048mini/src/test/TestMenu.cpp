#include "TestMenu.h"

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_ostream.h"

#include "test/item/test_p2048mini_gameprocessor.h"
#include "test/item/test_p2048mini_numbernode.h"
#include "test/item/test_p2048mini_stage.h"
#include "test/item/test_p2048mini_stageviewnode.h"

r2tm::TitleFunctionT TestMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Test Menu";
	};
}
r2tm::DescriptionFunctionT TestMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT TestMenu::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_p2048mini_stage::Declaration() );
		ret->AddItem( '2', test_p2048mini_stage::Add_Remove() );
		ret->AddItem( '3', test_p2048mini_stage::IsIn() );
		ret->AddItem( '4', test_p2048mini_stage::NumberCount_EmptyCount() );
		ret->AddItem( '5', test_p2048mini_stage::IsFull() );
		ret->AddItem( '6', test_p2048mini_stage::Lock() );
		ret->AddItem( '7', test_p2048mini_stage::Newcomer() );
		ret->AddItem( '8', test_p2048mini_stage::Reset() );

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
			, r2tm::eColor::BG_Purple
			, []()->const char* { return "Exit"; }
			, []()->r2tm::eDoLeaveAction
			{
				return r2tm::eDoLeaveAction::Exit;
			}
		);
	};
}