#pragma once

#include "r2cm_MenuConstant.h"

namespace r2cm
{
	class iItem
	{
	public:
		virtual ~iItem() {}

		virtual r2cm::TitleFunctionT GetTitleFunction() const = 0;
		virtual r2cm::DoFunctionT GetDoFunction() const = 0;
	};
}