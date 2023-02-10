#pragma once

namespace p2048mini
{
	class Config
	{
	private:
		Config() = delete;

	public:
		struct NodeConfig
		{
			bool pivot = true;
		};
		static const NodeConfig& GetNodeConfig()
		{
			static const NodeConfig ret;
			return ret;
		}
	};
}