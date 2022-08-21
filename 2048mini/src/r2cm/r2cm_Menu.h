#pragma once

#include <memory>
#include <string_view>
#include <vector>

#include "r2cm_iItem.h"

namespace r2cm
{
	class Director;

	using MenuUp = std::unique_ptr<class Menu>;
	class Menu
	{
	private:
		struct ItemInfo
		{
			ItemInfo(
				const char key_code
				, const iItem::TitleFunctionT title_function
				, const iItem::DoFunctionT do_function
			) :
				KeyCode( key_code )
				, TitleFunction( title_function )
				, DoFunction( do_function )
			{}

			char KeyCode;
			iItem::TitleFunctionT TitleFunction;
			iItem::DoFunctionT DoFunction;
		};

		using ItemContainerT = std::vector<ItemInfo>;

	public:
		Menu( Director& director, const char* title_string, const char* description_string = "" );
		virtual ~Menu() {}

		void ShowTitle() const;
		void ShowDescription() const;
		void ShowMenu() const;

		eItemLeaveAction Do( const int key_code );

		void AddItem( const char key_code, const iItem::TitleFunctionT func_title, iItem::DoFunctionT func_do );
		void AddItem( const char key_code, iItem& item_obj );
		
		template<typename menu_T>
		void AddMenu( const char key_code )
		{
			AddItem(
				key_code
				, []()->const char* { return menu_T::GetTitle(); }
				, [&director = mDirector]()->r2cm::eItemLeaveAction
				{
					director.Setup( menu_T::Create( director ) );
					return r2cm::eItemLeaveAction::None;
				}
			);
		}

		void AddLineFeed();
		void AddSplit();
		void AddMessage( const char* const message );

	protected:
		Director& mDirector;
		std::string_view mTitleString;
		std::string_view mDescriptionString;

		ItemContainerT mItemContainer;
	};
}