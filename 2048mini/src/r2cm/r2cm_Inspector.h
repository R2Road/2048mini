#pragma once

#include <iostream>
#include <stdint.h>

#define	EXPECT_TRUE( condition )																\
do {																							\
	if( ( condition ) )																			\
	{																							\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_TRUE( %s )\n", #condition );				\
	}																							\
	else																						\
	{																							\
		__debugbreak();																			\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_TRUE( %s )\n", #condition );			\
	}																							\
} while( false )

#define	EXPECT_FALSE( condition )																\
do {																							\
	if( !( condition ) )																		\
	{																							\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_FALSE( %s )\n", #condition );			\
	}																							\
	else																						\
	{																							\
		__debugbreak();																			\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_FALSE( %s )\n", #condition );			\
	}																							\
} while( false )

#define	EXPECT_EQ( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) == ( condition_2 ) )																	\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_EQ( %s == %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		__debugbreak();																							\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_EQ( %s == %s )\n", #condition_1, #condition_2 );		\
	}																											\
} while( false )

#define	EXPECT_NE( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) != ( condition_2 ) )																	\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_NE( %s != %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		__debugbreak();																							\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_NE( %s != %s )\n", #condition_1, #condition_2 );		\
	}																											\
} while( false )

#define	EXPECT_GT( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) > ( condition_2 ) )																		\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_GT( %s > %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		__debugbreak();																							\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_GT( %s > %s )\n", #condition_1, #condition_2 );		\
	}																											\
} while( false )

#define	EXPECT_LT( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) < ( condition_2 ) )																		\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_LT( %s < %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		__debugbreak();																							\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_LT( %s < %s )\n", #condition_1, #condition_2 );		\
	}																											\
} while( false )

#define	EXPECT_GE( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) >= ( condition_2 ) )																	\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_GE( %s >= %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		__debugbreak();																							\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_GE( %s >= %s )\n", #condition_1, #condition_2 );		\
	}																											\
} while( false )

#define	EXPECT_LE( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) <= ( condition_2 ) )																	\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_LE( %s <= %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		__debugbreak();																							\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_LE( %s <= %s )\n", #condition_1, #condition_2 );		\
	}																											\
} while( false )

//
// Important Process Code
//
#define	PROCESS_MAIN( condition )															\
do {																						\
	printf( "\x1B[96m" "[PROCESS]" "\033[0m" " %s\n", #condition );							\
	{ condition; }																			\
} while( false )
//
// Sub Process Code
//
#define	PROCESS_SUB( condition )															\
do {																						\
	printf( "\x1B[90m" "[PROCESS]" " %s" "\033[0m" "\n", #condition );						\
	{ condition; }																			\
} while( false )

//
// Important Declaration Code
//
#define	DECLARATION_MAIN( condition )														\
condition;																					\
printf( "\x1B[93m" "[DECLARATION]" "\033[0m" " %s\n", #condition );
//
// Sub Declaration Code
//
#define	DECLARATION_SUB( condition )														\
condition;																					\
printf( "\x1B[90m" "[DECLARATION]" " %s" "\033[0m" "\n", #condition );

//
// Output Value
//
#define	OUTPUT_VALUE( condition )															\
do {																						\
	printf( "[VALUE]" " %s" "\n", #condition );											\
	std::cout << "\t> " << condition << "\n";												\
} while( false )
//
// Output Binary
//
#define	OUTPUT_BINARY( condition )															\
do {																						\
	printf( "[BINARY]" " %s" "\n", #condition );											\
	std::cout << "\t> "						;												\
	SHOW_BINARY( ( condition ) );															\
	std::cout << "\n";																		\
} while( false )

template<typename T>
void SHOW_BINARY( const T value );

template<typename T>
void SHOW_BINARY( const T value )
{
	int32_t limit = sizeof( value ) * 8;

	if( 8 < limit )
	{
		for( int32_t position = limit - 1; 0 <= position; --position )
		{
			const T temp_1 = ( value >> position );
			const T temp_2 = temp_1 & 1;

			std::cout << temp_2;
		}
	}
	else
	{
		const int32_t fixed_value = static_cast<int32_t>( value );
		for( int32_t position = limit - 1; 0 <= position; --position )
		{
			const int32_t temp_1 = ( fixed_value >> position );
			const int32_t temp_2 = temp_1 & 1;

			std::cout << temp_2;
		}
	}
}

//
// Output Code
//
#define	OUTPUT_CODE( condition )																\
do {																						\
	printf( "[CODE]" " %s" "\n", #condition );												\
} while( false )

//
//
//
void SHOW_FILE( const char* const path );