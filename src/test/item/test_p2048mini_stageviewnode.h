#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace test_p2048mini_stageviewnode
{
	class Generate : public r2cm::iItem, public r2::SingleTon<Generate>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Setup_Render : public r2cm::iItem, public r2::SingleTon<Setup_Render>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class UpdateView : public r2cm::iItem, public r2::SingleTon<UpdateView>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}