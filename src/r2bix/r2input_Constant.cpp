#include "r2input_Constant.h"

#include <Windows.h>

namespace r2input
{
	int GetKeyState( const KeyCodeTypeT key_code )
	{
		return GetAsyncKeyState( key_code );
	}
	bool HasWindowFocus()
	{
		return GetConsoleWindow() == GetForegroundWindow();
	}
}