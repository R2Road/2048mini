#include <stdio.h>

#define	R2ASSERT( condition, message )		\
do {										\
	if( !( condition ) )					\
	{										\
		printf( "[R2ASSERT]" "\nCondition : %s" "\nMessage : %s\n", #condition, message );	\
		__debugbreak();\
		throw std::runtime_error( message );\
	}										\
} while( false )
