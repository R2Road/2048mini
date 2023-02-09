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

			LF();
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
			LS();

			DECLARATION_MAIN( const uint32_t width = 4 );
			DECLARATION_MAIN( const uint32_t height = 3 );
			DECLARATION_MAIN( p2048mini::Stage stage( width, height ) );

			LS();

			{
				EXPECT_EQ( width, stage.GetWidth() );
				EXPECT_EQ( height, stage.GetHeight() );
			}

			LS();

			{
				PROCESS_MAIN( PrintStage( stage ) );
			}

			LS();

			{
				EXPECT_EQ( width - 1, stage.GetMaxX() );
				EXPECT_EQ( height - 1, stage.GetMaxY() );
				EXPECT_EQ( width * height, stage.Size() );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Add_Remove::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : Add, Remove";
		};
	}
	r2cm::DoFunctionT Add_Remove::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( p2048mini::Stage stage( 4, 3 ) );

			LS();

			{
				OUTPUT_SUBJECT( "Add" );

				LF();

				PROCESS_MAIN( stage.Add( 2, 2, 64 ) );
				EXPECT_EQ( 64, stage.GetNumber( 2, 2 ) );

				PrintStage( stage );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Remove" );

				LF();

				PROCESS_MAIN( stage.Remove( 2, 2 ) );
				EXPECT_EQ( 0, stage.GetNumber( 2, 2 ) );

				PrintStage( stage );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Out of Range" );

				LF();

				PROCESS_MAIN( stage.Add( 1, 1, 1 ) );
				PROCESS_MAIN( stage.Add( 1, 2, 1 ) );
				PROCESS_MAIN( stage.Add( 1, 3, 1 ) );

				PrintStage( stage );
			}

			LS();

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
			LS();

			DECLARATION_MAIN( p2048mini::Stage stage( 2, 2 ) );

			LS();

			{
				EXPECT_TRUE( stage.IsIn( 0, 0 ) );
				EXPECT_TRUE( stage.IsIn( 1, 0 ) );
				EXPECT_TRUE( stage.IsIn( 1, 1 ) );
				EXPECT_TRUE( stage.IsIn( 0, 1 ) );
			}

			LS();

			{
				EXPECT_FALSE( stage.IsIn( -1, -1 ) );
				EXPECT_FALSE( stage.IsIn( -1, 2 ) );
				EXPECT_FALSE( stage.IsIn( 2, -1 ) );
				EXPECT_FALSE( stage.IsIn( 2, 2 ) );

				LF();

				EXPECT_FALSE( stage.IsIn( -1, 0 ) );
				EXPECT_FALSE( stage.IsIn( 2, 0 ) );
				EXPECT_FALSE( stage.IsIn( 0, 2 ) );
			}

			LS();

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
			LS();

			DECLARATION_MAIN( p2048mini::Stage stage( 2, 2 ) );
			EXPECT_EQ( 0, stage.GetNumberSpaceCount() );

			LS();

			{
				OUTPUT_SUBJECT( "Add New" );

				LF();

				PROCESS_MAIN( stage.Add( 0, 0, 7 ) );
				EXPECT_EQ( 1, stage.GetNumberSpaceCount() );
				EXPECT_EQ( 3, stage.GetEmptySpaceCount() );

				LF();

				PROCESS_MAIN( stage.Add( 0, 1, 7 ) );
				PROCESS_MAIN( stage.Add( 1, 0, 7 ) );
				EXPECT_EQ( 3, stage.GetNumberSpaceCount() );
				EXPECT_EQ( 1, stage.GetEmptySpaceCount() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Over Write" );

				LF();

				PROCESS_MAIN( stage.Add( 0, 1, 7 ) );
				EXPECT_EQ( 3, stage.GetNumberSpaceCount() );
				EXPECT_EQ( 1, stage.GetEmptySpaceCount() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Remove" );

				LF();

				PROCESS_MAIN( stage.Remove( 0, 1 ) );
				EXPECT_EQ( 2, stage.GetNumberSpaceCount() );
				EXPECT_EQ( 2, stage.GetEmptySpaceCount() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Full" );

				LF();

				PROCESS_MAIN( stage.Add( 0, 1, 7 ) );
				PROCESS_MAIN( stage.Add( 1, 1, 7 ) );
				EXPECT_EQ( 4, stage.GetNumberSpaceCount() );
				EXPECT_EQ( 0, stage.GetEmptySpaceCount() );

				LF();

				EXPECT_TRUE( stage.IsFull() );
			}

			LS();

			{
				PROCESS_MAIN( stage.Remove( 0, 1 ) );
				EXPECT_FALSE( stage.IsFull() );
			}

			LS();

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
			LS();

			DECLARATION_MAIN( p2048mini::Stage stage( 2, 2 ) );

			LS();

			{
				OUTPUT_SUBJECT( "Lock" );

				LF();

				PROCESS_MAIN( stage.Lock( 0, 0 ) );

				LF();

				EXPECT_TRUE( stage.IsLock( 0, 0 ) );
				EXPECT_FALSE( stage.IsLock( 1, 0 ) );
				EXPECT_FALSE( stage.IsLock( 1, 1 ) );
				EXPECT_FALSE( stage.IsLock( 0, 1 ) );

				LF();

				PROCESS_MAIN( stage.Lock( 0, 1 ) );
				PROCESS_MAIN( stage.Lock( 1, 1 ) );
				PROCESS_MAIN( stage.Lock( 1, 0 ) );

				LF();

				EXPECT_TRUE( stage.IsLock( 0, 1 ) );
				EXPECT_TRUE( stage.IsLock( 1, 1 ) );
				EXPECT_TRUE( stage.IsLock( 1, 0 ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "ClearAllFlags" );

				LF();

				PROCESS_MAIN( stage.ClearAllFlags() );

				LF();

				EXPECT_FALSE( stage.IsLock( 0, 0 ) );
				EXPECT_FALSE( stage.IsLock( 1, 0 ) );
				EXPECT_FALSE( stage.IsLock( 1, 1 ) );
				EXPECT_FALSE( stage.IsLock( 0, 1 ) );
			}

			LS();

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
			LS();

			DECLARATION_MAIN( p2048mini::Stage stage( 2, 2 ) );

			LS();

			{
				OUTPUT_SUBJECT( "Lock" );

				LF();

				PROCESS_MAIN( stage.SetNewcomer( 0, 0 ) );

				LF();

				EXPECT_TRUE( stage.IsNewcomer( 0, 0 ) );
				EXPECT_FALSE( stage.IsNewcomer( 1, 0 ) );
				EXPECT_FALSE( stage.IsNewcomer( 1, 1 ) );
				EXPECT_FALSE( stage.IsNewcomer( 0, 1 ) );

				LF();

				PROCESS_MAIN( stage.SetNewcomer( 0, 1 ) );
				PROCESS_MAIN( stage.SetNewcomer( 1, 1 ) );
				PROCESS_MAIN( stage.SetNewcomer( 1, 0 ) );

				LF();

				EXPECT_TRUE( stage.IsNewcomer( 0, 1 ) );
				EXPECT_TRUE( stage.IsNewcomer( 1, 1 ) );
				EXPECT_TRUE( stage.IsNewcomer( 1, 0 ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "ClearAllFlags" );

				LF();

				PROCESS_MAIN( stage.ClearAllFlags() );

				LF();

				EXPECT_FALSE( stage.IsNewcomer( 0, 0 ) );
				EXPECT_FALSE( stage.IsNewcomer( 1, 0 ) );
				EXPECT_FALSE( stage.IsNewcomer( 1, 1 ) );
				EXPECT_FALSE( stage.IsNewcomer( 0, 1 ) );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Reset::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : Reset";
		};
	}
	r2cm::DoFunctionT Reset::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( p2048mini::Stage stage( 3, 1 ) );

			LS();

			{
				PROCESS_MAIN( stage.Add( 0, 0, 7 ) );
				EXPECT_EQ( 7, stage.GetNumber( 0, 0 ) );

				LF();

				PROCESS_MAIN( stage.Lock( 1, 0 ) );
				EXPECT_TRUE( stage.IsLock( 1, 0 ) );

				LF();

				PROCESS_MAIN( stage.SetNewcomer( 2, 0 ) );
				EXPECT_TRUE( stage.IsNewcomer( 2, 0 ) );
			}

			LS();

			{
				PROCESS_MAIN( stage.Reset() );
			}

			LS();

			{
				EXPECT_NE( 7, stage.GetNumber( 0, 0 ) );

				LF();

				EXPECT_FALSE( stage.IsLock( 1, 0 ) );

				LF();

				EXPECT_FALSE( stage.IsNewcomer( 2, 0 ) );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}