#pragma once

#include <functional>

namespace r2cm
{
	enum class eItemLeaveAction;

	class iItem
	{
	public:
		using TitleFuncT = std::function<const char*()>;
		using DoFuncT = std::function<eItemLeaveAction()>;

		virtual ~iItem() {}

		virtual TitleFuncT GetTitleFunction() const = 0;
		virtual DoFuncT GetDoFunction() = 0;
	};
}