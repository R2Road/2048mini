#pragma once

namespace r2
{
	template<typename T>
	class SingleTon
	{
	public:
		using MyT = T;

	protected:
		SingleTon() = default;

	public:
		static MyT& GetInstance()
		{
			static MyT instance;
			return instance;
		}
	};
}