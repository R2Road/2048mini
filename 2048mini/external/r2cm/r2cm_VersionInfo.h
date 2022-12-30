#pragma once

namespace r2cm
{

	//
	// 2022.05.06 by R
	//
	// �������� �ʰ� ��̰� �۾��� �̾�� �� �ֵ��� ��� ����� ������ ��.
	//

	static struct
	{

		const char VersionNumber_1 = '1';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '5';

		const char String4Version[14] = { 'r', '2', 'c', 'm', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };



		const char* const String4Road2Version_1_0_5 =
			"### Version Rule ###"
			"\n"
			"\n"	"> " "1.0.0"  " : "  "�ϼ�?"
			"\n"	"> " "0.1.0"  " : "  "���� ���� ���ڰ� 10�� ����"
			"\n"	"> " "0.0.1"  " : "  "����ڿ��� �ڵ� ������ �䱸�Ѵ�."
			"\n"
			"\n"
			"\n"	"### Road 2 Version 1.0.5 ###"
			"\n"
			"\n"	"[o] " "update inspector : EXPECT_GT, EXPECT_LT, EXPECT_GE, EXPECT_LE - ���н� �� ���"
			"\n"	"[o] " "Split Menu And MenuProcessor"
		; 
		
		const char* const String4Road2Version_1_0_4 =
			"### Road 2 Version 1.0.4 ###"
			"\n"
			"\n"	"[o] " "update method : apply const - r2cm::iItem::GetDoFunction"
			"\n"	"[o] " "remove class : r2cm::SingleTon"
		; 
		
		const char* const String4Road2Version_1_0_3 =
			"### Road 2 Version 1.0.3 ###"
			"\n"
			"\n"	"[o] " "update inspector : EXPECT_EQ, EXPECT_NE - ���н� �� ���"
			"\n"	"[o] " "update inspector : OUTPUT_BINARY - ���ü� ����"
			"\n"	"[o] " "update inspector : inspector �� debug break ON/OFF ����"
			"\n"	"[o] " "update inspector : Add - OUTPUT_NOTE"
			"\n"	"[o] " "update inspector : Add - OUTPUT_COMMENT"
			"\n"	"[o] " "update inspector : OUTPUT_FILE ���� line index ���"
			"\n"	"[o] " "update inspector : Add - OUTPUT_FILE_RANGE"
		; 
		
		const char* const String4Road2Version_1_0_2 =
			"### Road 2 Version 1.0.2 ###"
			"\n"
			"\n"	"[o] " "add method : r2cm::WindowUtility::ScrollBarVisible"
			"\n"	"[o] " "add method : r2cm::WindowUtility::MaximizeButtonEnable"
			"\n"	"[o] " "add method : r2cm::WindowUtility::ResizingByDraggingEnable"
			"\n"	"[o] " "add method : r2cm::WindowUtility::QuickEditEnable"
		; 
		
		const char* const String4Road2Version_1_0_1 =
			"### Road 2 Version 1.0.1 ###"
			"\n"
			"\n"	"[o] " "add class : r2cm::StopWatch"
			"\n"	"[o] " "update method : r2cm::Menu::AddItem - Item ���� �÷� ����"
			"\n"	"[o] " "update method : r2cm::Menu::Do - �޴� ������ # �� ����ڰ� �Է����� �ʾƵ� �ǵ��� ����"
		;

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