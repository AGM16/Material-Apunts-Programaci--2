#ifndef DOUBLE_LIST
#define DOUBLE_LIST

#define NULL 0


template<class TYPE>
struct DList_Node
{
	TYPE data;
	DList_Node<TYPE>* next;
	DList_Node<TYPE>* prev;

	inline DList_Node(const TYPE& _data)
	{
		data = _data;
		next = prev = NULL;
	}

	~DList_Node()
	{}

};


template<class TYPE>
class DLinkList
{
	public:
		//Atributs
		DList_Node<TYPE>* start;
		DList_Node<TYPE>* end;

    private:

	unsigned int size;

    public:

	//Constructor
	DLinkList()
	{
		size = 0;
		start = end = NULL;
	}

	//Destructor
	~DLinkList()
	{
		//Function Clear
	}

	//Methods
	//--------------------------------

	unsigned int add(const TYPE& _data)
	{
		DList_Node<TYPE>* new_node;
		new_node = new DList_Node<TYPE>(_data);
		


		if (start == NULL)
		{
			start = end = new_node;
		}
		else
		{
			end->next = new_node;
			new_node->prev = end;
			end = new_node;
		}

		return(size++);

	}


	bool del(DList_Node<TYPE>* item)
	{
		if (item == NULL)
		{
			return (false);
		}

		// Now reconstruct the list
		if (item->prev != NULL)
		{
			

			if (item->next != NULL)
			{   
				item->prev->next = item->next;
				item->next->prev = item->prev;
			}
			else
			{
				item->prev->next = item->next;
				end = item->prev;
			}
		}
		else
		{
			if (item->next)
			{
				item->next->prev = NULL;
				start = item->next;
			}
			else
			{
				start = end = NULL;
			}
		}

		delete item;
		size--;
		return(true);
	}

	//Del nodes from a position
	bool delNodes(unsigned int position, unsigned int nodes_del)
	{

		if (size == NULL)
		{
			return false;
		}

		if (position > size)
		{
			return false;
		}

		unsigned int n_to_del = size - position;

		if (nodes_del > n_to_del)
		{
			return false;
		}

		DList_Node<TYPE>* first_node = start;
		unsigned int ret = 0;

		for (int i = 0; i < position; i++)
		{
			first_node = first_node->next;
		}

		DList_Node<TYPE>* last_node = first_node;

		for (unsigned int i = 1; i < nodes_del && last_node->next != NULL; i++)
		{
			last_node = last_node->next;
		}


		//Reconstruct de List
		if (first_node->prev != NULL)
		{

			if (last_node->next != NULL)
			{
				first_node->prev->next = last_node->next;
				last_node->next->prev = first_node->prev;
			}
			else
			{
				first_node->prev->next = last_node->next;
				end = first_node->prev;
			}
		}
		else
		{
			if (last_node->next)
			{
				last_node->next->prev = NULL;
				start = last_node->next;
			}
			else
			{
				start = end = NULL;
			}
		}

		//Delete Nodes
		DList_Node<TYPE>* tmp ;
		while (first_node != last_node)
		{
		    tmp = first_node->next;
			delete first_node;
			first_node = tmp;
			ret++;
		}

		delete last_node;
		ret++;
		size -= ret;

		return true;
	}

	void Clear()
	{
		DList_Node<TYPE>* tmp;
		DList_Node<TYPE>* tmp2 = start;

		while (!tmp2)
		{
			tmp = tmp2->next;
			delete tmp2;
			tmp2 = tmp;
		}
		start = end = NULL;
		size = 0;
	}
	
	TYPE& operator  [](const unsigned int index)
	{
		long                  pos;
		DList_Node<TYPE>*   p_item;
		pos = 0;
		p_item = start;

		while (p_item != NULL)
		{
			if (pos == index)
			{
				break;
			}

			++pos;
			p_item = p_item->next;
		}

		//ASSERT(p_item);
		return(p_item->data);
	}

