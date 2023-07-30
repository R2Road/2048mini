#pragma once

#include "r2tm/r2tm_iMenu.h"

class DevelopmentMenu : public r2tm::iMenu
{
public:
	r2tm::TitleFunctionT GetTitleFunction() const override;
	r2tm::DescriptionFunctionT GetDescriptionFunction() const override;
	r2tm::WriteFunctionT GetWriteFunction() const override;
};