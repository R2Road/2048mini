#include "r2_Random.h"

#include <random>
#include <algorithm>

namespace r2
{
	std::mt19937& GetRandomEngine()
	{
		static std::random_device random_device;
		static std::mt19937 random_engine( random_device() );

		return random_engine;
	}

	int Random::GetInt( const int min, const int max )
	{
		std::uniform_int_distribution<> dist( std::min( min, max ), std::max( min, max ) );
		return dist( GetRandomEngine() );
	}
	int Random::GetInt_0To1()
	{
		return GetInt( 0, 1 );
	}
	int Random::GetInt_0To100()
	{
		return GetInt( 0, 100 );
	}

	float Random::GetFloat( const float min, const float max )
	{
		std::uniform_real_distribution<> dist( std::min( min, max ), std::max( min, max ) );
		return static_cast<float>( dist( GetRandomEngine() ) );
	}

	bool Random::GetBool()
	{
		return 0 == GetInt_0To1();
	}
}

