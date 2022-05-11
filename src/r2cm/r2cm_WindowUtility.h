#pragma once

#include <stdint.h>

namespace r2cm
{
	class WindowUtility
	{
	public:
		static void ChangeTitle( const wchar_t* title_string );
		static void Resize( const int w, const int h );
		static void Move( const int x, const int y );

		struct CursorPoint
		{
			short x = 0;
			short y = 0;
		};
		static CursorPoint GetCursorPoint();
		static void MoveCursorPoint( const CursorPoint new_cursor_point );
		static void MoveCursorPointWithClearBuffer( const CursorPoint new_cursor_point );

		static void RequestSleep( const uint32_t m );
	};
}