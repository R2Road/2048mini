#pragma once

#include "r2base_Component.h"
#include "r2base_ComponentStaticID.h"

#include "r2/r2_Point_Int.h"

namespace r2component
{
	class TransformComponent : public r2base::Component
	{
	private:
		TransformComponent( r2base::Node& owner_node );

	public:
		int GetStaticID() const override { return r2base::ComponentStaticID<TransformComponent>::Get(); }
		static std::unique_ptr<TransformComponent> Create( r2base::Node& owner_node );

		//
		//
		//
		r2::PointInt GetPosition() const
		{
			return mPosition;
		}
		int32_t GetZ() const
		{
			return mZOrder;
		}

		//
		//
		//
		void SetPosition( const int32_t new_x, const int32_t new_y )
		{
			mPosition.Set( new_x, new_y );
		}
		void SetPosition( const float new_x, const float new_y )
		{
			mPosition.Set( static_cast<int>( new_x ), static_cast<int>( new_y ) );
		}
		void SetPosition( const r2::PointInt new_position )
		{
			mPosition = new_position;
		}
		void SetZ( const int32_t new_z_order )
		{
			mZOrder = new_z_order;
		}

	private:
		r2::PointInt mPosition;
		int32_t mZOrder;
	};
}