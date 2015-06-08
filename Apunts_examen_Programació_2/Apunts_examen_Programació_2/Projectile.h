#pragma once
#include "Point.h"

class Projectile
{
public:

	//Atributes
	Point<float> point;
	Point<float> speed;

public:

	Projectile()
	{
		point.SetZero();
		speed.SetZero();
	}

	//Method
	//-------------------------

		Point<float> GetCurrentPoisition(float time)const
		{
			Point<float> tmp;
			tmp.x = point.x + (speed.x * time);
			tmp.y = point.y + (speed.y * time);

			return tmp;
		}
	
};
