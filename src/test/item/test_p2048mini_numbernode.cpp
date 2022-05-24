#include "test_p2048mini_numbernode.h"

#include "r2bix/r2base_Director.h"
#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_constant.h"
#include "r2bix/r2render_Camera.h"

#include "p2048mini/p2048mini_NumberComponent.h"
#include "p2048mini/p2048mini_NumberNode.h"

#include "test/Utility4Test.h"
#include "r2cm/r2cm_WindowUtility.h"

namespace test_p2048mini_numbernode
{
	r2cm::iItem::TitleFuncT Generate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "NumberNode : Generate";
		};
	}
	r2cm::iItem::DoFuncT Generate::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 21, 11 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2base::Director dummy_director );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto number_node = p2048mini::NumberNode::Create( dummy_director ) );
			EXPECT_NE( nullptr, number_node->GetComponent<p2048mini::NumberComponent>() );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( number_node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

				std::cout << r2cm::linefeed;

				Utility4Test::DrawTexture( render_target );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT SetNumber::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "NumberNode : SetNumber";
		};
	}
	r2cm::iItem::DoFuncT SetNumber::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 11, 5 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2base::Director dummy_director );
			DECLARATION_MAIN( auto number_node = p2048mini::NumberNode::Create( dummy_director ) );

			std::cout << r2cm::split;

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

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}