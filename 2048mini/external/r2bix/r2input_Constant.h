#pragma once

#include <stdint.h>

namespace r2input
{
	using KeyCodeTypeT = uint8_t;

	int GetKeyState( const KeyCodeTypeT key_code );
	bool HasWindowFocus();
}