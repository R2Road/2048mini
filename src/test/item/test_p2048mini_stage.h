#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace test_p2048mini_stage
{
	class Basic : public r2cm::iItem, public r2cm::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class MoveReadyTest : public r2cm::iItem, public r2cm::SingleTon<MoveReadyTest>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class MoveTest : public r2cm::iItem, public r2cm::SingleTon<MoveTest>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class MergeTest : public r2cm::iItem, public r2cm::SingleTon<MergeTest>
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

	class MovableCheck : public r2cm::iItem, public r2cm::SingleTon<MovableCheck>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}