#include "pch.h"
#include "r2cm_Inspector.h"

#include <fstream>
#include <stdio.h>

void SHOW_FILE( const char* const path )
{
	printf( "\x1B[90m" "[FILE]" " %s" "\033[0m" "\n", path );

	char buffer[100];
	std::ifstream ifs( path, std::ios::in );

	while( ifs )
	{
		ifs.getline( buffer, 100 );

		if( ifs )
		{
			printf( "\t" "%s" "\n", buffer );
		}
	}
	ifs.close();

	printf( "\x1B[90m" "[/FILE]" "\033[0m" "\n" );
}