#pragma once

#include <iostream>

namespace r2cm
{
	enum class eItemLeaveAction
	{
		None,
		Pause,
		Exit,
	};


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
	class ColorModifier
	{
	public:
		ColorModifier() : mColor( eColor::None ) {}
		ColorModifier( const eColor color_fg ) : mColor( color_fg ) {}

		friend std::ostream& operator<<( std::ostream& os, const ColorModifier& mf )
		{
			static const char* header = "\033[";
			static const char* tail = "m";
			return os << header << mf.mColor << tail;
		}

	private:
		eColor mColor;
	};
	using clm = ColorModifier;


	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& linefeed( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		// insert newline
		_Ostr.put( _Ostr.widen( '\n' ) );
		return ( _Ostr );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& linefeed2( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		return _Ostr << r2cm::linefeed << r2cm::linefeed;
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& linefeed3( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		return _Ostr << r2cm::linefeed << r2cm::linefeed << r2cm::linefeed;
	}



	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& split( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		_Ostr << r2cm::linefeed << "====================================================================" << r2cm::linefeed << r2cm::linefeed;
		return ( _Ostr );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		_Ostr.put( _Ostr.widen( '\t' ) );
		return ( _Ostr );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab2( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		_Ostr << r2cm::tab << r2cm::tab;
		return ( _Ostr );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab3( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		_Ostr << r2cm::tab << r2cm::tab << r2cm::tab;
		return ( _Ostr );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab4( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		_Ostr << r2cm::tab << r2cm::tab << r2cm::tab << r2cm::tab;
		return ( _Ostr );
	}
}