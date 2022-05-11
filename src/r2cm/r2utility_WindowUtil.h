#pragma once

namespace r2utility
{
	void ChangeWindowTitle( const wchar_t* title_string );
	void ResizeWindow( const int w, const int h );
	void MoveWindow( const int x, const int y );

	struct CursorPoint
	{
		int x = 0;
		int y = 0;
	};
	CursorPoint GetCursorPoint();
	void SetCursorPoint( const CursorPoint new_cursor_point );

	void RequestSleep( const uint32_t m );
}