#pragma once

#include "r2_Assert.h"
#include "r2_NoneCopyable.h"

namespace r2
{
	template<typename T>
	class SingletonWithStaticVariable : private NoneCopyable
	{
	public:
		using MyT = T;

	protected:
		SingletonWithStaticVariable()
		{
			static bool blocked = false;

			R2ASSERT( false == blocked, "" );

			blocked = true;
		}

	public:
		static MyT& GetInstance()
		{
			static MyT instance;
			return instance;
		}
	};
}