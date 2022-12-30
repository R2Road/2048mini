#include "test_p2048mini_gameprocessor.h"

#include <conio.h>
#include <iomanip>

#include "r2bix/r2base_Director.h"
#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "p2048mini/p2048mini_GameProcessor.h"
#include "p2048mini/p2048mini_Stage.h"

#include "r2cm/r2cm_WindowUtility.h"


namespace test_p2048mini_gameprocessor
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



	r2cm::TitleFunctionT MoveReadyTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "GameProcessor : Move Ready";
		};
	}
	r2cm::DoFunctionT MoveReadyTest::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( p2048mini::Stage stage( 4, 4 ) );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( r2::Direction4 move_dir );
				DECLARATION_MAIN( const r2::PointInt center_point( stage.GetWidth() / 2, stage.GetHeight() / 2 ) );
				DECLARATION_MAIN( r2::PointInt pivot_point_1 );
				DECLARATION_MAIN( r2::PointInt pivot_point_2 );

				std::cout << r2cm::linefeed;

				const auto pivot_coord = r2cm::WindowUtility::GetCursorPoint();
				bool bRun = true;
				do
				{
					r2cm::WindowUtility::MoveCursorPoint( pivot_coord );

					std::cout << "Press [W, A, S, D]" << r2cm::linefeed2;

					switch( _getch() )
					{
					case 97: // L
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Left ) );
						break;
					case 100: // R
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Right ) );
						break;
					case 119: // U
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Down ) ); // swap D 4 ez look
						break;
					case 115: // D
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Up ) ); // swap U 4 ez look
						break;

					case 27: // ESC
						bRun = false;
						break;

					default:
						continue;
					}

					std::cout << r2cm::linefeed;

					if( bRun )
					{
						{
							PROCESS_MAIN( pivot_point_1 = center_point + r2::PointInt( center_point.GetX() * move_dir.GetPoint().GetX(), center_point.GetY() * move_dir.GetPoint().GetY() ) );
							PROCESS_MAIN( pivot_point_1.SetX( std::clamp( pivot_point_1.GetX(), 0, static_cast<int32_t>( stage.GetMaxX() ) ) ) );
							PROCESS_MAIN( pivot_point_1.SetY( std::clamp( pivot_point_1.GetY(), 0, static_cast<int32_t>( stage.GetMaxY() ) ) ) );
						}

						std::cout << r2cm::linefeed;

						{
							PROCESS_MAIN( pivot_point_2.Set( pivot_point_1.GetX() * std::abs( move_dir.GetPoint().GetX() ), pivot_point_1.GetY() * std::abs( move_dir.GetPoint().GetY() ) ) );
						}

						std::cout << r2cm::linefeed;

						stage.Reset();
						PROCESS_MAIN( stage.Add( pivot_point_1.GetX(), pivot_point_1.GetY(), 1 ) );
						PROCESS_MAIN( stage.Add( pivot_point_2.GetX(), pivot_point_2.GetY(), 2 ) );
						PROCESS_MAIN( stage.Add( center_point.GetX(), center_point.GetY(), 7 ) );
						PROCESS_MAIN( PrintStage( stage ) );

						std::cout << r2cm::linefeed;

						stage.Reset();

						auto reverse_dir = move_dir;
						reverse_dir.Rotate( true );
						reverse_dir.Rotate( true );
						for( int loop_count = 0; stage.IsIn( pivot_point_2.GetX(), pivot_point_2.GetY() ); ++loop_count )
						{
							for( uint32_t y = 0; stage.GetHeight() > y; ++y )
							{
								for( uint32_t x = 0; stage.GetWidth() > x; ++x )
								{
									r2::PointInt temp_point( x * std::abs( move_dir.GetPoint().GetX() ), y * std::abs( move_dir.GetPoint().GetY() ) );

									if( pivot_point_2.GetX() == temp_point.GetX() && pivot_point_2.GetY() == temp_point.GetY() )
									{
										PROCESS_MAIN( stage.Add( x, y, loop_count ) );
									}
								}
							}

							pivot_point_2 += reverse_dir.GetPoint();
						}
						PROCESS_MAIN( PrintStage( stage ) );
					}
				} while( bRun );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::None;
		};
	}



	r2cm::TitleFunctionT MoveTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "GameProcessor : Move";
		};
	}
	r2cm::DoFunctionT MoveTest::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( p2048mini::Stage stage( 4, 4 ) );
			DECLARATION_MAIN( p2048mini::GameProcessor game_processor( &stage ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( stage.Add( 0, 0, 1 ) );
				PROCESS_MAIN( stage.Add( 0, 1, 2 ) );
				PROCESS_MAIN( stage.Add( 3, 0, 3 ) );
				PROCESS_MAIN( stage.Add( 0, 3, 4 ) );
				PROCESS_MAIN( stage.Add( 3, 3, 8 ) );
				PROCESS_MAIN( PrintStage( stage ) );
			}

			std::cout << r2cm::split;


			{
				const auto pivot_coord = r2cm::WindowUtility::GetCursorPoint();
				bool bRun = true;
				do
				{
					r2cm::WindowUtility::MoveCursorPoint( pivot_coord );

					std::cout << "Press [W, A, S, D]" << r2cm::linefeed2;

					bool has_moved = false;
					switch( _getch() )
					{
					case 97: // L
						PROCESS_MAIN( has_moved = game_processor.Move( r2::Direction4::eState::Left ).has_moved );
						break;
					case 100: // R
						PROCESS_MAIN( has_moved = game_processor.Move( r2::Direction4::eState::Right ).has_moved );
						break;
					case 119: // U
						PROCESS_MAIN( has_moved = game_processor.Move( r2::Direction4::eState::Down ).has_moved ); // swap D 4 ez look
						break;
					case 115: // D
						PROCESS_MAIN( has_moved = game_processor.Move( r2::Direction4::eState::Up ).has_moved ); // swap U 4 ez look
						break;

					case 27: // ESC
						bRun = false;
						break;

					default:
						continue;
					}

					std::cout << r2cm::linefeed;

					PROCESS_MAIN( PrintStage( stage ) );
					std::cout << ( has_moved ? "Move Success" : "Move Failed" ) << r2cm::linefeed;

				} while( bRun );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::None;
		};
	}



	r2cm::TitleFunctionT MergeTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "GameProcessor : Merge";
		};
	}
	r2cm::DoFunctionT MergeTest::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( p2048mini::Stage stage( 4, 1 ) );
			DECLARATION_MAIN( p2048mini::GameProcessor game_processor( &stage ) );

			std::cout << r2cm::split;

			{
				stage.Add( 0, 0, 2 );
				stage.Add( 1, 0, 1 );
				stage.Add( 2, 0, 1 );
				PROCESS_MAIN( PrintStage( stage ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const auto move_result = game_processor.Move( r2::Direction4::eState::Right ) );
				PROCESS_MAIN( PrintStage( stage ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, stage.GetNumber( 2, 0 ) );
				EXPECT_EQ( 2, stage.GetNumber( 3, 0 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, game_processor.GetSum4Merged() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const auto move_result = game_processor.Move( r2::Direction4::eState::Right ) );
				PROCESS_MAIN( PrintStage( stage ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 4, stage.GetNumber( 3, 0 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 4, game_processor.GetSum4Merged() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( stage.Add( 0, 0, 4 ) );
				PROCESS_MAIN( stage.Add( 1, 0, 4 ) );
				PROCESS_MAIN( stage.Add( 2, 0, 4 ) );
				PROCESS_MAIN( PrintStage( stage ) );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto move_result = game_processor.Move( r2::Direction4::eState::Right ) );
				PROCESS_MAIN( PrintStage( stage ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 8, stage.GetNumber( 2, 0 ) );
				EXPECT_EQ( 8, stage.GetNumber( 3, 0 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 16, game_processor.GetSum4Merged() );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT MovableCheck::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "GameProcessor : Movable Check";
		};
	}
	r2cm::DoFunctionT MovableCheck::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Node : �ֺ��� ���ڰ� 0 �̰ų� ���ٸ� �̵� �Ѵ�." << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( p2048mini::Stage stage( 2, 2 ) );
			DECLARATION_MAIN( p2048mini::GameProcessor game_processor( &stage ) );

			std::cout << r2cm::split;

			{
				stage.Add( 0, 0, 7 );
				stage.Add( 0, 1, 7 );
				stage.Add( 1, 0, 7 );
				stage.Add( 1, 1, 7 );
				PrintStage( stage );
				EXPECT_TRUE( game_processor.IsMovable() );
			}

			std::cout << r2cm::split;

			{
				stage.Add( 0, 0, 1 );
				stage.Add( 0, 1, 2 );
				stage.Add( 1, 0, 7 );
				stage.Add( 1, 1, 7 );
				PrintStage( stage );
				EXPECT_TRUE( game_processor.IsMovable() );
			}

			std::cout << r2cm::split;

			{
				stage.Add( 0, 0, 1 );
				stage.Add( 0, 1, 7 );
				stage.Add( 1, 0, 2 );
				stage.Add( 1, 1, 7 );
				PrintStage( stage );
				EXPECT_TRUE( game_processor.IsMovable() );
			}

			std::cout << r2cm::split;

			{
				stage.Add( 0, 0, 1 );
				stage.Add( 0, 1, 2 );
				stage.Add( 1, 0, 3 );
				stage.Add( 1, 1, 7 );
				PrintStage( stage );
				EXPECT_FALSE( game_processor.IsMovable() );
			}

			std::cout << r2cm::split;

			{
				stage.Add( 0, 0, 1 );
				stage.Add( 0, 1, 2 );
				stage.Add( 1, 0, 3 );
				stage.Add( 1, 1, 0 );
				PrintStage( stage );
				EXPECT_TRUE( game_processor.IsMovable() );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}