#include "pch.h"
#include "r2cm_Menu.h"

#include <cctype> // std::toupper

#include "r2cm_eTestEndAction.h"
#include "r2cm_iItem.h"

namespace
{
	const char KeyCode4LineFeed = 64; // @
	const char KeyCode4Split = 42; // *
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
		std::cout << "# " << mTitleString << " #" << r2::linefeed;
		std::cout << r2::split;
	}
	void Menu::ShowDescription() const
	{
		if( !mDescriptionString.empty() )
		{
			std::cout << "+ Message" << r2::linefeed2;
			
			std::cout << mDescriptionString << r2::linefeed;

			std::cout << r2::split;
		}
	}

	void Menu::ShowMenu() const
	{
		std::cout << "+ Menu" << r2::linefeed2;

		for( const auto t : mItemContainer )
		{
			//
			// Key
			//
			if( KeyCode4Split == t.KeyCode ) // *
			{
				std::cout << r2::split;
				continue;
			}
			if( KeyCode4LineFeed == t.KeyCode ) // @
			{
				std::cout << r2::linefeed;
				continue;
			}

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
			// Name
			//
			std::cout << t.NameFunction() << r2::linefeed;
		}

		std::cout << r2::split << "Select Menu";
	}

	eTestEndAction Menu::Do( const int key_code )
	{
		for( const auto& i : mItemContainer )
		{
			if( key_code == i.KeyCode )
			{
				return i.DoFunction();
			}
		}

		return eTestEndAction::Pause;
	}

	void Menu::AddItem( const char key_code, iItem& item_obj )
	{
		mItemContainer.emplace_back( key_code, item_obj.GetTitleFunction(), item_obj.GetDoFunction() );
	}
	void Menu::AddItem( const char key_code, const std::function<const char*()> func_title, const std::function<const r2cm::eTestEndAction()> func_do )
	{
		mItemContainer.emplace_back( key_code, func_title, func_do );
	}
	void Menu::AddLineFeed()
	{
		static const std::function<const char*()> func_title = []()->const char* { return ""; };
		static const std::function<const r2cm::eTestEndAction()> func_do = []()->const r2cm::eTestEndAction { return r2cm::eTestEndAction::Pause; };

		mItemContainer.push_back( { KeyCode4LineFeed, func_title, func_do } );
	}
	void Menu::AddSplit()
	{
		static const std::function<const char*( )> func_title = []()->const char* { return ""; };
		static const std::function<const r2cm::eTestEndAction()> func_do = []()->const r2cm::eTestEndAction { return r2cm::eTestEndAction::Pause; };

		mItemContainer.push_back( { KeyCode4Split, func_title, func_do } );
	}
}