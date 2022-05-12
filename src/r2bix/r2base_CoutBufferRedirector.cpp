#include "r2base_CoutBufferRedirector.h"

#include <Windows.h>

namespace r2base
{
	CoutBufferRedirector::CoutBufferRedirector( HandleT handle ) : mHandle( handle )
	{}

	std::streambuf::int_type CoutBufferRedirector::overflow( std::streambuf::int_type c )
	{
		if( c != EOF )
		{
			DWORD written;
			WriteConsole( mHandle, &c, 1, &written, nullptr );
		}
		return c;
	}

	std::streamsize CoutBufferRedirector::xsputn( std::streambuf::char_type const *s, std::streamsize count )
	{
		DWORD written;
		WriteConsoleA( mHandle, s, static_cast<DWORD>( count ), &written, nullptr );
		return written;
	}
}