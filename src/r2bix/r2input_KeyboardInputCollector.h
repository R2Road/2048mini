#pragma once

#include <vector>

#include "r2input_Constant.h"

namespace r2input
{
	class KeyboardInputListener;

	class KeyboardInputCollector
	{
	public:
		KeyboardInputCollector();

		//
		//
		//
		void Collect();

		//
		//
		//
		void ClearListener()
		{
			mKeyboardInputListener = nullptr;
		}
		void AddListener( KeyboardInputListener* listener )
		{
			mKeyboardInputListener = listener;
		}
		void RemoveListener( KeyboardInputListener* listener )
		{
			if( listener == mKeyboardInputListener )
			{
				mKeyboardInputListener = nullptr;
			}
		}

	private:
		KeyboardInputListener* mKeyboardInputListener;
	};
}