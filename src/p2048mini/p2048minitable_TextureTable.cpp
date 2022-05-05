#include "pch.h"
#include "p2048minitable_TextureTable.h"

#include "r2bix/r2render_Texture.h"
#include "r2bix/r2render_TextureFrame.h"

namespace p2048minitable
{
	void TextureTable::Load()
	{
		if( !mTextureContainer.empty() )
		{
			return;
		}

		{
			auto result = mTextureContainer.emplace( "p2048mini_image", TextureValueT( new ( std::nothrow ) r2render::Texture(
				71,
				//		"          1         2         3         4         5         6         7"
				//		"01234567890123456789012345678901234567890123456789012345678901234567890"
				/* 0 */ "##########B                                                            "
				/* 1 */ "#        #B   ###    ###    # #   #####     ###   #   #  #####   ###   "
				/* 2 */ "#        #B  #      #   #  # # #  #        #   #  #   #  #      #   #  "
				/* 3 */ "#        #B  # ###  ### #  # # #  #####    #   #  #   #  #####  ####   "
				/* 4 */ "##########B  #   #  #   #  # # #  #        #   #   # #   #      #   #  "
				/* 5 */ "              ###   #   #  # # #  # ###     ###     #    # ###  #   #  "
				/* 6 */ "                                                                       "
				/* 7 */ " 22222    00000    4  4     88888                                      "
				/* 8 */ "2     2  0     0  4   4    8     8  M                                  "
				/* 9 */ "  2222   0     0  4   4     88888   I                                  "
				/* 0 */ "22       0     0  4444444  8     8  N                                  "
				/* 1 */ "2222222   00000       4     88888   I                                  "
				/* 2 */ "                                                                       "
				/* 3 */ "[   ESC   ] Exit                                                       "
				/* 4 */ "[ W,A,S,D ] Move Number                                                "
				/* 5 */ "[    R    ] Restart                                                    "
				/* 6 */ "                                                                       "
				/* 7 */ "  #   #   ###   #   #    #   #   #####  #   #   B                      "
				/* 8 */ "  #   #  #   #  #   #    # # #     #    ##  #   B                      "
				/* 9 */ "   # #   #   #  #   #    # # #     #    # # #   B                      "
				/* 0 */ "    #    #   #  #   #    # # #     #    #  ##   B                      "
				/* 1 */ "    #     ###    ###      # #    #####  #   #   B                      "
				/* 2 */ "                                                                       "
			) ) );

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"number_frame_0"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 1, 1, 7, 2 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"title_0"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 0, 7, 36, 4 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"keyinfo_0"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 0, 13, 22, 2 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"game_over_0"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 11, 0, 59, 6 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"you_win_0"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( 0, 16, 47, 22 );
			}
		}
	}
}