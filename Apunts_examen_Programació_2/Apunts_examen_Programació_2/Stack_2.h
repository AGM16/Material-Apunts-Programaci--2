#ifndef _STACK_2_
#define _STACK_2_

#include "Double_List.h"

template<class TYPE>
class Stack_2
{

private:

	DLinkList<TYPE> data;

public:

	void Push_s2(const TYPE& _data)
	{
		data.add(_data);
	}

	bool Pop_s2(TYPE& result)
	{
		if (data.Count() != NULL)
		{
			result = data.end->data;
			data.del(data.end);
			return true;
		}

		return false;
	}

	void Clear()
	{
		data.Clear();
	}

	unsigned int Count()const
	{
		return data.Count();
	}

	const TYPE* PEEK_s2(unsigned int index)const
	{
		if (index < data.Count())
		{
			return &data[index];
		}
		return NULL;
	}




};

#endif