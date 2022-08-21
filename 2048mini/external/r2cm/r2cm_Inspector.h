#pragma once

#include <iostream>
#include <stdint.h>

#define R2_ENABLE_DEBUG_BREAK 1

#if defined( R2_ENABLE_DEBUG_BREAK ) && R2_ENABLE_DEBUG_BREAK == 1
	#define R2_DEBUG_BREAK ( __debugbreak() )
#else
	#define R2_DEBUG_BREAK
#endif // R2_ENABLE_DEBUG_BREAK


#define	EXPECT_TRUE( condition )																\
do {																							\
	if( ( condition ) )																			\
	{																							\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_TRUE( %s )\n", #condition );				\
	}																							\
	else																						\
	{																							\
		R2_DEBUG_BREAK;																			\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_TRUE( %s )\n", #condition );			\
	}																							\
} while( false )

#define	EXPECT_FALSE( condition )																\
do {																							\
	if( !( condition ) )																		\
	{																							\
		printf( "\x1B[34m" "[PASS]" "\033[0m" " EXPECT_FALSE( %s )\n", #condition );			\
	}																							\
	else																						\
	{																							\
		R2_DEBUG_BREAK;																			\
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
		R2_DEBUG_BREAK;																							\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_EQ( %s == %s )\n", #condition_1, #condition_2 );		\
	}																											\
} while( false )

#define	EXPECT_NE( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) != ( condition_2 ) )																	\
	{																											\
		printf( "\x1B[34m" "[PASS]" "\033[0m" " EXPECT_NE( %s != %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		R2_DEBUG_BREAK;																							\
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
		R2_DEBUG_BREAK;																							\
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
		R2_DEBUG_BREAK;																							\
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
		R2_DEBUG_BREAK;																							\
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
		R2_DEBUG_BREAK;																							\
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
	printf( "[VALUE]" " %s" "\n", #condition );												\
	std::cout << "\t> " << condition << "\n";												\
} while( false )
//
// Output Binary
//
#define	OUTPUT_BINARY( condition )															\
do {																						\
	printf( "[BINARY]" " %s" "\n", #condition );											\
	printf( "\t> " );																		\
	SHOW_BINARY( ( condition ) );															\
	printf( "\n" );																			\
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
// + example : int a[4];
// pointer : int*
// size : 4
//
#define	OUTPUT_BINARIES( pointer, size )													\
do {																						\
	printf( "[BINARIES]" " %s" ", %s" "\n", #pointer, #size );								\
	SHOW_BINARY( ( pointer ), ( size ) );													\
	printf( "\n" );																			\
} while( false )
template<typename T>
void SHOW_BINARY( const T* p, const uint64_t size )
{
	const uint64_t fixed_limit = sizeof( T ) * size;
	const uint8_t* fixed_p = reinterpret_cast<const uint8_t*>( p );

	const uint64_t tab_limit = sizeof( T );
	uint64_t count_4_linefeed = 0;
	for( uint64_t i = 0; fixed_limit > i; ++i )
	{
		if( 0 == count_4_linefeed )
		{
			printf( "\t> " );
		}

		SHOW_BINARY( fixed_p[i] );

		++count_4_linefeed;
		if( 8 == count_4_linefeed && fixed_limit > ( i + 1 ) )
		{
			count_4_linefeed = 0;
			printf( "\n" );
		}
		else if( 0 < count_4_linefeed && 0 == count_4_linefeed % tab_limit )
		{
			printf( "\t" );
		}
		else
		{
			printf( " " );
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