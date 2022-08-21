#pragma once

#include <streambuf>

//
// # REF
//
// https://stackoverflow.com/questions/39110882/redirecting-cout-to-the-new-buffer-that-created-with-winapi
//

namespace r2base
{
	class CoutBufferRedirector : public std::streambuf
	{
	private:
		using HandleT = void*;

	public:
		CoutBufferRedirector( HandleT handle );

	protected:
		std::streambuf::int_type overflow( std::streambuf::int_type c ) override;
		std::streamsize xsputn( std::streambuf::char_type const *s, std::streamsize count ) override;

	private:
		HandleT mHandle;
	};
}