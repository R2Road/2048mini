#include "r2_Direction4.h"

namespace r2
{
	Direction4::Direction4() : mState( eState::Up )
	{}
	Direction4::Direction4( const eState state ) : mState( state )
	{}

	void Direction4::Rotate( const bool rotate_right )
	{
		char new_state = 0;
		if( rotate_right )
		{
			new_state = static_cast<char>( mState << 1 );
			if( eState::LAST < new_state )
			{
				new_state = eState::FIRST;
			}
		}
		else
		{
			new_state = static_cast<char>( mState >> 1 );
			if( eState::None >= new_state )
			{
				new_state = eState::LAST;
			}
		}

		mState = static_cast<eState>( new_state );
	}

	r2::PointInt Direction4::GetPoint() const
	{
		r2::PointInt out_point;

		switch( mState )
		{
		case Direction4::eState::Up:
			out_point = r2::Point{ 0, 1 };
			break;
		case Direction4::eState::Right:
			out_point = r2::Point{ 1, 0 };
			break;
		case Direction4::eState::Down:
			out_point = r2::Point{ 0, -1 };
			break;
		case Direction4::eState::Left:
			out_point = r2::Point{ -1, 0 };
			break;

		default:
			out_point = r2::Point{ 0, 0 };
			break;
		}

		return out_point;
	}
	r2::PointInt::ValueT Direction4::GetX() const
	{
		return GetPoint().GetX();
	}
	r2::PointInt::ValueT Direction4::GetY() const
	{
		return GetPoint().GetY();
	}
}
