#include "r2cm_Menu.h"

#include <cctype> // std::toupper

#include "r2cm_ostream.h"

namespace
{
	const char KeyCode4LineFeed = '@';
	const char KeyCode4Split = '*';
	const char KeyCode4Message = '(';
}

namespace r2cm
{
	Menu::Menu( Director& director, const char* title_string, const char* description_string ) :
		mDirector( director )
		, mTitleString( title_string )
		, mDescriptionString( description_string )
		, mItemContainer()
	{}

	void Menu::ShowTitle() const
	{
		std::cout << "# " << mTitleString << " #" << r2cm::linefeed;
		std::cout << r2cm::split;
	}
	void Menu::ShowDescription() const
	{
		if( !mDescriptionString.empty() )
		{
			std::cout << "+ Message" << r2cm::linefeed2;
			
			std::cout << r2cm::clm( r2cm::eColor::FG_LightGreen ) << mDescriptionString << r2cm::clm() << r2cm::linefeed;

			std::cout << r2cm::split;
		}
	}

	void Menu::ShowItems() const
	{
		std::cout << "+ Menu" << r2cm::linefeed2;

		for( const auto t : mItemContainer )
		{
			//
			// Function Key
			//
			if( KeyCode4Split == t.KeyCode ) // *
			{
				std::cout << r2cm::split;
				continue;
			}
			if( KeyCode4LineFeed == t.KeyCode ) // @
			{
				std::cout << r2cm::linefeed;
				continue;
			}
			if( KeyCode4Message == t.KeyCode ) // (
			{
				std::cout << t.TitleFunction() << r2cm::linefeed;
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
			std::cout << r2cm::clm( static_cast<r2cm::eColor>( t.ColorCode ) ) << t.TitleFunction() << r2cm::clm() << r2cm::linefeed;
		}

		std::cout << r2cm::split << "Select Menu";
	}

	eItemLeaveAction Menu::Do( const int key_code )
	{
		for( const auto& i : mItemContainer )
		{
			if( key_code == i.KeyCode )
			{
				std::cout << "# " << i.TitleFunction() << " #" << r2cm::linefeed;
				return i.DoFunction();
			}
		}

		return eItemLeaveAction::Pause;
	}

	void Menu::AddItem( const char key_code, const int color_code, const iItem::TitleFunctionT& func_title, const iItem::DoFunctionT& func_do )
	{
		mItemContainer.emplace_back( key_code, color_code, func_title, func_do );
	}
	void Menu::AddItem( const char key_code, const iItem::TitleFunctionT& func_title, const iItem::DoFunctionT& func_do )
	{
		mItemContainer.emplace_back( key_code, r2cm::eColor::FG_White, func_title, func_do );
	}
	void Menu::AddItem( const char key_code, const iItem& item_obj )
	{
		AddItem( key_code, r2cm::eColor::FG_White, item_obj.GetTitleFunction(), item_obj.GetDoFunction() );
	}

	void Menu::AddLineFeed()
	{
		static const iItem::TitleFunctionT func_title = []()->const char* { return ""; };
		static const iItem::DoFunctionT func_do = []()->const r2cm::eItemLeaveAction { return r2cm::eItemLeaveAction::Pause; };

		AddItem( KeyCode4LineFeed, r2cm::eColor::FG_White, func_title, func_do );
	}
	void Menu::AddSplit()
	{
		static const iItem::TitleFunctionT func_title = []()->const char* { return ""; };
		static const iItem::DoFunctionT func_do = []()->const r2cm::eItemLeaveAction { return r2cm::eItemLeaveAction::Pause; };

		AddItem( KeyCode4Split, r2cm::eColor::FG_White, func_title, func_do );
	}
	void Menu::AddMessage( const char* const message )
	{
		const iItem::TitleFunctionT func_title = [message]()->const char* { return message; };
		static const iItem::DoFunctionT func_do = []()->const r2cm::eItemLeaveAction { return r2cm::eItemLeaveAction::Pause; };

		AddItem( KeyCode4Message, r2cm::eColor::FG_White, func_title, func_do );
	}
}