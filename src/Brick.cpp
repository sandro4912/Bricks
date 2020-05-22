#include "Brick.h"

#include <cassert>

namespace bricks {

	Brick::Brick(Point topLeft, Width width, Height height, Hitpoints hitpoints)
		:GameObject(topLeft, 
            MaxPositionX{topLeft.x + width()}, 
            MaxPositionY{topLeft.y + height()},
            width, height, Velocity{0.0}, Angle{0.0}),
        mStartHitpoints{hitpoints()},
        mHitpoints{mStartHitpoints}
	{
        assert(mHitpoints > 0);
	}

    int Brick::startHitpoints() const
	{
		return mStartHitpoints;
	}

    int Brick::hitpoints() const
	{
		return mHitpoints;
	}

	void Brick::decreaseHitpoints()
	{
        if(mHitpoints > 0) { 
		    --mHitpoints;
        }
	}

	bool Brick::isDestroyed() const
	{
		return mHitpoints == 0;
	}
}  // namespace bricks