#ifndef _QEUE_2_
#define _QEUE_2_

#include "Dynamic_Array.h"

template<class TYPE>
class Qeue_2
{
public:

	DynArray<TYPE> data;



	void Push_Q2(const TYPE& item)
	{
		data.Pushback(item);
	}


	bool Pop_End(TYPE& result)
	{
		if (Count() != NULL)
		{
			data.Pop(result);
			return true;
		}

		return false;
	}

	const TYPE* PEEK(unsigned int index)const
	{
		assert(index < Count());

		 return &data[index];	
	}

	void Clear()
	{
		data.Clear();
	}

	unsigned int Count()const
	{
		return data.Count();
	}


};

#endif