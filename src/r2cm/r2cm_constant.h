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
}