#pragma once

namespace r2base
{
	class ComponentStaticIDGenerator
	{
	private:
		ComponentStaticIDGenerator() = delete;

	public:
		static int Get()
		{
			static int ret = 0;
			return ret++;
		}
	};

	template<typename T>
	class ComponentStaticID
	{
	private:
		ComponentStaticID() = delete;

	public:
		using MyT = T;

		static int Get()
		{
			static int component_unique_id = ComponentStaticIDGenerator::Get();
			return component_unique_id;
		}
	};
}