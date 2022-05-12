#include "r2base_Director.h"

#include <utility> // std::move

#include "r2node_SceneNode.h"

namespace r2base
{
	Director::Director() :
		mScreenBufferManager()
		, mFPSTimer()
		, mbAbort( false )
		, mScreenBufferSIze( 107, 53 )

		, mKeyboardInputCollector()

		, mCurrentSceneNode()
		, mNextSceneNode()
	{}

	void Director::Setup( r2node::SceneNodeUp node )
	{
		if( mCurrentSceneNode )
		{
			mNextSceneNode = std::move( node );
		}
		else
		{
			mCurrentSceneNode = std::move( node );
		}
	}

	void Director::Run()
	{
		ClearScreen();

		while( !mbAbort )
		{
			if( mNextSceneNode )
			{
				mCurrentSceneNode = std::move( mNextSceneNode );
			}

			if( mFPSTimer.Update() )
			{
				mKeyboardInputCollector.Collect();

				mCurrentSceneNode->Update( mFPSTimer.GetElapsedTime() );
				mCurrentSceneNode->Render();

				mScreenBufferManager.InitCursor();
				mScreenBufferManager.Swap();
			}
		}
	}

	void Director::ClearScreen()
	{
		mScreenBufferManager.ClearCurrentBuffer();
	}

	void Director::Write2BackBuffer( const r2render::Texture* const texture )
	{
		mScreenBufferManager.Write2BackBuffer( texture );
	}

	void Director::AddInputListener( r2input::KeyboardInputListener* const keyboard_input_listener )
	{
		mKeyboardInputCollector.AddListener( keyboard_input_listener );
	}
	void Director::RemoveInputListener( r2input::KeyboardInputListener* const keyboard_input_listener )
	{
		mKeyboardInputCollector.RemoveListener( keyboard_input_listener );
	}
}