	const TYPE& operator  [](const unsigned int index)const
	{
		long                  pos;
		DList_Node<TYPE>*   p_item;
		pos = 0;
		p_item = start;

		while (p_item != NULL)
		{
			if (pos == index)
			{
				break;
			}

			++pos;
			p_item = p_item->next;
		}

		//ASSERT(p_item);
		return(p_item->data);
	}



	//+=
	//Coses per fer: Inserir Llista enllaçada al mig d'una llista
	/*const DLinkList& operator +=(const DLinkList& list)//El const del principi es que tornem la llista perque la puguis llegir però no canviar
	{
		DList_Node<TYPE>* tmp;
		tmp = list.start;

		while (tmp != NULL)
		{
		   add(tmp->data);
		   tmp = tmp->next;
		}

		return(*this);// asterisc this perque tornem una referencia
		//retornem nomes this si retornem un punter
	}*/

	void Swap(TYPE& a, TYPE& b)
	{
		DList_Node<TYPE>* tmp = new DList_Node<TYPE>(a);
		//tmp->data = a;
		a = b;
		b = tmp->data;
	}
	
	const DLinkList& operator +=(DLinkList& list)//El const del principi es que tornem la llista perque la puguis llegir però no canviar
	{
		DList_Node<TYPE>* tmp;
		tmp = list.start;
		DList_Node<TYPE>* tmp2;
		tmp2 = start;
		unsigned int pos = 0;
		unsigned int middle = Count() / 2;
		unsigned int num_nodes = Count();
		unsigned int num_nodes2 = list.Count();
		unsigned int num_swap = 0;

		while (tmp != NULL)
		{
			add(tmp->data);
			tmp = tmp->next;
		}

		while (tmp2 != NULL)
		{
			if (pos >= middle)
			{
				while (num_swap != num_nodes2)
				{
					Swap(tmp2->data, tmp2->next->data);
					tmp2 = tmp2->next;
					num_swap++;
				}

				end = tmp2;
			}
			
			pos++;
			tmp2 = tmp2->next;
		}



		return(*this);// asterisc this perque tornem una referencia
		//retornem nomes this si retornem un punter
	}


	

	int BubbleSort()
	{
		int ret = 0;
		bool swapped = true;

		while (swapped)
		{
			swapped = false;
			DList_Node<TYPE>* tmp = start;
			while (tmp != NULL && tmp->next != NULL)
			{
				++ret;
				if (tmp->data > tmp->next->data)
				{
					Swap(tmp->data, tmp->next->data);
					swapped = true;
				}

				tmp = tmp->next;
			}
		}
		return ret;
	}

	void Revert()
	{
		DList_Node<TYPE>* tmp = start;
		DList_Node<TYPE>* tmp2 = end;

		unsigned int num_swaps = Count() / 2;

		while (num_swaps != 0)
		{
			Swap(tmp->data, tmp2->data);
			tmp = tmp->next;
			tmp2 = tmp2->prev;
			num_swaps--;
		}

	}
	
	TYPE& Get_data_node(const int N) const
	{
		DList_Node<TYPE>* tmp = start;
		for (int p = 0; p < N; p++)
		{
			if (tmp == NULL)
			{

				return tmp->data;
				break;
			}
			tmp = tmp->next;
		}
		return tmp->data;
	}


	DList_Node<TYPE>* Get_node(const int N) const
	{
		DList_Node<TYPE>* tmp = start;
		for (int p = 0; p < N; p++)
		{
			if (tmp == NULL)
			{

				return 0;
				break;
			}
			tmp = tmp->next;
		}
		return tmp;
	}

	int find(const TYPE& data)const
	{
		DList_Node<TYPE>* tmp = start;
		int index = 0;

		while (tmp != NULL)
		{
			if (tmp->data == data)
				return(index);

			++index;
			tmp = tmp->next;
		}
		return (NULL);
	}

	DList_Node<TYPE>* Get_First()
	{
		return start;
	}

	unsigned int Count()const
	{
		return size;
	}

};


#endif