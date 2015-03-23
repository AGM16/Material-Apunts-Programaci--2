#ifndef POINT2D
#define POINT2D

#include <math.h>

//Class with template
template<class Type>
class Point2D
{
public:
	
	
	Type px, py;


	//OPERATORS

	Point2D operator*(const Point2D& b)const
	{
		Point2D str;
		str.px = px * b.px;
		str.py = py * b.py;
		return(str);
	}

	Point2D operator/(const Point2D& b)const
	{
		Point2D str;
		str.px = px / b.px;
		str.py = py / b.py;
		return(str);
	}

	const Point2D& operator=(const Point2D& b)
	{
		px = b.px;
		py = b.py;

		return(*this);
	}


	Point2D operator+(const Point2D& b)const
	{
		
		Point2D s;
		s.px = px + b.px;
		s.py = py + b.py;

		return(s);
	}
	
	Point2D operator-(const Point2D& b)const
	{
		Point2D s;
		s.px = px - b.px;
		s.py = py - b.py;
		return(s);
	}
	const Point2D& operator-=(const Point2D& b)
	{
		px -= b.px;
		py -= b.py;
		return(*this);
	}

	const Point2D& operator+=(const Point2D& b)
	{
		px += b.px;
		py += b.py;
		return(*this);
	}


	//COMPARATORS
	bool operator==(const Point2D& b)const
	{
		return(px == b.px && py == b.py);
	}
	
	bool operator!=(const Point2D& b)const
	{
		return(px != b.px || py != b.py);
	}


	//OTHERS METHODS

	void Swap(Type& a, Type& b ){

		Type tmp = a;
		a = b;
		b = tmp;
		
	}

	bool IsZero()const
	{
		return(px == 0 && py == 0);
	}
	
	Point2D& SetZero()
	{
		px = py = 0;
		return(*this);
	}
	
	Point2D& Negate()
	{
		px = -px;
		py = -py;
		return(*this);
	}
	
	Type DistanceTo(const Point2D& b)const
	{
		Type px2 = px - b.px;
		Type py2 = py - b.py;

		return sqrt((px2 * px2) + (py2 * py2));
	}



};

#endif