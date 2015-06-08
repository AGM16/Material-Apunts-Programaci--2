#ifndef POINT
#define POINT

#include <math.h>

template<class TYPE>
class Point
{
public:

	TYPE x, y;

	//Constructor
	Point(){ x = 0; y = 0; }
	Point(const TYPE _x, const TYPE _y){ x = _x; y = _y; }

	//Destructor
	~Point()
	{}

	//Operators

	//1) Plus (+)
	Point operator +(const Point& a)
	{
		Point tmp;
		tmp.x = x + a.x;
		tmp.y = y + a.y;
		return tmp;
	}

	Point operator -(const Point& a)
	{
		Point tmp;
		tmp.x = x - a.x;
		tmp.y = y - a.y;
		return tmp;
	}

	const Point& operator += (const Point& a)
	{
		x += a.x;
		y += a.y;
		return(*this);
	}

	const Point& operator -= (const Point& a)
	{
		x -= a.x;
		y -= a.y;
		return(*this);
	}

	bool operator ==(const Point& a)const
	{
		return(x == a.x && y == a.x);
	}

	bool operator !=(const Point& a)const
	{
		return(x != a.x && y != a.y);
	}

	/*Point operator = (const Point& a)
	{
	x = a.x;
	y = a.y;
	return(*this);
	}*/

	//Methods

	bool IsZero()
	{
		return(x == 0 && y == 0);
	}

	void SetZero()
	{
		x = y = 0;
	}

	void Swap(Point& a)
	{
		Point tmp;
		tmp.x = x;
		x = a.x;
		a.x = tmp.x;

		tmp.y = y;
		y = a.y;
		a.y = tmp.y;

	}

	void Negate()
	{
		x = -x;
		y = -y;
	}

	int distanceTo(const Point& a)
	{
		return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));

	}

	int get_x()const{ return x; }
	int get_y()const{ return y; }

};
#endif