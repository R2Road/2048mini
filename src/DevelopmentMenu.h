#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;
}

class DevelopmentMenu
{
private:
	DevelopmentMenu() = delete;

public:
	static const char* GetTitle() { return "Development : r2bix v0.0.1"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};