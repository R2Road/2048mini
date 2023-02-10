#pragma once

namespace p2048mini
{
	class Config
	{
	public:
		struct NodeConfig
		{
			bool pivot = false;
		};

	private:
		Config() = delete;

	public:
		static const NodeConfig& GetNodeConfig()
		{
			const static NodeConfig ret
			{
				true
			};
			return ret;
		}
	};
}