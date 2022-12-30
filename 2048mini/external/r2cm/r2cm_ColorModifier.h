#pragma once

#include <iostream>

namespace r2cm
{
	enum eColor
	{
		None = 0,

		FG_Black = 30,
		FG_Red,
		FG_Green,
		FG_Yellow,
		FG_Blue,
		FG_Purple,
		FG_Aqua,
		FG_White,

		FG_Gray = 90,
		FG_LightLed,
		FG_LightGreen,
		FG_LightYellow,
		FG_LightBlue,
		FG_LightPurple,
		FG_LightAqua,
		FG_BrightWhite,

		BG_Black = 40,
		BG_Red,
		BG_Green,
		BG_Yellow,
		BG_Blue,
		BG_Purple,
		BG_Aqua,
		BG_White,

		BG_Gray = 100,
		BG_LightLed,
		BG_LightGreen,
		BG_LightYellow,
		BG_LightBlue,
		BG_LightPurple,
		BG_LightAqua,
		BG_BrightWhite,
	};

	//
	// REF : https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
	// 1과 2를 생각해 놓고 위 REF에 있는 3에 도달하지 못했다. Link를 남기는 것이 어떤 의미로는 굴욕이구만. - 2022.05.24 by R2Road
	//
	class ColorModifier
	{
	public:
		ColorModifier() : mColor( eColor::None ) {}
		ColorModifier( const eColor color ) : mColor( color ) {}

		friend std::ostream& operator<<( std::ostream& os, const ColorModifier& color_modifier )
		{
			//
			// 2022.07.10 by R
			// - std::hex 등이 쓰이면 " << mf.mColor " 가 정상작동하지 않는다.
			// - 문자 변환해서 기록하면 해결되지만 성능이 신경쓰이므로 방치하기로 하자.
			//

			static const char* header = "\033[";
			static const char* tail = "m";
			return os << header << color_modifier.mColor << tail;
		}

	private:
		eColor mColor;
	};
}

using clm = r2cm::ColorModifier;