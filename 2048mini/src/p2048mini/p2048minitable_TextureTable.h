#pragma once

#include "r2/r2_SingletonWithStaticVariable.h"
#include "r2bix/r2base_TextureTableBase.h"

namespace p2048minitable
{
	class TextureTable : public r2base::TextureTableBase, private r2::SingletonWithStaticVariable<TextureTable>
	{
	public:
		using r2::SingletonWithStaticVariable<TextureTable>::GetInstance;

	public:
		void Load() override;
	};
}