#include "r2tm_MenuProcessor.h"

#include <cctype> // std::toupper

#include "r2tm_iItem.h"
#include "r2tm_iMenu.h"
#include "r2tm_ostream.h"


namespace
{
	const char KEYCODE_4_LINEFEED = '@';
	const char KEYCODE_4_SPLIT = '*';
	const char KEYCODE_4_MESSAGE = '(';
}

namespace r2tm
{
	MenuProcessor::MenuProcessor( Director& director ) :
		mDirector( director )
		, mTitleString( "" )
		, mDescriptionString( "" )
		, mItemContainer()
	{}

	void MenuProcessor::ShowTitle() const
	{
		std::cout << "# " << mTitleString << " #" << r2tm::linefeed;

		LS();
	}
	void MenuProcessor::ShowDescription() const
	{
		if( !mDescriptionString.empty() )
		{
			std::cout << clm( r2tm::eColor::FG_LightGreen ) << mDescriptionString << clm() << r2tm::linefeed;

			LS();
		}
	}

	void MenuProcessor::ShowItems() const
	{
		std::cout << "+ Menu" << r2tm::linefeed2;

		for( const auto t : mItemContainer )
		{
			//
			// Function Key
			//
			if( KEYCODE_4_SPLIT == t.KeyCode ) // *
			{
				LS();
				continue;
			}
			if( KEYCODE_4_LINEFEED == t.KeyCode ) // @
			{
				LF();
				continue;
			}
			if( KEYCODE_4_MESSAGE == t.KeyCode ) // (
			{
				std::cout
					<< clm( static_cast<r2tm::eColor>( t.MessageColorCode ) )
					<< clm( static_cast<r2tm::eColor>( t.BackgroundColorCode ) )
					<< t.TitleFunction()
					<< clm()
					<< r2tm::linefeed;
				continue;
			}

			//
			// Key
			//
			std::cout << "[";

			if( 27 == t.KeyCode ) // ESC
			{
				std::cout << "ESC";
			}
			else if( 32 == t.KeyCode ) // SPACE_BAR
			{
				std::cout << "SPACE";
			}
			else
			{
				std::cout << static_cast<char>( std::toupper( t.KeyCode ) );
			}

			std::cout << "] ";
			
			//
			// Title
			//
			std::cout
				<< clm( static_cast<r2tm::eColor>( t.MessageColorCode) )
				<< clm( static_cast<r2tm::eColor>( t.BackgroundColorCode ) )
				<< t.TitleFunction()
				<< clm()
				<< r2tm::linefeed;
		}

		std::cout << r2tm::split << "Select Menu";
	}

	eDoLeaveAction MenuProcessor::Do( const int key_code )
	{
		for( const auto& i : mItemContainer )
		{
			if( key_code == i.KeyCode )
			{
				std::cout << "# " << i.TitleFunction() << " #" << r2tm::linefeed;

				//
				// # 2022.12.25 by R
				//
				// i.DoFunction 의 내부에서 MenuProcessor 변경을 위해 mItemContainer.clear() 를 호출하는경우
				// 작동중인 lambda 가 날아가면서 함수 내부의 capture 변수들이 날아가고 잘못된 메모리 참조로 터진다.
				//
				// 위와 같은 문제의 해결을 위해 lambda 를 복사하여 사용한다.
				//
				// 다른 해결책이 있을까?
				//
				auto do_func = i.DoFunction;
				return do_func();
			}
		}

		return eDoLeaveAction::Pause;
	}

	void MenuProcessor::Reset( const TitleFunctionT& title_function, const DescriptionFunctionT& description_function, const WriteFunctionT& write_function )
	{
		mTitleString = title_function();
		mDescriptionString = description_function();

		mItemContainer.clear();
		write_function( this );
	}

	void MenuProcessor::AddItem( const char key_code, const int message_color_code, const int background_color_code, const TitleFunctionT& func_title, const DoFunctionT& func_do )
	{
		mItemContainer.emplace_back( key_code, message_color_code, background_color_code, func_title, func_do );
	}
	void MenuProcessor::AddItem( const char key_code, const int message_color_code, const TitleFunctionT& func_title, const DoFunctionT& func_do )
	{
		AddItem( key_code, message_color_code, r2tm::eColor::BG_Black, func_title, func_do );
	}
	void MenuProcessor::AddItem( const char key_code, const TitleFunctionT& func_title, const DoFunctionT& func_do )
	{
		AddItem( key_code, r2tm::eColor::FG_White, r2tm::eColor::BG_Black, func_title, func_do );
	}
	void MenuProcessor::AddItem( const char key_code, const iItem& item_obj )
	{
		AddItem( key_code, r2tm::eColor::FG_White, r2tm::eColor::BG_Black, item_obj.GetTitleFunction(), item_obj.GetDoFunction() );
	}

	void MenuProcessor::AddExit( const char key_code, const int message_color_code, const int background_color_code )
	{
		AddItem(
			  key_code
			, message_color_code
			, background_color_code
			, []()->const char* { return "Exit"; }
			, []()->r2tm::eDoLeaveAction { return r2tm::eDoLeaveAction::Exit; }
		);
	}
	void MenuProcessor::AddExit( const char key_code, const int message_color_code )
	{
		AddExit( key_code, message_color_code, r2tm::eColor::BG_Purple );
	}
	void MenuProcessor::AddExit( const char key_code )
	{
		AddExit( key_code, r2tm::eColor::FG_White, r2tm::eColor::BG_Purple );
	}

	void MenuProcessor::AddMenu( const char key_code, const iMenu& menu_obj )
	{
		AddItem( key_code, r2tm::eColor::FG_Aqua, menu_obj.GetTitleFunction()
			, [
				this
				, title_function = menu_obj.GetTitleFunction()
				, description_function = menu_obj.GetDescriptionFunction()
				, write_function = menu_obj.GetWriteFunction()
			]()->eDoLeaveAction
			{
				Reset( title_function, description_function, write_function );

				return eDoLeaveAction::None;
			}
		);
	}

	void MenuProcessor::AddLineFeed()
	{
		static const TitleFunctionT func_title = []()->const char* { return ""; };
		static const DoFunctionT func_do = []()->const eDoLeaveAction { return eDoLeaveAction::Pause; };

		AddItem( KEYCODE_4_LINEFEED, r2tm::eColor::FG_White, func_title, func_do );
	}
	void MenuProcessor::AddSplit()
	{
		static const TitleFunctionT func_title = []()->const char* { return ""; };
		static const DoFunctionT func_do = []()->const eDoLeaveAction { return eDoLeaveAction::Pause; };

		AddItem( KEYCODE_4_SPLIT, r2tm::eColor::FG_White, func_title, func_do );
	}

	void MenuProcessor::AddMessage( const char* const message, const int message_color_code, const int background_color_code )
	{
		const TitleFunctionT func_title = [message]()->const char* { return message; };
		static const DoFunctionT func_do = []()->const eDoLeaveAction { return eDoLeaveAction::Pause; };

		AddItem( KEYCODE_4_MESSAGE, message_color_code, background_color_code, func_title, func_do );
	}
	void MenuProcessor::AddMessage( const char* const message, const int message_color_code )
	{
		AddMessage( message, message_color_code, r2tm::eColor::BG_Black );
	}
	void MenuProcessor::AddMessage( const char* const message )
	{
		AddMessage( message, r2tm::eColor::FG_White );
	}
}