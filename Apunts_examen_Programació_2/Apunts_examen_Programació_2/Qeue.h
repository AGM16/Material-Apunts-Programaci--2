#ifndef _QEUE_
#define _QEUE_

#define NULL 0
#include <assert.h>

template<class VALUE>
struct Qeue_Node
{
	VALUE data;
	Qeue_Node<VALUE>* next;

	//Copy Constructor
	Qeue_Node(){ next = NULL; }
	Qeue_Node( VALUE _data){ data = _data; next = NULL;}

};

template<class VALUE>
class Qeue
{
public:

	Qeue_Node<VALUE>* start;

private:
     
	unsigned int size;

public:

	//Default Constructor
	Qeue(){ start = NULL; size = 0; }

	//Destructor
	~Qeue()
	{
		Clear();
	}

	//METHODS
	//------------------------
	VALUE& Get_data_nodes(unsigned int index)const
	{
		if (start == NULL)
		{
			return start->data;
		}
		
		Qeue_Node<VALUE>* tmp = start;
		unsigned int pos = 0;
		
		while (tmp != NULL && pos < index)
		{
			tmp = tmp->next;
			pos++;
		}

		return tmp->data;
	}

	Qeue_Node<VALUE>* GetLast()const 
	{
		//VALUE* _return = NULL;
		if (start == NULL)
		{
			return start;
		}
		Qeue_Node<VALUE>* tmp = start;

		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		 
		return tmp;
	}

	void Push_Qeue(const VALUE& _data)
	{
		Qeue_Node<VALUE>* p_data_item;
		p_data_item = new Qeue_Node<VALUE>(_data);

		Qeue_Node<VALUE>* last = GetLast();

		if (last == NULL)
		{
			start = p_data_item;
		}
		else
		{
			last->next = p_data_item;
		}
		size++;


			
	}


	bool Del_Qeue_Start(VALUE& _result)
	{
		if (Count() == NULL)
		{
			return false;
		}
		
		Qeue_Node<VALUE>* tmp = new Qeue_Node < VALUE > ;
	    tmp = start;
		
		_result = start->data;
		start = start->next;
		delete tmp;
		
		size--;
		
		return true;
	}

	/*bool Pop_Qeue(VALUE& item)
	{
		if (Count() == NULL)
		{
			return false;
		}
	    

		Qeue_Node<VALUE>* last = GetLast();

			Qeue_Node<VALUE>* tmp = start;

			while (tmp->next != last)
				tmp = tmp->next;

			item = tmp->next->data;
			delete(tmp->next);

		
		size--;
		return true;
	}*/

	const VALUE* PEEK_Q(unsigned int index)const
	{
		VALUE* ret = NULL;
		unsigned int i = 0;
		Qeue_Node<VALUE>* tmp;

		for (tmp = start; tmp != NULL && i < index; tmp = tmp->next)
			++i;

		if (tmp != NULL)
		{
			ret = &(tmp->data);
			return ret;
		}
		else
		{
			return NULL;
		}

	}

	void Clear()
	{
		Qeue_Node<VALUE>* tmp = start;
		Qeue_Node<VALUE>* tmp2;

		while (tmp != NULL)
		{
			tmp2 = tmp->next;
			delete tmp;
			tmp = tmp2;
			size--;
		}

		start = NULL;
	}
   
	unsigned int Count()const
	{
		return size;
	}

};


#endif