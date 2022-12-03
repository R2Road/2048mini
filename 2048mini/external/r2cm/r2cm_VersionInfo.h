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

		const char VersionNumber_1 = '1';	// 규칙 : 아래 명시된 목표 목록을 모두 완성하면 1 증가
		const char VersionNumber_2 = '0';	// 규칙 : 아래 명시한 목표가 여러 단계로 나뉘어 있는데 한 묶음을 완성하면 1 증가
		const char VersionNumber_3 = '3';	// 규칙 : 자잘한 작업을 진행 했고 그 것이 사용자의 코드에 어떤 변화를 유발하는 수준이면 1 증가

		const char String4Version[14] = { 'r', '2', 'c', 'm', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };

		const char* const String4Road2Version_1_0_0 =
					"### Road 2 Version 1.0.0 ###"
			"\n"
			"\n"	"[o] " "Director, Menu, Item"
			"\n"	"[o] " "Inspector"
			"\n"	"[o] " "Window Utility"
			"\n"	"[o] " "Color Modifier"
		;

	} VersionInfo;
}