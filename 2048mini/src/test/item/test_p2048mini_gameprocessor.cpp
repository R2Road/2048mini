#include "test_p2048mini_gameprocessor.h"

#include <conio.h>
#include <iomanip>

#include "r2bix/r2base_Director.h"
#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

#include "p2048mini/p2048mini_GameProcessor.h"
#include "p2048mini/p2048mini_Stage.h"

#include "r2tm/r2tm_WindowUtility.h"


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

				std::cout << r2tm::tab;
			}

			LF();
		}
	}

	std::ostream& operator<<( std::ostream& o, const r2::PointInt& value )
	{
		return o << "x : " << value.GetX() << "   " "y : " << value.GetY();
	}



	r2tm::TitleFunctionT MoveReady_Pivot_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "GameProcessor : Move Ready - Pivot 1";
		};
	}
	r2tm::DoFunctionT MoveReady_Pivot_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( p2048mini::Stage stage( 4, 4 ) );

			LS();

			DECLARATION_MAIN( r2::Direction4 move_dir );
			DECLARATION_MAIN( const r2::PointInt center( stage.GetWidth() / 2, stage.GetHeight() / 2 ) );
			DECLARATION_MAIN( r2::PointInt pivot_1 );
			DECLARATION_MAIN( r2::PointInt temp );

			LS();

			{
				std::cout << "[     ESC    ] Exit" << r2tm::linefeed;
				std::cout << "[ W, A, S, D ] Move" << r2tm::linefeed;
			}

			LS();

			{
				OUTPUT_VALUE( center );

				LF();

				const auto pivot_cursor_point = r2tm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{

					r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_cursor_point );

					switch( input )
					{
					case 97: // L
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Left ) );
						break;
					case 100: // R
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Right ) );
						break;
					case 119: // U
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Down ) );
						break;
					case 115: // D
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Up ) );
						break;

					default:
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Up ) );
						break;
					}
					OUTPUT_VALUE( move_dir.GetPoint() );

					LF();

					OUTPUT_NOTE( "center를 입력 방향의 끝으로 보내자" );
					OUTPUT_NOTE( "pivot_1이 이동 처리 시작의 기준점이 된다." );

					LF();

					{
						PROCESS_MAIN( temp = r2::PointInt( center.GetX() * move_dir.GetX(), center.GetY() * move_dir.GetY() ) );
						OUTPUT_VALUE( temp );
					}

					LF();

					{
						PROCESS_MAIN( pivot_1 = center + temp );
						OUTPUT_VALUE( pivot_1 );
					}

					LF();

					{
						PROCESS_MAIN( pivot_1.SetX( std::clamp( pivot_1.GetX(), 0, static_cast<int32_t>( stage.GetMaxX() ) ) ) );
						PROCESS_MAIN( pivot_1.SetY( std::clamp( pivot_1.GetY(), 0, static_cast<int32_t>( stage.GetMaxY() ) ) ) );
						OUTPUT_VALUE( pivot_1 );
					}

					LF();

					{
						stage.Reset();
						PROCESS_MAIN( stage.Add( center.GetX(), center.GetY(), 7 ) );
						PROCESS_MAIN( stage.Add( pivot_1.GetX(), pivot_1.GetY(), 1 ) );
						PROCESS_MAIN( PrintStage( stage ) );
					}

					input = _getch();

				} while( 27 != input );
			}

			LS();

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT MoveReady_Pivot_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "GameProcessor : Move Ready - Pivot 2";
		};
	}
	r2tm::DoFunctionT MoveReady_Pivot_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( p2048mini::Stage stage( 4, 4 ) );

			LS();

			DECLARATION_MAIN( r2::Direction4 move_dir );
			DECLARATION_MAIN( const r2::PointInt center( stage.GetWidth() / 2, stage.GetHeight() / 2 ) );
			DECLARATION_MAIN( r2::PointInt pivot_1 );
			DECLARATION_MAIN( r2::PointInt pivot_2 );
			DECLARATION_MAIN( r2::PointInt temp );

			LS();

			{
				std::cout << "[     ESC    ] Exit" << r2tm::linefeed;
				std::cout << "[ W, A, S, D ] Move" << r2tm::linefeed;
			}

			LS();

			{
				OUTPUT_VALUE( center );

				LF();

				const auto pivot_cursor_point = r2tm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{

					r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_cursor_point );

					switch( input )
					{
					case 97: // L
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Left ) );
						break;
					case 100: // R
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Right ) );
						break;
					case 119: // U
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Down ) );
						break;
					case 115: // D
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Up ) );
						break;

					default:
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Up ) );
						break;
					}
					OUTPUT_VALUE( move_dir.GetPoint() );

					LF();

					{
						temp = r2::PointInt( center.GetX() * move_dir.GetX(), center.GetY() * move_dir.GetY() );

						pivot_1 = center + temp;

						pivot_1.SetX( std::clamp( pivot_1.GetX(), 0, static_cast<int32_t>( stage.GetMaxX() ) ) );
						pivot_1.SetY( std::clamp( pivot_1.GetY(), 0, static_cast<int32_t>( stage.GetMaxY() ) ) );
						OUTPUT_VALUE( pivot_1 );
					}

					LF();

					OUTPUT_NOTE( "기준점인 pivot_1 에 abs( move_dir )을 곱해서 pivot_2를 만든다." );
					OUTPUT_NOTE( "pivot_2는 현재 처리할 줄 인지 확인하기 위한 값이다." );
					OUTPUT_NOTE( "각 좌표에 abs( move_dir )을 곱해서 pivot_2와 비교하면 현재 처리할 줄 인지 확인된다." );

					LF();

					{
						PROCESS_MAIN( pivot_2.SetX( pivot_1.GetX() * std::abs( move_dir.GetX() ) ) );
						PROCESS_MAIN( pivot_2.SetY( pivot_1.GetY() * std::abs( move_dir.GetY() ) ) );
						OUTPUT_VALUE( pivot_2 );
					}

					LF();

					{
						stage.Reset();
						PROCESS_MAIN( stage.Add( pivot_1.GetX(), pivot_1.GetY(), 1 ) );
						PROCESS_MAIN( stage.Add( pivot_2.GetX(), pivot_2.GetY(), 2 ) );
						PROCESS_MAIN( stage.Add( center.GetX(), center.GetY(), 7 ) );
						PROCESS_MAIN( PrintStage( stage ) );
					}

					LF();

					{
						OUTPUT_NOTE( "판별 결과" );

						LF();

						stage.Reset();
						for( uint32_t y = 0; stage.GetHeight() > y; ++y )
						{
							for( uint32_t x = 0; stage.GetWidth() > x; ++x )
							{
								//
								// pivot_2를 만드는 것과 같은 방식으로 x, y 를 단순화 한다.
								//
								// 단순화 된 값이 pivot_2 와 같다면 처리 대상이다.
								//
								// pivot_1을 만드는 과정은 신경 쓸 필요 없다.
								// 유효한 pivot_2를 만들기 위해 기준이 될 위치까지 이동시킨 것 이다.
								//
								const r2::PointInt temp_point( x * std::abs( move_dir.GetX() ), y * std::abs( move_dir.GetY() ) );
								stage.Add( x, y, pivot_2 == temp_point );
							}
						}
						PROCESS_MAIN( PrintStage( stage ) );
					}

					input = _getch();

				} while( 27 != input );
			}

			LS();

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT MoveReady_Pivot_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "GameProcessor : Move Ready - Pivot 3";
		};
	}
	r2tm::DoFunctionT MoveReady_Pivot_3::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( p2048mini::Stage stage( 4, 4 ) );

			LS();

			DECLARATION_MAIN( r2::Direction4 move_dir );
			DECLARATION_MAIN( const r2::PointInt center( stage.GetWidth() / 2, stage.GetHeight() / 2 ) );
			DECLARATION_MAIN( r2::PointInt pivot_1 );
			DECLARATION_MAIN( r2::PointInt pivot_2 );
			DECLARATION_MAIN( r2::PointInt temp );

			LS();

			{
				std::cout << "[     ESC    ] Exit" << r2tm::linefeed;
				std::cout << "[ W, A, S, D ] Move" << r2tm::linefeed;
			}

			LS();

			{
				OUTPUT_VALUE( center );

				LF();

				const auto pivot_cursor_point = r2tm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{

					r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_cursor_point );

					switch( input )
					{
					case 97: // L
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Left ) );
						break;
					case 100: // R
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Right ) );
						break;
					case 119: // U
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Down ) );
						break;
					case 115: // D
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Up ) );
						break;

					default:
						PROCESS_MAIN( move_dir.SetState( r2::Direction4::eState::Up ) );
						break;
					}
					OUTPUT_VALUE( move_dir.GetPoint() );

					LF();

					{
						temp = r2::PointInt( center.GetX() * move_dir.GetX(), center.GetY() * move_dir.GetY() );

						pivot_1 = center + temp;

						pivot_1.SetX( std::clamp( pivot_1.GetX(), 0, static_cast<int32_t>( stage.GetMaxX() ) ) );
						pivot_1.SetY( std::clamp( pivot_1.GetY(), 0, static_cast<int32_t>( stage.GetMaxY() ) ) );
						OUTPUT_VALUE( pivot_1 );
					}

					LF();

					{
						pivot_2.SetX( pivot_1.GetX() * std::abs( move_dir.GetX() ) );
						pivot_2.SetY( pivot_1.GetY() * std::abs( move_dir.GetY() ) );
						OUTPUT_VALUE( pivot_2 );
					}

					LF();

					{
						stage.Reset();
						stage.Add( pivot_1.GetX(), pivot_1.GetY(), 1 );
						stage.Add( pivot_2.GetX(), pivot_2.GetY(), 2 );
						stage.Add( center.GetX(), center.GetY(), 7 );
						PROCESS_MAIN( PrintStage( stage ) );
					}

					LF();

					OUTPUT_NOTE( "pivot_1 이 있는 줄 부터 reverse_dir 방향으로 처리한다." );

					LF();

					{
						r2::PointInt temp_point;
						DECLARATION_MAIN( auto reverse_dir = move_dir );
						PROCESS_MAIN( reverse_dir.Rotate( true ) );
						PROCESS_MAIN( reverse_dir.Rotate( true ) );
						OUTPUT_VALUE( reverse_dir.GetPoint() );

						LF();

						//
						// loop_count 1당 stage 한 줄이 처리된다.
						//
						stage.Reset();
						for( int loop_count = 0; stage.IsIn( pivot_2.GetX(), pivot_2.GetY() ); ++loop_count )
						{
							for( uint32_t y = 0; stage.GetHeight() > y; ++y )
							{
								for( uint32_t x = 0; stage.GetWidth() > x; ++x )
								{
									//
									// pivot_2를 만드는 것과 같은 방식으로 x, y 를 단순화 한다.
									//
									// 단순화 된 값이 pivot_2 와 같다면 처리 대상이다.
									//
									// pivot_1을 만드는 과정은 신경 쓸 필요 없다.
									// 유효한 pivot_2를 만들기 위해 기준이 될 위치까지 이동시킨 것 이다.
									//
									temp_point.Set( x * std::abs( move_dir.GetX() ), y * std::abs( move_dir.GetY() ) );

									if( pivot_2 == temp_point )
									{
										stage.Add( x, y, loop_count );
									}
								}
							}

							pivot_2 += reverse_dir.GetPoint();
						}
						PROCESS_MAIN( PrintStage( stage ) );
					}

					input = _getch();

				} while( 27 != input );
			}

			LS();

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT Move::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "GameProcessor : Move";
		};
	}
	r2tm::DoFunctionT Move::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( p2048mini::Stage stage( 4, 4 ) );
			DECLARATION_MAIN( p2048mini::GameProcessor game_processor( &stage ) );

			LS();

			{
				PROCESS_MAIN( stage.Add( 0, 0, 1 ) );
				PROCESS_MAIN( stage.Add( 0, 1, 2 ) );
				PROCESS_MAIN( stage.Add( 3, 0, 3 ) );
				PROCESS_MAIN( stage.Add( 0, 3, 4 ) );
				PROCESS_MAIN( stage.Add( 3, 3, 8 ) );
			}

			LS();

			{
				std::cout << "[     ESC    ] Exit" << r2tm::linefeed;
				std::cout << "[ W, A, S, D ] Move" << r2tm::linefeed;
			}

			LS();


			{
				const auto pivot_cursor_point = r2tm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{
					r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_cursor_point );

					bool has_moved = false;
					switch( input )
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

					default:
						std::cout << "Input Empty" << r2tm::linefeed;
					}

					LF();

					PROCESS_MAIN( PrintStage( stage ) );

					LF();

					std::cout << ( has_moved ? "Move Success" : "Move Failed" ) << r2tm::linefeed;

					input = _getch();

				} while( 27 != input );
			}

			LS();

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT Merge::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "GameProcessor : Merge";
		};
	}
	r2tm::DoFunctionT Merge::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( p2048mini::Stage stage( 4, 1 ) );
			DECLARATION_MAIN( p2048mini::GameProcessor game_processor( &stage ) );

			LS();

			{
				stage.Add( 0, 0, 2 );
				stage.Add( 1, 0, 1 );
				stage.Add( 2, 0, 1 );
				PROCESS_MAIN( PrintStage( stage ) );
			}

			LS();

			{
				DECLARATION_MAIN( const auto move_result = game_processor.Move( r2::Direction4::eState::Right ) );
				PROCESS_MAIN( PrintStage( stage ) );

				LF();

				EXPECT_EQ( 2, stage.GetNumber( 2, 0 ) );
				EXPECT_EQ( 2, stage.GetNumber( 3, 0 ) );

				LF();

				EXPECT_EQ( 2, game_processor.GetSum4Merged() );
			}

			LS();

			{
				DECLARATION_MAIN( const auto move_result = game_processor.Move( r2::Direction4::eState::Right ) );
				PROCESS_MAIN( PrintStage( stage ) );

				LF();

				EXPECT_EQ( 4, stage.GetNumber( 3, 0 ) );

				LF();

				EXPECT_EQ( 4, game_processor.GetSum4Merged() );
			}

			LS();

			{
				PROCESS_MAIN( stage.Add( 0, 0, 4 ) );
				PROCESS_MAIN( stage.Add( 1, 0, 4 ) );
				PROCESS_MAIN( stage.Add( 2, 0, 4 ) );
				PROCESS_MAIN( PrintStage( stage ) );

				LF();

				DECLARATION_MAIN( const auto move_result = game_processor.Move( r2::Direction4::eState::Right ) );
				PROCESS_MAIN( PrintStage( stage ) );

				LF();

				EXPECT_EQ( 8, stage.GetNumber( 2, 0 ) );
				EXPECT_EQ( 8, stage.GetNumber( 3, 0 ) );

				LF();

				EXPECT_EQ( 16, game_processor.GetSum4Merged() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT MovableCheck::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "GameProcessor : Movable Check";
		};
	}
	r2tm::DoFunctionT MovableCheck::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "주변의 숫자가 0 이거나 같다면 이동 한다." );

			LS();

			DECLARATION_MAIN( p2048mini::Stage stage( 2, 2 ) );
			DECLARATION_MAIN( p2048mini::GameProcessor game_processor( &stage ) );

			LS();

			{
				stage.Add( 0, 0, 7 );
				stage.Add( 0, 1, 7 );
				stage.Add( 1, 0, 7 );
				stage.Add( 1, 1, 7 );
				PrintStage( stage );
				EXPECT_TRUE( game_processor.IsMovable() );
			}

			LS();

			{
				stage.Add( 0, 0, 1 );
				stage.Add( 0, 1, 2 );
				stage.Add( 1, 0, 7 );
				stage.Add( 1, 1, 7 );
				PrintStage( stage );
				EXPECT_TRUE( game_processor.IsMovable() );
			}

			LS();

			{
				stage.Add( 0, 0, 1 );
				stage.Add( 0, 1, 7 );
				stage.Add( 1, 0, 2 );
				stage.Add( 1, 1, 7 );
				PrintStage( stage );
				EXPECT_TRUE( game_processor.IsMovable() );
			}

			LS();

			{
				stage.Add( 0, 0, 1 );
				stage.Add( 0, 1, 2 );
				stage.Add( 1, 0, 3 );
				stage.Add( 1, 1, 7 );
				PrintStage( stage );
				EXPECT_FALSE( game_processor.IsMovable() );
			}

			LS();

			{
				stage.Add( 0, 0, 1 );
				stage.Add( 0, 1, 2 );
				stage.Add( 1, 0, 3 );
				stage.Add( 1, 1, 0 );
				PrintStage( stage );
				EXPECT_TRUE( game_processor.IsMovable() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}