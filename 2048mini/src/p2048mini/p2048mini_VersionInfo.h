#pragma once

namespace p2048mini
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
		const char VersionNumber_3 = '1';

		const char String4Version[18] = { '2', '0', '4', '8', 'm', 'i', 'n', 'i', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };

		const char* const String4SubjectOfAProject = {
			"### 프로젝트 목표 | Subject Of A Project ###"
			"\n"
			"\n"	"[o] "    "r2bix가 활용된 첫 게임을 만든다"
			"\n"	"[o] "    "r2bix의 기능을 점검 하고 부족한 부분을 보강한다."
		};

	} VersionInfo;
}