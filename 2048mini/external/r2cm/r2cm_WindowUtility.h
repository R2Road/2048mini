#pragma once

#include <stdint.h>

namespace r2cm
{
	class WindowUtility
	{
	public:
		static void ChangeTitle( const char* title_string );
		static void Resize( const int w, const int h );
		static void Move( const int x, const int y );
		static void ScrollBarVisible( const bool visible );
		static void MaximizeButtonEnable( const bool enable );
		static void ResizingByDraggingEnable( const bool enable );

		//
		// 마우스를 사용한 커서 이동, 영역 선택 On/Off
		//
		static void QuickEditEnable( const bool enable );

		struct CursorPoint
		{
			short x = 0;
			short y = 0;

			CursorPoint operator+( const CursorPoint& other ) const { return CursorPoint{ x + other.x, y + other.y }; }
		};
		static CursorPoint GetCursorPoint();
		static void MoveCursorPoint( const CursorPoint new_cursor_point );
		static void MoveCursorPointWithClearBuffer( const CursorPoint new_cursor_point );

		static void FillCharacter( const CursorPoint point, const char c );
		static void FillCharacter( const int x, const int y, const char c );

		enum eColor : unsigned char
		{
			FG_Black = 0,
			FG_Blue,
			FG_Green,
			FG_Aqua,
			FG_Red,
			FG_Purple,
			FG_Yellow,
			FG_White,
			FG_Gray,
			FG_LightBlue,
			FG_LightGreen,
			FG_LightAqua,
			FG_LightLed,
			FG_LightPurple,
			FG_LightYellow,
			FG_BrightWhite,

			BG_Black = 0,
			BG_Blue = 1 << 4,
			BG_Green = 2 << 4,
			BG_Aqua = 3 << 4,
			BG_Red = 4 << 4,
			BG_Purple = 5 << 4,
			BG_Yellow = 6 << 4,
			BG_White = 7 << 4,
			BG_Gray = 8 << 4,
			BG_LightBlue = 9 << 4,
			BG_LightGreen = 10 << 4,
			BG_LightAqua = 11 << 4,
			BG_LightLed = 12 << 4,
			BG_LightPurple = 13 << 4,
			BG_LightYellow = 14 << 4,
			BG_BrightWhite = 15 << 4,
		};
		static void FillColor( const CursorPoint point, const short c );
		static void FillColor( const int x, const int y, const short c );

		static void RequestSleep( const uint32_t m );

	};
}