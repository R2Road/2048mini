#pragma once

namespace r2cm
{

	//
	// 2022.05.06 by R
	//
	// 무리하지 않고 즐겁게 작업을 이어나갈 수 있도록 모든 방안을 강구할 것.
	//

	static struct
	{

		const char VersionNumber_1 = '1';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '0';

		const char String4Version[15] = { 'r', '2', 'c', 'm', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };

	} VersionInfo;
}