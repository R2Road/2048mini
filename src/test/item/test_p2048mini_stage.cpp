#include "test_p2048mini_stage.h"

#include <conio.h>
#include <iomanip>

#include "r2bix/r2base_Director.h"
#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

#include "p2048mini/p2048mini_Stage.h"


namespace test_p2048mini_stage
{
	void PrintStage( const p2048mini::Stage& stage )
	{
		int val = 0;
		for( uint32_t y = 0; stage.GetHeight() > y; ++y )
		{
			for( uint32_t x = 0; stage.GetWidth() > x; ++x )
			{
				val = stage.GetNumber( x, y );

				std::cout << std::setw( 2 ) << std::right << val;
				std::cout << std::setw( 1 ) << std::left; // roll back

				std::cout << r2cm::tab;
			}

			std::cout << r2cm::linefeed;
		}
	}



	r2cm::iItem::TitleFuncT Generate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : Generate";
		};
	}
	r2cm::iItem::DoFuncT Generate::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( const uint32_t width = 4 );
			DECLARATION_MAIN( const uint32_t height = 3 );
			DECLARATION_MAIN( p2048mini::Stage stage( width, height ) );

			std::cout << r2cm::split;
			{
				EXPECT_EQ( width, stage.GetWidth() );
				EXPECT_EQ( height, stage.GetHeight() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( PrintStage( stage ) );
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( width - 1, stage.GetMaxX() );
				EXPECT_EQ( height - 1, stage.GetMaxY() );
				EXPECT_EQ( width * height, stage.Size() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Add_And_Remove::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : Add, Remove";
		};
	}
	r2cm::iItem::DoFuncT Add_And_Remove::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( p2048mini::Stage stage( 4, 3 ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( stage.Add( 2, 2, 64 ) );
				EXPECT_EQ( 64, stage.GetNumber( 2, 2 ) );
				PROCESS_MAIN( PrintStage( stage ) );
			}

			std::cout << r2cm::split;


			{
				PROCESS_MAIN( stage.Remove( 2, 2 ) );
				EXPECT_EQ( 0, stage.GetNumber( 2, 2 ) );
				PROCESS_MAIN( PrintStage( stage ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT EmptyCheck::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : Empty Check";
		};
	}
	r2cm::iItem::DoFuncT EmptyCheck::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( p2048mini::Stage stage( 2, 2 ) );
			EXPECT_EQ( 0, stage.GetCurrentNumberCount() );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Add New" << r2cm::linefeed2;

				PROCESS_MAIN( stage.Add( 0, 0, 7 ) );
				EXPECT_EQ( 1, stage.GetCurrentNumberCount() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( stage.Add( 0, 1, 7 ) );
				PROCESS_MAIN( stage.Add( 1, 0, 7 ) );
				EXPECT_EQ( 3, stage.GetCurrentNumberCount() );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Over Write" << r2cm::linefeed2;

				PROCESS_MAIN( stage.Add( 0, 1, 7 ) );
				EXPECT_EQ( 3, stage.GetCurrentNumberCount() );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Remove" << r2cm::linefeed2;

				PROCESS_MAIN( stage.Remove( 0, 1 ) );
				EXPECT_EQ( 2, stage.GetCurrentNumberCount() );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Full" << r2cm::linefeed2;

				PROCESS_MAIN( stage.Add( 0, 1, 7 ) );
				PROCESS_MAIN( stage.Add( 1, 1, 7 ) );
				EXPECT_EQ( 4, stage.GetCurrentNumberCount() );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( stage.IsFull() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( stage.Remove( 0, 1 ) );
				EXPECT_FALSE( stage.IsFull() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}