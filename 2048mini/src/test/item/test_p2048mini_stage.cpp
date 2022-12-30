#include "test_p2048mini_stage.h"

#include <conio.h>
#include <iomanip>

#include "r2bix/r2base_Director.h"
#include "r2cm/r2cm_ostream.h"
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



	r2cm::TitleFunctionT Generate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : Generate";
		};
	}
	r2cm::DoFunctionT Generate::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
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

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Add_Remove_ClearAll::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : Add, Remove, ClearAll";
		};
	}
	r2cm::DoFunctionT Add_Remove_ClearAll::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( p2048mini::Stage stage( 4, 3 ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Add" << r2cm::linefeed2;

				PROCESS_MAIN( stage.Add( 2, 2, 64 ) );
				EXPECT_EQ( 64, stage.GetNumber( 2, 2 ) );

				PrintStage( stage );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Remove" << r2cm::linefeed2;

				PROCESS_MAIN( stage.Remove( 2, 2 ) );
				EXPECT_EQ( 0, stage.GetNumber( 2, 2 ) );

				PrintStage( stage );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( stage.Add( 1, 1, 1 ) );
				PROCESS_MAIN( stage.Add( 1, 2, 1 ) );
				PROCESS_MAIN( stage.Add( 1, 3, 1 ) );

				PrintStage( stage );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Clear All" << r2cm::linefeed2;

				PROCESS_MAIN( stage.ClearAll() );
				EXPECT_EQ( 0, stage.GetNumber( 1, 1 ) );
				EXPECT_EQ( 0, stage.GetNumber( 1, 2 ) );
				EXPECT_EQ( 0, stage.GetNumber( 1, 3 ) );

				PrintStage( stage );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT IsIn::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : IsIn";
		};
	}
	r2cm::DoFunctionT IsIn::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( p2048mini::Stage stage( 2, 2 ) );

			std::cout << r2cm::split;

			{
				EXPECT_TRUE( stage.IsIn( 0, 0 ) );
				EXPECT_TRUE( stage.IsIn( 1, 0 ) );
				EXPECT_TRUE( stage.IsIn( 1, 1 ) );
				EXPECT_TRUE( stage.IsIn( 0, 1 ) );
			}

			std::cout << r2cm::split;

			{
				EXPECT_FALSE( stage.IsIn( -1, -1 ) );
				EXPECT_FALSE( stage.IsIn( -1, 2 ) );
				EXPECT_FALSE( stage.IsIn( 2, -1 ) );
				EXPECT_FALSE( stage.IsIn( 2, 2 ) );

				std::cout << r2cm::linefeed;

				EXPECT_FALSE( stage.IsIn( -1, 0 ) );
				EXPECT_FALSE( stage.IsIn( 2, 0 ) );
				EXPECT_FALSE( stage.IsIn( 0, 2 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT NumberCount_EmptyCount_IsFull::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : NumberCount, EmptyCount, IsFull";
		};
	}
	r2cm::DoFunctionT NumberCount_EmptyCount_IsFull::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( p2048mini::Stage stage( 2, 2 ) );
			EXPECT_EQ( 0, stage.GetNumberSpaceCount() );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Add New" << r2cm::linefeed2;

				PROCESS_MAIN( stage.Add( 0, 0, 7 ) );
				EXPECT_EQ( 1, stage.GetNumberSpaceCount() );
				EXPECT_EQ( 3, stage.GetEmptySpaceCount() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( stage.Add( 0, 1, 7 ) );
				PROCESS_MAIN( stage.Add( 1, 0, 7 ) );
				EXPECT_EQ( 3, stage.GetNumberSpaceCount() );
				EXPECT_EQ( 1, stage.GetEmptySpaceCount() );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Over Write" << r2cm::linefeed2;

				PROCESS_MAIN( stage.Add( 0, 1, 7 ) );
				EXPECT_EQ( 3, stage.GetNumberSpaceCount() );
				EXPECT_EQ( 1, stage.GetEmptySpaceCount() );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Remove" << r2cm::linefeed2;

				PROCESS_MAIN( stage.Remove( 0, 1 ) );
				EXPECT_EQ( 2, stage.GetNumberSpaceCount() );
				EXPECT_EQ( 2, stage.GetEmptySpaceCount() );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Full" << r2cm::linefeed2;

				PROCESS_MAIN( stage.Add( 0, 1, 7 ) );
				PROCESS_MAIN( stage.Add( 1, 1, 7 ) );
				EXPECT_EQ( 4, stage.GetNumberSpaceCount() );
				EXPECT_EQ( 0, stage.GetEmptySpaceCount() );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( stage.IsFull() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( stage.Remove( 0, 1 ) );
				EXPECT_FALSE( stage.IsFull() );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Lock::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : Lock";
		};
	}
	r2cm::DoFunctionT Lock::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( p2048mini::Stage stage( 2, 2 ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Lock" << r2cm::linefeed2;

				PROCESS_MAIN( stage.Lock( 0, 0 ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( stage.IsLock( 0, 0 ) );
				EXPECT_FALSE( stage.IsLock( 1, 0 ) );
				EXPECT_FALSE( stage.IsLock( 1, 1 ) );
				EXPECT_FALSE( stage.IsLock( 0, 1 ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( stage.Lock( 0, 1 ) );
				PROCESS_MAIN( stage.Lock( 1, 1 ) );
				PROCESS_MAIN( stage.Lock( 1, 0 ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( stage.IsLock( 0, 1 ) );
				EXPECT_TRUE( stage.IsLock( 1, 1 ) );
				EXPECT_TRUE( stage.IsLock( 1, 0 ) );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ ClearAllFlags" << r2cm::linefeed2;

				PROCESS_MAIN( stage.ClearAllFlags() );

				std::cout << r2cm::linefeed;

				EXPECT_FALSE( stage.IsLock( 0, 0 ) );
				EXPECT_FALSE( stage.IsLock( 1, 0 ) );
				EXPECT_FALSE( stage.IsLock( 1, 1 ) );
				EXPECT_FALSE( stage.IsLock( 0, 1 ) );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ ClearAll" << r2cm::linefeed2;

				PROCESS_MAIN( stage.Lock( 0, 0 ) );
				PROCESS_MAIN( stage.Lock( 0, 1 ) );
				PROCESS_MAIN( stage.Lock( 1, 1 ) );
				PROCESS_MAIN( stage.Lock( 1, 0 ) );
				PROCESS_MAIN( stage.ClearAll() );

				std::cout << r2cm::linefeed;

				EXPECT_FALSE( stage.IsLock( 0, 0 ) );
				EXPECT_FALSE( stage.IsLock( 1, 0 ) );
				EXPECT_FALSE( stage.IsLock( 1, 1 ) );
				EXPECT_FALSE( stage.IsLock( 0, 1 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Newcomer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : Newcomer";
		};
	}
	r2cm::DoFunctionT Newcomer::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( p2048mini::Stage stage( 2, 2 ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Lock" << r2cm::linefeed2;

				PROCESS_MAIN( stage.SetNewcomer( 0, 0 ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( stage.IsNewcomer( 0, 0 ) );
				EXPECT_FALSE( stage.IsNewcomer( 1, 0 ) );
				EXPECT_FALSE( stage.IsNewcomer( 1, 1 ) );
				EXPECT_FALSE( stage.IsNewcomer( 0, 1 ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( stage.SetNewcomer( 0, 1 ) );
				PROCESS_MAIN( stage.SetNewcomer( 1, 1 ) );
				PROCESS_MAIN( stage.SetNewcomer( 1, 0 ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( stage.IsNewcomer( 0, 1 ) );
				EXPECT_TRUE( stage.IsNewcomer( 1, 1 ) );
				EXPECT_TRUE( stage.IsNewcomer( 1, 0 ) );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ ClearAllFlags" << r2cm::linefeed2;

				PROCESS_MAIN( stage.ClearAllFlags() );

				std::cout << r2cm::linefeed;

				EXPECT_FALSE( stage.IsNewcomer( 0, 0 ) );
				EXPECT_FALSE( stage.IsNewcomer( 1, 0 ) );
				EXPECT_FALSE( stage.IsNewcomer( 1, 1 ) );
				EXPECT_FALSE( stage.IsNewcomer( 0, 1 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}