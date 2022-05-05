#pragma once

namespace p2048mini
{
	class Config
	{
	public:
		struct DebugConfig
		{
			bool bLastStage = false;
		};
		struct NodeConfig
		{
			bool pivot = false;
		};

	private:
		Config() = delete;

	public:
		static const DebugConfig& GetDebugConfig()
		{
			const static DebugConfig ret
			{
				false
			};
			return ret;
		}

		static const NodeConfig& GetNodeConfig()
		{
			const static NodeConfig ret
			{
				false
			};
			return ret;
		}
	};
}