#pragma once

namespace r2
{
	class Random
	{
	public:
		static int GetInt( const int min, const int max );
		static int GetInt_0To1();
		static int GetInt_0To100();

		static float GetFloat( const float min, const float max );

		static bool GetBool();
	};
}

