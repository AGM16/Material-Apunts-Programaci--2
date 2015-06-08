#ifndef OT_FUNCTIONS
#define OT_FUNCTIONS


template <class TYPE> void Swap(TYPE& a, TYPE& b)
{
	TYPE c = a;
	a = b;
	b = c;
}
#endif