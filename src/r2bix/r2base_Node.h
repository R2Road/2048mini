#pragma once

#include <list>
#include <memory>
#include <type_traits>

#include "r2/r2_Point_Int.h"
#include "r2component_TransformComponent.h"

//
// # 2022.02.28 by R2Road
//
// 컴포넌트 기반 시스템을 써본 경험은 있으나 만들어 본 경험이 없으니 여기서 해본다.
//
// 노드와 컴포넌트를 조합하여 특정 기능을 가진 표준 노드를 제작한다.
// 사용자 정의 노드의 제작은 가급적 없도록 노력하자.
//

namespace r2component
{
	class TransformComponent;
}

namespace r2render
{
	class Camera;
	class iRenderTarget;
}

namespace r2base
{
	class Director;

	using NodeUp = std::unique_ptr<class Node>;
	class Node
	{
	protected:
		using ComponentContainerT = std::list<ComponentUp>;
		using ChildContainerT = std::list<r2base::NodeUp>;

		Node( Director& director );

	public:
		virtual ~Node() {}

	static std::unique_ptr<Node> Create( r2base::Director& director );

	public:
		virtual bool Init();
		virtual void Update( const float delta_time );
		virtual void Render( const r2render::Camera* const camera, r2render::iRenderTarget* const render_target, r2::PointInt offset );

		//
		//
		//
		Director& GetDirector() const { return mDirector; }
		bool IsVisible() const { return mbVisible; }
		void SetVisible( const bool visible )
		{
			mbVisible = visible;
		}

		//
		//
		//
		template<typename ComponentT>
		ComponentT* const GetComponent() const
		{
			for( auto& c : mComponentContainer )
			{
				if( r2base::ComponentStaticID<ComponentT>::Get() == c->GetStaticID() )
				{
					return static_cast<ComponentT*>( c.get() );
				}
			}

			return nullptr;
		}
		template<typename ComponentT>
		ComponentT* AddComponent()
		{
			static_assert( std::is_base_of<r2base::Component, ComponentT>() );

			if( GetComponent<ComponentT>() )
			{
				return nullptr;
			}

			auto component = ComponentT::Create( *this );
			auto ret = component.get();
			mComponentContainer.push_back( std::move( component ) );

			return ret;
		}

		//
		//
		//
		template<typename NodeT>
		Node* AddChild()
		{
			return AddChild<NodeT>( 0 );
		}
		template<typename NodeT>
		Node* AddChild( const int32_t z_order )
		{
			static_assert( std::is_base_of<r2base::Node, NodeT>() );

			auto child_node = NodeT::Create( mDirector );
			child_node->mTransformComponent->SetZ( z_order );

			auto ret = child_node.get();

			//
			// Find Insert Pivot
			//
			auto cur = mChildContainer.begin();
			for( auto end = mChildContainer.end(); end != cur; ++cur )
			{
				if( z_order <= ( *cur )->mTransformComponent->GetZ() )
				{
					break;
				}
			}

			//
			// Insert
			//
			if( cur == mChildContainer.end() )
			{
				mChildContainer.push_back( std::move( child_node ) );
			}
			else
			{
				mChildContainer.insert( cur, std::move( child_node ) );
			}

			return ret;
		}

	protected:
		Director& mDirector;
		bool mbVisible;
		ComponentContainerT mComponentContainer;
		ChildContainerT mChildContainer;
	public:
		r2component::TransformComponent* mTransformComponent;
	};
}