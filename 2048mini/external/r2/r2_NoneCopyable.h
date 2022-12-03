#pragma once

namespace r2
{
	class NoneCopyable
	{
	public:
		NoneCopyable() = default;

	private:
		// none copy
		NoneCopyable( const NoneCopyable& ) = delete;
		NoneCopyable( NoneCopyable&& ) = delete;
		NoneCopyable& operator=( const NoneCopyable& ) = delete;
		NoneCopyable& operator=( NoneCopyable&& ) = delete;
	};
}