#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace test_p2048mini_gameprocessor
{
	class MoveReadyTest : public r2cm::iItem, public r2cm::SingleTon<MoveReadyTest>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class MoveTest : public r2cm::iItem, public r2cm::SingleTon<MoveTest>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class MergeTest : public r2cm::iItem, public r2cm::SingleTon<MergeTest>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class MovableCheck : public r2cm::iItem, public r2cm::SingleTon<MovableCheck>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}