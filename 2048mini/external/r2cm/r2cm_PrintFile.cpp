#include "r2cm_PrintFile.h"

#include <stdio.h>

namespace r2cm
{
	const char* GetLine( FILE* fp )
	{
		static char buffer[100];
		fgets( buffer, sizeof( buffer ), fp );

		return buffer;
	}

	void PrintFile( const char* const path )
	{
		printf( "\x1B[90m" "[FILE]" " %s" "\033[0m" "\n", path );

		FILE* fp = nullptr;
		if( 0 == fopen_s( &fp, path, "rb" ) )
		{
			
			unsigned int cur = 1;
			while( !feof( fp ) )
			{
				printf( "%4d | " " " "%s", cur, GetLine( fp ) );

				++cur;
			}
			printf( "\n" );
		}

		fclose( fp );

		printf( "\x1B[90m" "[/FILE]" "\033[0m" "\n" );
	}

	void PrintFile( const char* const path, const unsigned int min, const unsigned int max )
	{
		printf( "\x1B[90m" "[FILE]" " %s" " : %d ~ %d" "\033[0m" "\n", path, min, max );

		FILE* fp = nullptr;
		if( 0 == fopen_s( &fp, path, "rb" ) )
		{
			unsigned int cur = 1;
			const char* str = nullptr;
			while( !feof( fp ) )
			{
				str = GetLine( fp );

				if( min <= cur )
				{
					printf( "%4d | " " " "%s", cur, str );
				}

				++cur;
				if( cur > max )
				{
					break;
				}
			}

			if( feof( fp ) )
			{
				printf( "\n" );
			}
		}

		fclose( fp );

		printf( "\x1B[90m" "[/FILE]" "\033[0m" "\n" );
	}
}