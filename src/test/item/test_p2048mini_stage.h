#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace test_p2048mini_stage
{
	class Generate : public r2cm::iItem, public r2cm::SingleTon<Generate>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Add_And_Remove : public r2cm::iItem, public r2cm::SingleTon<Add_And_Remove>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class EmptyCheck : public r2cm::iItem, public r2cm::SingleTon<EmptyCheck>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}