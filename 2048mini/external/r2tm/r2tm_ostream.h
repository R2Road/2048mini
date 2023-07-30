#pragma once

#include "r2tm_ColorModifier.h"

namespace r2tm
{
	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& linefeed( std::basic_ostream<_Elem, _Traits>& os )
	{
		// insert newline
		return os.put( os.widen( '\n' ) );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& linefeed2( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2tm::linefeed << r2tm::linefeed;
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& linefeed3( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2tm::linefeed << r2tm::linefeed << r2tm::linefeed;
	}



	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& split( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2tm::linefeed << "==========" "==========" "==========" "==========" "==========" "==========" "========" << r2tm::linefeed << r2tm::linefeed;
	}



	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& softsplit( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2tm::linefeed << "    " "----------" "----------" "----------" "----------" "----------" "----------" << r2tm::linefeed << r2tm::linefeed;
	}



	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os.put( os.widen( '\t' ) );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab2( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2tm::tab << r2tm::tab;
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab3( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2tm::tab << r2tm::tab << r2tm::tab;
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab4( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2tm::tab << r2tm::tab << r2tm::tab << r2tm::tab;
	}
}

inline void LF()
{
	std::cout << r2tm::linefeed;
}
inline void LF2()
{
	std::cout << r2tm::linefeed2;
}
inline void LF3()
{
	std::cout << r2tm::linefeed3;
}

inline void SS()
{
	std::cout << r2tm::softsplit;
}

inline void LS()
{
	std::cout << r2tm::split;
}