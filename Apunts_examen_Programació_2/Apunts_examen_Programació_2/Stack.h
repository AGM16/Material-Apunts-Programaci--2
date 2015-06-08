#ifndef _STACK_
#define _STACK_

#define NULL 0

template<class VALUE>
class Stack
{
private:
	//Atributs
	VALUE* data;
	unsigned int num_elements;
	unsigned int mem_capacity;

public:

	//Default constructor
	Stack(){ data = NULL; num_elements = 0; mem_capacity = 0; Alloc(DYNARRAY_MEMORY); }
	//Copy Constructor
	Stack(unsigned int capacity){ data = NULL; num_elements = 0; mem_capacity = 0; Alloc(capacity); }

    //Destructor
	~Stack()
	{
		delete[] data;
	}

	void Push(const VALUE& _data)
	{
		if (num_elements + 1 > mem_capacity)
		{
			Alloc(mem_capacity + DYNARRAY_MEMORY);
		}

		data[num_elements++] = _data;
	}

	VALUE Pop()
	{
		if (num_elements > 0)
		{
			return data[--num_elements];
		}

		return false;
	}
	
	bool Pop_2(VALUE& value)
	{
		if (num_elements > 0)
		{
			value = data[--num_elements];
			return true;
		}

		return false;
	}

	void Clear()
	{
		num_elements = 0;
	}

	VALUE* PEEK(unsigned int index)
	{
		assert(index < num_elements);

		VALUE* value_return = NULL;

		value_return = &data[index];

		return value_return;
	}

	const VALUE* PEEK(unsigned int index)const
	{
		assert(index < num_elements);

		VALUE* value_return = NULL;

		value_return = &data[index];

		return value_return;
	}

	unsigned int Count()const
	{
		return num_elements;
	}

	unsigned int Capacity()const
	{
		return mem_capacity;
	}

	VALUE PeekLast()
	{
		if (num_elements >= 1)
		{
			return data[num_elements - 1];
		}
		return NULL;

	}

private:

	void Alloc(unsigned int memory)
	{
		VALUE* tmp = data;

		mem_capacity = memory;
		data = new VALUE[mem_capacity];

		if (num_elements > mem_capacity)
		{
			num_elements = mem_capacity;
		}

		if (tmp != NULL)
		{
			for (unsigned int a = 0; a < num_elements; a++)
			{
				data[a] = tmp[a];

			}
			delete[] tmp;
		}
	}


};

#endif