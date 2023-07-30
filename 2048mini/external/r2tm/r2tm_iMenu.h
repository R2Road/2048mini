#pragma once

#include "r2tm_MenuConstant.h"

namespace r2tm
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