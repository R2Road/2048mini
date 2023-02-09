#pragma once

#include <string_view>
#include <vector>

#include "r2cm_MenuConstant.h"

namespace r2cm
{
	class Director;
	class iItem;
	class iMenu;

	class MenuProcessor
	{
	private:
		struct ItemInfo
		{
			ItemInfo(
				const char key_code
				, const int color_code
				, const TitleFunctionT& title_function
				, const DoFunctionT& do_function
			) :
				KeyCode( key_code )
				, ColorCode( color_code )
				, TitleFunction( title_function )
				, DoFunction( do_function )
			{}

			char KeyCode;
			int ColorCode;
			TitleFunctionT TitleFunction;
			DoFunctionT DoFunction;
		};

		using ItemContainerT = std::vector<ItemInfo>;

	public:
		MenuProcessor( Director& director );

		//
		//
		//
		void ShowTitle() const;
		void ShowDescription() const;
		void ShowItems() const;

		eDoLeaveAction Do( const int key_code );

		//
		//
		//
		void Reset( const TitleFunctionT& title_function, const DescriptionFunctionT& description_function, const WriteFunctionT& write_function );

		//
		//
		//
		void AddItem( const char key_code, const int color_code, const TitleFunctionT& func_title, const DoFunctionT& func_do );
		void AddItem( const char key_code, const TitleFunctionT& func_title, const DoFunctionT& func_do );
		void AddItem( const char key_code, const iItem& item_obj );

		void AddExit( const char key_code, const int color_code );
		void AddExit( const char key_code );

		void AddMenu( const char key_code, const iMenu& menu_obj );

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