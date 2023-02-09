#pragma once

#include "r2cm_MenuConstant.h"

namespace r2cm
{
	class iMenu
	{
	public:
		virtual ~iMenu() {}

		virtual TitleFunctionT GetTitleFunction() const = 0;
		virtual DescriptionFunctionT GetDescriptionFunction() const = 0;
		virtual WriteFunctionT GetWriteFunction() const = 0;
	};
}