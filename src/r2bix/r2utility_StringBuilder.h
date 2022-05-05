#pragma once

#include <string_view>

namespace r2utility
{
	class StringBuilder
	{
	private:
		StringBuilder() = delete;

	public:
		static const std::string_view Build( const char* format_string, ... );
	};
}
