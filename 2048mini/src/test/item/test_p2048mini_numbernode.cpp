#include "test_p2048mini_numbernode.h"

#include "r2bix/r2base_Director.h"
#include "r2bix/r2render_Camera.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

#include "p2048mini/p2048mini_NumberComponent.h"
#include "p2048mini/p2048mini_NumberNode.h"

#include "test/Utility4Test.h"

namespace test_p2048mini_numbernode
{
	r2cm::TitleFunctionT Generate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "NumberNode : Generate";
		};
	}
	r2cm::DoFunctionT Generate::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 21, 11 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2base::Director dummy_director );

			LS();

			DECLARATION_MAIN( auto number_node = p2048mini::NumberNode::Create( dummy_director ) );
			EXPECT_NE( nullptr, number_node->GetComponent<p2048mini::NumberComponent>() );

			LS();

			{
				PROCESS_MAIN( number_node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

				LF();

				Utility4Test::DrawTexture( render_target );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT SetNumber::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "NumberNode : SetNumber";
		};
	}
	r2cm::DoFunctionT SetNumber::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 11, 5 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2base::Director dummy_director );
			DECLARATION_MAIN( auto number_node = p2048mini::NumberNode::Create( dummy_director ) );

			LS();

			{
				PROCESS_MAIN( number_node->GetComponent<p2048mini::NumberComponent>()->SetNumber( 2048, false, false ) );
				number_node->Render( &camera, &render_target, r2::PointInt::GetZERO() );
				Utility4Test::DrawTexture( render_target );
				EXPECT_EQ( r2base::BG_Black, render_target.GetColor( 1, 1 ) );
				EXPECT_EQ( r2base::BG_Black | r2base::FG_Aqua, render_target.GetColor( 6, 2 ) );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( number_node->GetComponent<p2048mini::NumberComponent>()->SetNumber( 1024, true, false ) );
				number_node->Render( &camera, &render_target, r2::PointInt::GetZERO() );
				Utility4Test::DrawTexture( render_target );
				EXPECT_EQ( r2base::BG_Aqua, render_target.GetColor( 1, 1 ) );
				EXPECT_EQ( r2base::BG_Aqua | r2base::FG_Black, render_target.GetColor( 6, 2 ) );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( number_node->GetComponent<p2048mini::NumberComponent>()->SetNumber( 512, true, true ) );
				number_node->Render( &camera, &render_target, r2::PointInt::GetZERO() );
				Utility4Test::DrawTexture( render_target );
				EXPECT_EQ( r2base::BG_Aqua, render_target.GetColor( 1, 1 ) );
				EXPECT_EQ( r2base::BG_Aqua | r2base::FG_Black, render_target.GetColor( 6, 2 ) );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( number_node->GetComponent<p2048mini::NumberComponent>()->SetNumber( 4096, false, true ) );
				number_node->Render( &camera, &render_target, r2::PointInt::GetZERO() );
				Utility4Test::DrawTexture( render_target );
				EXPECT_EQ( r2base::BG_Black, render_target.GetColor( 1, 1 ) );
				EXPECT_EQ( r2base::BG_Black | r2base::FG_LightYellow, render_target.GetColor( 6, 2 ) );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}