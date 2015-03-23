#ifndef DOUBLE_CLASS_LIST 
#define DOUBLE_CLASS_LIST


#include<stdio.h>


//----------------------------------

//NODE STRUCT

//----------------------------------

template <class T1>
struct Node
{
	T1 data;
	Node <T1>* next;
	Node <T1>* prev;

};


//---------------------------------

//CLASS LIST

//---------------------------------
template <class T1> 
class DoubleClassList
{
public:

	Node <T1>* Start;
	Node <T1>* End;

private:

	unsigned int in_size;

public:

	//Constructor
	DoubleClassList(){
		Start = End = NULL;
		in_size = 0;
	}

	//Destructor
	~DoubleClassList(){}


	//Methods
	void AddDoubleNode(const T1& _data)
	{
		Node <T1>* new_node = new Node <T1>;
		new_node->data = _data;
		new_node->next = NULL;
		new_node->prev = NULL;

		Node<T1>* tmp = Start;
		if (Start == NULL)
		{
			Start = End = new_node;
		}
		else
		{ 

			new_node->prev = End;
			End->next = new_node;
			End = new_node;

		}

		in_size++;
	}


	
	void DeleDoubleNode(Node<T1>* del_node)
	{

		
		if (del_node->prev != NULL)
		{
			
			if (del_node->next != NULL)
			{
				del_node->next->prev = del_node->prev;
				del_node->prev->next = del_node->next;
				delete (del_node);
			}

		
			else
			{
				End = del_node->prev;
				delete (del_node);
			}

		}

		
		else
		{
			if (del_node->next != NULL)
			{
				del_node->next->prev = NULL;
				Start = del_node->next;
				delete(del_node);
			}
			else
			{
				Start = End = NULL;
			}

		}

		in_size--;

	}



	
	void DeleAll()
	{
		if (Start != NULL)
		{
			Node<T1>* tmp = Start;
			while (tmp->next != NULL)
			{
				Node<T1>* tmp2 = tmp;
				tmp = tmp->next;
				delete(tmp2);
			}
			Start = End = NULL;
			in_size = 0;
		}
	}

	
	T1& operator [](const unsigned int num_position)const
	{
		
		long pos = 0;

		Node<T1>* tmp = Start;
		while (tmp != NULL)
		{
			if (pos == num_position)
			{
				break;
			}

			pos++;
			tmp = tmp->next;
		}

		return (tmp->data);

	}

	unsigned int DoubleCount()
	{
		return in_size;
	}

};


#endif