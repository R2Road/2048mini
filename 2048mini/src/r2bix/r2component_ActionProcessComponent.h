#pragma once

#include <vector>

#include "r2base_Action.h"
#include "r2base_Component.h"
#include "r2base_ComponentStaticID.h"

namespace r2component
{
	class ActionProcessComponent : public r2base::Component
	{
	private:
		ActionProcessComponent( r2base::Node& owner_node );

	public:
		int GetStaticID() const override { return r2base::ComponentStaticID<ActionProcessComponent>::Get(); }
		static std::unique_ptr<ActionProcessComponent> Create( r2base::Node& owner_node );

		//
		//
		//
		void SetAction( r2base::ActionUp action )
		{
			mAction = std::move( action );
		}
		bool HasAction() const { return ( nullptr != mAction ); }
		void StartAction();
		bool IsRunning() const { return mbStart; }

		//
		// Override
		//
		void Update( const float delta_time ) override;

	private:
		r2base::ActionUp mAction;
		bool mbStart;
	};
}