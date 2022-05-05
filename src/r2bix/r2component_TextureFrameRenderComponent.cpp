#include "pch.h"
#include "r2component_TextureFrameRenderComponent.h"

#include "r2base_DebugConfig.h"
#include "r2base_Node.h"
#include "r2component_TransformComponent.h"
#include "r2render_Camera.h"
#include "r2render_TextureFrame.h"

namespace r2component
{
	TextureFrameRenderComponent::TextureFrameRenderComponent( r2base::Node& owner_node ) : r2base::Component( owner_node )
		, mPivotPoint( 0.5f, 0.5f )
		, mVisibleRect()
		, mTextureFrame( nullptr )
	{}

	std::unique_ptr<TextureFrameRenderComponent> TextureFrameRenderComponent::Create( r2base::Node& owner_node )
	{
		std::unique_ptr<TextureFrameRenderComponent> ret( new ( std::nothrow ) TextureFrameRenderComponent( owner_node ) );
		if( !ret || !ret->Init() )
		{
			ret.reset();
		}

		return ret;
	}

	void TextureFrameRenderComponent::Render( const r2render::Camera* const camera, r2render::iRenderTarget* const render_target, r2::PointInt offset )
	{
		if( nullptr == mTextureFrame )
		{
			return;
		}

		//
		// World Space : My Rect : Test
		//
		{
			const r2::RectInt my_world_space_rect( offset + mVisibleRect.GetOrigin() + mOwnerNode.mTransformComponent->GetPosition(), mVisibleRect.GetSize() );
			if( !my_world_space_rect.IntersectsRect( camera->GetRect() ) )
			{
				return;
			}
		}

		//
		// Camera Space : My Position
		//
		const auto camera_space_my_position = offset + mOwnerNode.mTransformComponent->GetPosition() - camera->GetPoint();

		//
		// Render Target Space : My Position
		//
		const auto render_target_space_my_position = camera_space_my_position - camera->GetCameraSpaceRect().GetOrigin();

		//
		// Render Target Space : My Rect
		//
		auto render_target_space_my_rect = mVisibleRect;
		render_target_space_my_rect.MoveOrigin( render_target_space_my_position.GetX(), render_target_space_my_position.GetY() );

		//
		// Render Target Space : Intersect Rect
		//
		auto render_target_space_intersect_rect = render_target->GetRect().IntersectsWithRect( render_target_space_my_rect );

		//
		// Offset
		//
		const auto off_set_point = render_target_space_intersect_rect.GetOrigin() - render_target_space_my_rect.GetOrigin();
		for( int y = render_target_space_intersect_rect.GetMinY(), ty = 0; render_target_space_intersect_rect.GetMaxY() >= y; ++y, ++ty )
		{
			for( int x = render_target_space_intersect_rect.GetMinX(), tx = 0; render_target_space_intersect_rect.GetMaxX() >= x; ++x, ++tx )
			{
				render_target->Fill(
					x, y
					, mTextureFrame->Get( off_set_point.GetX() + tx, off_set_point.GetY() + ty )
				);
			}
		}

		//
		// Debug
		//
		if( r2base::DebugConfig::GetLabelConfig().bShowPositionPivot )
		{
			render_target->Fill( render_target_space_my_position.GetX(), render_target_space_my_position.GetY(), '+' );
		}
	}

	void TextureFrameRenderComponent::SetPivotPoint( const float x, const float y )
	{
		mPivotPoint.Set( x, y );

		resetVisibleRect();
	}
	void TextureFrameRenderComponent::SetTextureFrame( const r2render::TextureFrame* const texture_frame )
	{
		mTextureFrame = texture_frame;

		resetVisibleRect();
	}
	void TextureFrameRenderComponent::resetVisibleRect()
	{
		if( !mTextureFrame )
		{
			return;
		}

		mVisibleRect.Set(
			-static_cast<int>( mTextureFrame->GetWidth() * mPivotPoint.GetX() )
			, -static_cast<int>( mTextureFrame->GetHeight() * mPivotPoint.GetY() )
			, mTextureFrame->GetVisibleRect().GetSize().GetWidth()
			, mTextureFrame->GetVisibleRect().GetSize().GetHeight()
		);
	}
}