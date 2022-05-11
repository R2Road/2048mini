#include "pch.h"
#include "r2utility_WindowUtil.h"

#include <Windows.h>

namespace r2utility
{
	void ChangeWindowTitle( const wchar_t* title_string )
	{
		SetConsoleTitle( title_string );
	}

	void ResizeWindow( const int w, const int h )
	{
		HWND hWnd = GetConsoleWindow();
		RECT window_rect;
		GetClientRect( hWnd, &window_rect );
		MoveWindow( hWnd, window_rect.left, window_rect.top, w, h, TRUE );
	}

	void MoveWindow( const int x, const int y )
	{
		//
		// # MoveWindow( hWnd, 0, 0... ); 만으로는 Window 가 실질적인 0, 0 좌표에 위치하지 않는다.
		// # 아래의 코드를 이용해서 타이틀 바와 얇은 프레임을 제거 해야만 위 코드로 0, 0 위치에 보여진다.
		//		LONG lStyle = GetWindowLong( GetConsoleWindow(), GWL_STYLE );
		//		lStyle &= ~( WS_CAPTION | WS_THICKFRAME );
		//		SetWindowLong( GetConsoleWindow(), GWL_STYLE, lStyle );
		//
		// # 내 목표는 타이틀 바는 남아 있지만 Window 가 0, 0 에 자리하는 것이다.
		// # 따라서 Frame 크기를 계산해서 강제로 0, 0 위치에 보이게 하고자 한다.
		//
		int offset_x = 0;
		offset_x -= GetSystemMetrics( SM_CXBORDER );
		offset_x -= GetSystemMetrics( SM_CXFRAME );
		offset_x -= GetSystemMetrics( SM_CXFIXEDFRAME );

		HWND hWnd = GetConsoleWindow();
		RECT rectClient;
		GetClientRect( hWnd, &rectClient );
		MoveWindow( hWnd, x + offset_x, y, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE );
	}

	CursorPoint GetCursorPoint()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi{};
		GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );

		return CursorPoint{ csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y };
	}
	void SetCursorPoint( const CursorPoint new_cursor_point )
	{
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), COORD{ static_cast<SHORT>( new_cursor_point.x ), static_cast<SHORT>( new_cursor_point.y ) } );
	}

	void RequestSleep( const uint32_t m )
	{
		Sleep( m );
	}
}
