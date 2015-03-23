#ifndef DINAMICARRAY
#define DINAMICARRAY
#include <assert.h>

#define DNY_ARRAY_MEM_RESERVE 16

template< class Type1>
class DinamicArray
{
private:

	Type1* i_data;
	unsigned int in_num_elements;
	unsigned int in_memory;

public:

	//Constructors
	DinamicArray( int in_capacity){ i_data = NULL; in_num_elements = 0; in_memory = 0; Alloc(in_capacity);}
	DinamicArray() : i_data(NULL), in_num_elements(0), in_memory(0){};

	~DinamicArray(){
		delete[] i_data;
	}

	//Methods
	void Insert(const Type1& value, unsigned int pos)
	{
		if (pos >= 0 && pos <= in_num_elements && in_memory + 1 > in_num_elements)
		{
			Type1* tmpHead = new Type1[(pos + 1)];
			Type1* tmpTail = new Type1[(in_num_elements - pos)];

			CopyArray(tmpHead, i_data, pos, 0);
	
			tmpHead[pos] = value;

			int counter = 0;
			
			for (int i = pos; i < in_num_elements; i++)
			{
				tmpTail[counter] = i_data[i];
				counter++;
			}

			if (in_memory == in_num_elements)
			{
				Alloc(in_num_elements + 1); 
			}

			CopyArray(i_data, tmpHead, in_num_elements, 0);

			counter = 0;
			for (int i = pos + 1; i < in_num_elements; i++)
			{
				i_data[i] = tmpTail[counter]; 
				counter++;
			}

			delete[] tmpHead;
			delete[] tmpTail;
		}

		if (in_memory && in_num_elements == 0)
		{
			Alloc(1);
			i_data[in_num_elements - 1] = value;
		}
		
		

}

	void PushBack(const Type1& value)
	{
		if (in_num_elements - in_memory == 0)
		{
			Type1* tmp = new Type1[in_num_elements];
			CopyArray(tmp, i_data, in_num_elements, 0);
			Alloc(in_memory + 1);
			CopyArray(i_data, tmp, in_num_elements, 0);
			i_data[in_num_elements - 1] = value;
		}
		
		else
			
		i_data[in_num_elements ++] = value;
			
	

	}

	 
	bool Pop1()
	{
		int value = 0;
		if (in_num_elements > 0)
		{
			value = i_data[--in_num_elements];
			return true;
		}
		else
			return false;

		
	}

	void CopyArray(int* destiny, int* origin, unsigned int elements, unsigned int a)
	{
		for (unsigned int i = a; i < elements; i++)
		{
			destiny[i] = origin[i];
		}

	}

	
	const Type1& operator[](unsigned int pos)const
	{
		assert(pos < in_num_elements);
		return i_data[pos];
	}

	
	Type1& operator[](unsigned int pos)
	{
		assert(pos < in_num_elements);
		return i_data[pos];
	}


	Type1* At(unsigned int index)
	{
		Type1* result = NULL;

		if (index < in_num_elements)
			return result = &i_data[index];

		return result;
	}

	const Type1* At(unsigned int index) const
	{
		Type1* result = NULL;

		if (index < in_num_elements)
			return result = &i_data[index];

		return result;
	}

	
	void Clear()
	{
		in_num_elements = 0;
	}

	
	unsigned int GetCapacity()const
	{
		return in_memory;
	}

	
	unsigned int Count()const
	{
		return in_num_elements;
	}
    




private:
	
	void Alloc(unsigned int new_memory)
	{
		assert(new_memory > 0);
		i_data = new Type1[new_memory];
		in_memory = new_memory;
		in_num_elements = in_memory;
	}
		

};
#endif