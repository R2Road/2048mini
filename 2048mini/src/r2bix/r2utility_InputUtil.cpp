#include "r2utility_InputUtil.h"

#include <conio.h>

namespace r2utility
{
	void ClearCInputBuffer()
	{
		while( _kbhit() )
		{
			_getch();
		}
	}
}
