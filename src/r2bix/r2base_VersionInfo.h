#pragma once

namespace r2base
{

	//
	// 2022.05.06 by R
	//
	// 무리하지 않고 즐겁게 작업을 이어나갈 수 있도록 모든 방안을 강구할 것.
	//

	struct
	{
		const char VersionNumber_1 = 0;
		const char VersionNumber_2 = 0;
		const char VersionNumber_3 = 1;

		const char* const String4Version_0_0_1 =
					"### Road 2 Version 0.0.1 ###"
			"\n\n"	"[o] " "Double Buffering"
			"\n"	"[o] " "Input"
			"\n"	"[o] " "Render Pipe Line"
			"\n"	"[o] " "Scene Node"
			"\n"	"[o] " "Component"
			"\n"	"[o] " "Make Simple Puzzle Game"
		;

		const char* const String4Version_0_0_2 =
					"### Road 2 Version 0.0.2 ###"
			"\n\n"	"[o] " "Color : 각 문자에 전경, 원경 색상 지정"
			"\n"	"[ ] " "Color : 전경과 원경의 색상 유효성 처리. 버퍼에 글자와 글자 색만 기록하고 싶다거나..."
			"\n"	"[ ] " "Audio"
			"\n"	"[ ] " "Split The Render And Update Process"
			"\n"	"[ ] " "Node Delete And Caching Pipe Line"
			"\n"	"[ ] " "Texture Viewer"
			"\n"	"[ ] " "Texture Editor"
			"\n"	"[ ] " "Korean"

			"\n\n"	"------------------------------------------"

			"\n\n"	"[ ] " "Json"
			"\n"	"[ ] " "Color Blend"
			"\n"	"[ ] " "Script"
		;
	} VersionInfo;
}