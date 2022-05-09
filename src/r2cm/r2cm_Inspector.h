#pragma once

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