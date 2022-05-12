#include "r2utility_StringBuilder.h"

#include <stdarg.h> // va
#include <stdio.h> // vsnprintf

namespace r2utility
{
	const std::string_view StringBuilder::Build( const char* format_string, ... )
	{
		static char buffer[256] = { 0, };

		va_list argList;
		va_start( argList, format_string );

		vsnprintf( buffer, 256, format_string, argList );

		va_end( argList );

		return std::string_view( buffer );
	}
}