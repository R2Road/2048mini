#pragma once

namespace r2tm
{

	//
	// 2022.05.06 by R
	//
	// 무리하지 않고 즐겁게 작업을 이어나갈 수 있도록 모든 방안을 강구할 것.
	//

	constexpr struct
	{

		const char* const String4VersionRule =
					"### Version Rule ###"
			"\n"
			"\n"	"> " "1.0.0.0"  " : "  "완성?"
			"\n"	"> " "0.1.0.0"  " : "  "하위 버전 숫자가 10에 도달"
			"\n"	"> " "0.0.1.0"  " : "  "Road 완료"
			"\n"	"> " "0.0.0.1"  " : "  "사용자가 변경 사항을 몰라도 되는 변화"
		;



		const char VersionNumber_1 = '1';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '7';
		const char VersionNumber_4 = '2';

		const char String4Version[16] = { 'r', '2', 't', 'm', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '.', VersionNumber_4, '\0' };



		const char* const String4Road2Version_1_0_8 =
					"### Road 2 Version 1.0.8 ###"
			"\n"
			"\n"	"[o] " "update    function   : r2tm::Inspector - OUTPUT_NOTE"
			"\n"	"[o] " "update    struct     : r2tm::WindowUtility::CursorPoint - 생성자 추가, 연산자 +, += 추가"
			"\n"	"[ ] " "..."
		;

		const char* const String4Road2Version_1_0_7 =
					"### Road 2 Version 1.0.7 ###"
			"\n"
			"\n"	"[o] " "add method           : r2tm::WindowUtility::FillString"
			"\n"	"[o] " "update inspector     : Add - OUTPUT_STRING"
			"\n"	"[o] " "update inspector     : OUTPUT_SIZE - 크기 뒤에 byte 문자열 출력"
			"\n"	"[o] " "rename method        : r2tm::StopWatch - PrintMinAndMaxTime_NanoSeconds"
			"\n"	"[o] " "add    method        : r2tm::StopWatch - PrintMinAndMaxTime_MilliSeconds"
			"\n"	"[o] " "add    method        : r2tm::StopWatch - PrintMinAndMaxTime_MicroSeconds"
			"\n"	"[o] " "update menuprocessor : 키, 메세지 텍스트의 백그라운드 색상 설정"
			"\n"	"[o] " "overload    method   : r2tm::WindowUtility - FillString"
			"\n"	"[o] " "overload    method   : r2tm::WindowUtility - MoveCursorPoint"
			"\n"	"[o] " "overload    method   : r2tm::WindowUtility - FillCharacter"
			"\n"	"[o] " "overload    method   : r2tm::WindowUtility - FillColor"
			"\n"	"[o] " "overload    method   : r2tm::WindowUtility - MoveCursorPointWithClearBuffer"
		;

		const char* const String4Road2Version_1_0_6 =
					"### Road 2 Version 1.0.6 ###"
			"\n"
			"\n"	"[o] " "update inspector : Add - OUTPUT_SUBJECT"
			"\n"	"[o] " "update inspector : Add - OUTPUT_SIZE"
			"\n"	"[o] " "update ostream : Add - LF(), LF2(), LF3(), LS()"
			"\n"	"[o] " "update menuprocessor : Add - AddExit"
			"\n"	"[o] " "update inspector : Apply Color - OUTPUT_NOTE, OUTPUT_SUBJECT, OUTPUT_COMMENT, OUTPUT_CODE"
		;

		const char* const String4Road2Version_1_0_5 =
					"### Road 2 Version 1.0.5 ###"
			"\n"
			"\n"	"[o] " "update inspector : EXPECT_GT, EXPECT_LT, EXPECT_GE, EXPECT_LE - 실패시 값 출력"
			"\n"	"[o] " "Split Menu And MenuProcessor"
		;
		
		const char* const String4Road2Version_1_0_4 =
					"### Road 2 Version 1.0.4 ###"
			"\n"
			"\n"	"[o] " "update method : apply const - r2tm::iItem::GetDoFunction"
			"\n"	"[o] " "remove class : r2tm::SingleTon"
		;
		
		const char* const String4Road2Version_1_0_3 =
					"### Road 2 Version 1.0.3 ###"
			"\n"
			"\n"	"[o] " "update inspector : EXPECT_EQ, EXPECT_NE - 실패시 값 출력"
			"\n"	"[o] " "update inspector : OUTPUT_BINARY - 가시성 개선"
			"\n"	"[o] " "update inspector : inspector 의 debug break ON/OFF 설정"
			"\n"	"[o] " "update inspector : Add - OUTPUT_NOTE"
			"\n"	"[o] " "update inspector : Add - OUTPUT_COMMENT"
			"\n"	"[o] " "update inspector : OUTPUT_FILE 에서 line index 출력"
			"\n"	"[o] " "update inspector : Add - OUTPUT_FILE_RANGE"
		;
		
		const char* const String4Road2Version_1_0_2 =
					"### Road 2 Version 1.0.2 ###"
			"\n"
			"\n"	"[o] " "add method : r2tm::WindowUtility::ScrollBarVisible"
			"\n"	"[o] " "add method : r2tm::WindowUtility::MaximizeButtonEnable"
			"\n"	"[o] " "add method : r2tm::WindowUtility::ResizingByDraggingEnable"
			"\n"	"[o] " "add method : r2tm::WindowUtility::QuickEditEnable"
		;
		
		const char* const String4Road2Version_1_0_1 =
					"### Road 2 Version 1.0.1 ###"
			"\n"
			"\n"	"[o] " "add class : r2tm::StopWatch"
			"\n"	"[o] " "update method : r2tm::Menu::AddItem - Item 제목에 컬러 적용"
			"\n"	"[o] " "update method : r2tm::Menu::Do - 메뉴 제목의 # 을 사용자가 입력하지 않아도 되도록 조정"
		;

		const char* const String4Road2Version_1_0_0 =
					"### Road 2 Version 1.0.0 ###"
			"\n"
			"\n"	"[o] " "Director, Menu, Item"
			"\n"	"[o] " "Inspector"
			"\n"	"[o] " "Window Utility"
			"\n"	"[o] " "Color Modifier"
		;



		const char* const String4Road2NextVersion = String4Road2Version_1_0_8;

	} VersionInfo;
}