#include "pch.h"
#include "test_p2048mini_stageviewnode.h"

#include "r2bix/r2base_Director.h"
#include "r2/r2_Inspector.h"
#include "r2cm/r2cm_eTestEndAction.h"
#include "r2bix/r2render_Camera.h"

#include "p2048mini/p2048mini_Stage.h"
#include "p2048mini/p2048mini_StageViewComponent.h"
#include "p2048mini/p2048mini_StageViewNode.h"
#include "p2048mini/p2048minitable_TextureTable.h"

#include "test/Utility4Test.h"
#include "r2bix/r2utility_WindowUtil.h"

namespace test_p2048mini_stageviewnode
{
	r2cm::iItem::TitleFuncT Generate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StageViewNode : Generate";
		};
	}
	r2cm::iItem::DoFuncT Generate::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 41, 21 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2base::Director dummy_director );

			std::cout << r2::split;

			DECLARATION_MAIN( auto stage_view_node = p2048mini::StageViewNode::Create( dummy_director ) );
			EXPECT_NE( nullptr, stage_view_node->GetComponent<p2048mini::StageViewComponent>() );

			std::cout << r2::split;

			{
				PROCESS_MAIN( stage_view_node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

				std::cout << r2::linefeed;

				Utility4Test::DrawTexture( render_target );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Setup_Render::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StageViewNode : Setup And Render";
		};
	}
	r2cm::iItem::DoFuncT Setup_Render::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			p2048minitable::TextureTable::GetInstance().Load();

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 41, 21 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2base::Director dummy_director );

			std::cout << r2::split;

			DECLARATION_MAIN( p2048mini::Stage stage( 4, 4 ) );
			PROCESS_MAIN( stage.Add( 0, 0, 32 ) );
			PROCESS_MAIN( stage.Add( 0, 1, 64 ) );
			PROCESS_MAIN( stage.Add( 3, 0, 512 ) );
			PROCESS_MAIN( stage.Add( 0, 3, 1024 ) );
			PROCESS_MAIN( stage.Add( 3, 3, 2048 ) );

			std::cout << r2::linefeed;

			DECLARATION_MAIN( auto svn = p2048mini::StageViewNode::Create( dummy_director ) );
			DECLARATION_MAIN( auto svc = svn->GetComponent<p2048mini::StageViewComponent>() );
			PROCESS_MAIN( svc->Setup( stage ) );
			PROCESS_MAIN( svn->GetComponent<r2component::TransformComponent>()->SetPosition( -svc->GetWidth() * 0.5f, -svc->GetHeight() * 0.5f ) );

			std::cout << r2::split;

			{
				PROCESS_MAIN( svn->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

				std::cout << r2::linefeed;

				Utility4Test::DrawTexture( render_target );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT UpdateView::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StageViewNode : UpdateView";
		};
	}
	r2cm::iItem::DoFuncT UpdateView::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			p2048minitable::TextureTable::GetInstance().Load();

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 41, 21 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2base::Director dummy_director );

			std::cout << r2::split;

			DECLARATION_MAIN( p2048mini::Stage stage( 4, 4 ) );
			PROCESS_MAIN( stage.Add( 0, 0, 32 ) );
			PROCESS_MAIN( stage.Add( 0, 1, 64 ) );
			PROCESS_MAIN( stage.Add( 3, 0, 512 ) );
			PROCESS_MAIN( stage.Add( 0, 3, 1024 ) );
			PROCESS_MAIN( stage.Add( 3, 3, 2048 ) );

			std::cout << r2::linefeed;

			DECLARATION_MAIN( auto svn = p2048mini::StageViewNode::Create( dummy_director ) );
			DECLARATION_MAIN( auto svc = svn->GetComponent<p2048mini::StageViewComponent>() );
			PROCESS_MAIN( svc->Setup( stage ) );
			PROCESS_MAIN( svc->UpdateView() );
			PROCESS_MAIN( svn->GetComponent<r2component::TransformComponent>()->SetPosition( -svc->GetWidth() * 0.5f, -svc->GetHeight() * 0.5f ) );

			std::cout << r2::split;

			{
				PROCESS_MAIN( svn->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

				std::cout << r2::linefeed;

				Utility4Test::DrawTexture( render_target );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}