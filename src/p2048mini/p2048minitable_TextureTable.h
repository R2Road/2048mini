#pragma once

#include "r2cm/r2cm_Singleton.h"
#include "r2bix/r2base_TextureTableBase.h"

namespace p2048minitable
{
	class TextureTable : public r2base::TextureTableBase, public r2cm::SingleTon<TextureTable>
	{
	public:
		void Load() override;
	};
}