#pragma once

#include <functional>

namespace r2cm
{
	enum class eTestEndAction;

	class iItem
	{
	public:
		using TitleFuncT = std::function<const char*()>;
		using DoFuncT = std::function<eTestEndAction()>;

		virtual ~iItem() {}

		virtual TitleFuncT GetTitleFunction() const = 0;
		virtual DoFuncT GetDoFunction() = 0;
	};
}