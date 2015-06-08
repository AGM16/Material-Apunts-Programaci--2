#ifndef _TREE_
#define _TREE_

#include "Double_List.h"
#include "Stack.h"

template <class TYPE>
class TreeNode
{

public:
	TreeNode(){ data = NULL; parent = NULL; }
	TreeNode(TYPE _data){ data = _data; parent = NULL; }

	TreeNode<TYPE>* parent;
	DLinkList<TreeNode<TYPE>*> branches;
	TYPE data;

	void VisitPostOrder_Rec(DLinkList <TYPE>* list) const
	{
		int nNodes = branches.Count();
		for (int n = 0; n < nNodes; n++)
		{
			branches.Get_node(n)->data->VisitPostOrder_Rec(list);
		}
		list->add(data);
	}

	void VisitPreOrder_Rec(DLinkList <TYPE>* list) const
	{
		list->add(data);
		int nNodes = branches.Count();
		for (int n = 0; n < nNodes; n++)
		{
			branches.Get_node(n)->data->VisitPreOrder_Rec(list);
		}
	}

	void VisitInOrder_Rec(DLinkList <TYPE>* list) const
	{
		int nNodes = branches.Count();
		int n = 0;

		for (; n < nNodes / 2; n++)
		{
			branches.Get_node(n)->data->VisitInOrder_Rec(list);
		}

		list->add(data);

		for (; n < nNodes; n++)
		{
			branches.Get_node(n)->data->VisitInOrder_Rec(list);
		}
	}

};

template <class TYPE>
class cTree
{

	TreeNode<TYPE>* rootNode;

public:

	//Constructor
	cTree() { rootNode = NULL; }


	//Destructor
	~cTree() 
	{
		//Clear(); 
	}


	//Getters
	const TreeNode<TYPE>* GetRoot() const { return rootNode; }


	//Visit
	void VisitPreOrder_Rec(DLinkList <TYPE>* list) const { rootNode->VisitPreOrder_Rec(list); }
	void VisitPostOrder_Rec(DLinkList <TYPE>* list) const { rootNode->VisitPostOrder_Rec(list); }
	void VisitInOrder_Rec(DLinkList <TYPE>* list) const { rootNode->VisitInOrder_Rec(list); }

	void VisitPreOrder(DLinkList <TYPE>* list) const
	{
		Stack<TreeNode<TYPE>*> Stack;
		TreeNode<TYPE>* node = rootNode;
		//TYPE node_del_data = NULL;
		while (node != NULL )
		{
			list->add(node->data);
			for (int n = node->branches.Count()- 1; n >= 0; n--)
			{
				Stack.Push(node->branches.Get_node(n)->data);
			}
			node = Stack.Pop();
		}
	}

	void VisitPostOrderIterative(DLinkList<TYPE>* list)
	{
		Stack<TreeNode<TYPE>*> stack;
		Stack<TreeNode<TYPE>*> stack_end;
		TreeNode<TYPE>* node = rootNode;

		while (node != NULL)
		{
			stack_end.Push(node);
			for (unsigned int a = 0; a < node->branches.Count(); a++)
			{
				stack.Push(node->branches.Get_node(a)->data);
			}
			node = stack.Pop();
		}
		while (true)
		{
			node = stack_end.Pop();
			if (node == NULL){ break; }
			list->add(node->data);
		}

	}
	void VisitInOrder(DLinkList <TYPE>* list) const
	{
		Stack<TreeNode<TYPE>*> stack;
		Stack<TreeNode<TYPE>*> stack2;
		TreeNode<TYPE>* node = rootNode;
		while (node != NULL)
		{
			int m = node->branches.Count();
			for (int n = m / 2; m > n; m--)
			{
				stack.Push(node->branches.Get_node(m - 1)->data);
			}
			stack.Push(node);
			stack2.Push(node);
			for (; m > 0; m--)
			{
				stack.Push(node->branches.Get_node(m - 1)->data);
			}
			while (stack.PeekLast() == stack2.PeekLast() && stack.PeekLast() != NULL)
			{
				node = stack.Pop();
				list->add(stack2.Pop()->data);
			}
			node = stack.Pop();

		}
	}


	//Add
	TreeNode<TYPE>* Add(const TYPE& data, TreeNode<TYPE>* parent = NULL)
	{
		if (parent == NULL && rootNode != NULL)
		{
			return NULL;
		}
		TreeNode<TYPE>* newNode = new TreeNode<TYPE>(data);
		if (rootNode == NULL)
		{
			newNode->parent = NULL;
			rootNode = newNode;
		}
		else if (parent != NULL)
		{
			parent->branches.add(newNode);
			newNode->parent = parent;
		}
		return newNode;
	}


	//Clear
	void Clear(TreeNode<TYPE>* nodeToErase = NULL)
	{
		if (nodeToErase == NULL && rootNode != NULL)
		{
			nodeToErase = rootNode;
		}
		if (nodeToErase != NULL)
		{
			if (nodeToErase->branches.Get_First() != NULL)
			{
				int nNodes = nodeToErase->branches.Count();
				for (int n = 0; n < nNodes; n++)
				{
					Clear(nodeToErase->branches.Get_node(n)->data);
				}
			}
			delete nodeToErase;
		}
		if (nodeToErase == rootNode)
		{
			rootNode = NULL;
		}
	}

	

};
#endif