#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace test_p2048mini_stage
{
	class Generate : public r2cm::iItem, public r2cm::SingleTon<Generate>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Add_Remove_ClearAll : public r2cm::iItem, public r2cm::SingleTon<Add_Remove_ClearAll>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class IsIn : public r2cm::iItem, public r2cm::SingleTon<IsIn>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class NumberCount_EmptyCount_IsFull : public r2cm::iItem, public r2cm::SingleTon<NumberCount_EmptyCount_IsFull>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Lock : public r2cm::iItem, public r2cm::SingleTon<Lock>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Newcomer : public r2cm::iItem, public r2cm::SingleTon<Newcomer>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}