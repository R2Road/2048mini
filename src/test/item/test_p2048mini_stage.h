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

	class Add_Remove_ClearAll : public r2cm::iItem, public r2cm::SingleTon<Add_Remove_ClearAll>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class IsIn : public r2cm::iItem, public r2cm::SingleTon<IsIn>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class NumberCount_EmptyCount_IsFull : public r2cm::iItem, public r2cm::SingleTon<NumberCount_EmptyCount_IsFull>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Lock_Newcomer : public r2cm::iItem, public r2cm::SingleTon<Lock_Newcomer>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}