#ifndef DYNARRAY
#define DYNARRAY

#define NULL 0
#define DYNARRAY_MEMORY 140

#include <assert.h>
#include "Others_Functions.h"

template<class VALUE>
class DynArray
{
private:

	//Atributs
	VALUE* data;
	unsigned int num_elements;
	unsigned int mem_capacity;

public:

	//CONSTRUCTORS
	//----------------------------
	    //Default constructor
	    DynArray(){ data = NULL; num_elements = 0; mem_capacity = 0; Alloc(DYNARRAY_MEMORY);}
	    //Copy Constructor
	    DynArray(unsigned int capacity){ data = NULL; num_elements = 0; mem_capacity = 0; Alloc(capacity);}

	//DESTRUCTOR
    //----------------------------
	    ~DynArray()
	    {
		   delete[] data;
	    }

	//METHODS
	//----------------------------

		
    
		VALUE& operator[]( unsigned int index)
		{
			assert(index < num_elements);
			return data[index];
		}

		const VALUE& operator[]( unsigned int index)const
		{
			assert(index < num_elements);
			return data[index];
		}

		void Pushback(const VALUE& _data)
		{
			if (num_elements + 1 > mem_capacity)
			{
				Alloc(mem_capacity + DYNARRAY_MEMORY);
			}
			
			data[num_elements++] = _data;
		}

		bool Pop(VALUE& value)
		{
			if (num_elements > 0)
			{
				value = data[--num_elements];
				return true;
			}

			return false;
		}

		bool Pop_data(unsigned int position)
		{
			if (num_elements > 0 && position < num_elements)
			{
				for (unsigned int m = position; m < num_elements - position; m++)
				{
					data[m] = data[m + 1];
				}

				--num_elements;
				return true;
			}
			return false;
		}

		bool del_Space()
		{
			unsigned int spaces = 0;
			unsigned int first_spaces = 0; 
			unsigned int last_spaces = num_elements;
			unsigned int letters = 0;
			if (num_elements > 0)
			{
				if (data[spaces] == ' ')
				{
					unsigned int pos = 0;
					for (unsigned int m = 0; m < num_elements; m++)
					{
						if (data[m] != ' ')
						{
							Swap(data[pos], data[m]);
							pos++;
						}
					}
				}

				if (data[spaces] != ' ' && data[last_spaces - 1] == ' ')
				{
					while (data[last_spaces - 1] == ' ')
					{
							VALUE _value;
							Pop(_value);
							last_spaces--;
					}
				}
				return true;
			}
			return false;

		}


		//Afegir una dada mes en un array
		bool Insert(VALUE& _data, unsigned int position)
		{
			if (position > num_elements)
			{
				return false;
			}

			if (position == num_elements)
			{
				Pushback(_data);
			}

			if (num_elements + 1 > mem_capacity)
			{
				Alloc(mem_capacity + DYNARRAY_MEMORY);
			}

			for (unsigned int a = num_elements; a > position; a--)
			{
				data[a] = data[a - 1];
			}

			data[position] = _data;
			++num_elements;
			return true;
		}

		bool Insert_middle(const DynArray& _array)
		{
			if (num_elements == NULL)
			{
				for (unsigned int a = 0; a < _array.num_elements; a++)
				{
					Pushback(_array.data[a]);
				}
			
				return true;
			}

			if (_array.num_elements == NULL)
			{
				return false;
			}

			if (_array.num_elements + 1 > mem_capacity)
			{
				Alloc(mem_capacity + DYNARRAY_MEMORY);
			}

			unsigned int middle = Count() / 2;
			
			if (middle % 2 != 0)
			{
				middle += 1;
			}

			for (unsigned int a = 0; a < _array.num_elements; a++)
			{
				Insert(_array.data[a], middle);
				middle++;
			}
			
			return true;
		}

		unsigned int Find(const DynArray& _array)
		{
			unsigned int letters = 0;
			unsigned int array_in = 0;

			for (unsigned int i = 0; i < num_elements; i++)
			{
				if (data[i] == _array.data[i])
				{
					letters++;
					if (letters == _array.num_elements)
					{
						array_in += 1;
					}
				}
				else
				{
					letters = 0;
				}
			}

			return array_in;
		}

		//An other form to writte insert middle
		/*bool Insert(const p2DynArray<VALUE>& array, unsigned int position)
		{
			if (position > num_elements)
				return false;

			if (num_elements + array.num_elements > mem_capacity)
				Alloc(num_elements + array.num_elements + 1);

			for (unsigned int i = position; i < position + array.num_elements; ++i)
			{
				data[i + array.num_elements] = data[i];
				data[i] = array[i - position];
				++num_elements;
			}

			return true;
		}*/

		//Pone el array al inrevés
		void Flip()
		{
			VALUE* start = &data[0];
			VALUE* end = &data[num_elements - 1];

			while (start < end)
			{
				Swap(*start++, *end--);
			}
		}

		void BubleSort()
		{
			bool swaped = true;

			while (swaped)
			{
				swaped = false;
				for (unsigned int i = 0; i < num_elements - 1; i++)
				{
					if (data[i] > data[i + 1])
					{
						Swap(data[i], data[i + 1]);
						swaped = true;
					}
				}
			}
		}

		VALUE* At(unsigned int index)
		{
			assert(index < num_elements);

			VALUE* value_return = NULL;

			value_return = &data[index];

			return value_return;
		}

		const VALUE* At(unsigned int index)const
		{
			assert(index < num_elements);

			VALUE* value_return = NULL;

			value_return = &data[index];

			return value_return;
		}


		unsigned int removeWastedMemory()
		{
			assert(num_elements != NULL);
			if (num_elements == mem_capacity)
			{
				return NULL;
			}

			unsigned int wast_memory = mem_capacity - num_elements;
			if (wast_memory != 0)
			{
				Alloc(num_elements);//Eliminar espais fent un nou Alloc
			}

			return wast_memory;	
		}


	//OTHERS METHODS
    //-------------------------
	 
	   void Clear()
	   {
		   num_elements = 0;
	   }

		
	   unsigned int Count()const
	   {
		   return num_elements;
	   }

	   unsigned int Capacity()const
	   {
		   return mem_capacity;
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