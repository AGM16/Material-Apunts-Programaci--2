#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Apunts_examen_Programació_2/Point.h"
#include "../Apunts_examen_Programació_2/String_Class.h"
#include "../Apunts_examen_Programació_2/Double_List.h"
#include "../Apunts_examen_Programació_2/Dynamic_Array.h"
#include "../Apunts_examen_Programació_2/Projectile.h"
#include "../Apunts_examen_Programació_2/Others_Functions.h"
#include "../Apunts_examen_Programació_2/Stack.h"
#include "../Apunts_examen_Programació_2/Stack_2.h"
#include "../Apunts_examen_Programació_2/Qeue.h"
#include "../Apunts_examen_Programació_2/Qeue_2.h"
#include "../Apunts_examen_Programació_2/Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		//--------------------------------------
		//POINT
		//--------------------------------------

		TEST_METHOD(Constructor_empty)
		{
			Point<int> a;
			Assert::AreEqual(a.get_x(), 0);
			Assert::AreEqual(a.get_y(), 0);
		}

		TEST_METHOD(Constructor_copy)
		{
			Point<int> a(1, 2);
			Assert::AreEqual(a.get_x(), 1);
			Assert::AreEqual(a.get_y(), 2);
		}

		TEST_METHOD(Operator_plus)
		{
			Point<int> a;
			a.x = 1;
			a.y = 2;
			Point<int> b;
			b.x = 4;
			b.y = 5;
			Point<int> Result;
			Result = a + b;
			Assert::AreEqual(Result.get_x(), 5);
			Assert::AreEqual(Result.get_y(), 7);
		}

		TEST_METHOD(Operator_Remove)
		{
			Point<int> a;
			a.x = 1;
			a.y = 2;
			Point<int> b;
			b.x = 4;
			b.y = 5;
			Point<int> Result;
			Result = a - b;
			Assert::AreEqual(Result.get_x(), -3);
			Assert::AreEqual(Result.get_y(), -3);
		}

		TEST_METHOD(Operator_Plus_equal)
		{
			Point<int> a;
			a.x = 1;
			a.y = 2;
			Point<int> b;
			b.x = 4;
			b.y = 5;

			a += b;
			Assert::AreEqual(a.get_x(), 5);
			Assert::AreEqual(a.get_y(), 7);
		}


		TEST_METHOD(Operator_Remove_equal)
		{
			Point<int> a;
			a.x = 1;
			a.y = 2;
			Point<int> b;
			b.x = 4;
			b.y = 5;

			a -= b;
			Assert::AreEqual(a.get_x(), -3);
			Assert::AreEqual(a.get_y(), -3);
		}

		TEST_METHOD(Operator_equal)
		{
			Point<int> a(1, 5);
			Point<int> b(1, 5);

			Assert::IsTrue(a.x == b.x);
			Assert::IsTrue(a.y == b.y);

			Point<int> c(8, 7);

			Assert::IsFalse(a.x == c.x);
			Assert::IsFalse(a.y == c.y);
		}

		TEST_METHOD(Operator_not_equal)
		{
			Point<int> a(1, 2);
			Point<int> b(6, 4);

			Assert::IsTrue(a.x != b.x);
			Assert::IsTrue(a.y != b.y);

			Point<int> c(1, 2);

			Assert::IsFalse(a.x != c.x);
			Assert::IsFalse(a.y != c.y);
		}


		//Look how is done the method assignation
		TEST_METHOD(Operator_Assignation)
		{
			Point<int> a;
			a.x = 1;
			a.y = 5;

			Assert::AreEqual(a.get_x(), 1);
			Assert::AreEqual(a.get_y(), 5);

		}


		TEST_METHOD(Operator_IsZero)
		{
			Point<int> a;
			a.x = 1;
			a.y = 5;

			Assert::IsFalse(a.IsZero());

			a.x = 0;
			a.y = 0;

			Assert::IsTrue(a.IsZero());
		}

		TEST_METHOD(Operator_SetZero)
		{
			Point<int> a;
			a.x = 1;
			a.y = 5;

			a.SetZero();

			Assert::IsTrue(a.IsZero());
		}

		TEST_METHOD(Operator_Swap)
		{
			Point<int> a(1, 5);
			Point<int> b(2, 3);

			a.Swap(b);

			Assert::AreEqual(a.get_x(), 2);
			Assert::AreEqual(a.get_y(), 3);
			Assert::AreEqual(b.get_x(), 1);
			Assert::AreEqual(b.get_y(), 5);
		}

		TEST_METHOD(Operator_Negate)
		{
			Point<int> a(1, 5);

			a.Negate();

			Assert::AreEqual(a.get_x(), -1);
			Assert::AreEqual(a.get_y(), -5);
		}

		TEST_METHOD(Distance_to)
		{

			Point<int> p1, p2;
			p2.x = 3;
			p2.y = -4;

			Assert::IsTrue(p1.distanceTo(p2) == 5.f);
		}


		//--------------------------------------
		//StringClass
		//--------------------------------------

		TEST_METHOD(String_Default_Constructor)
		{
			String_Class a;
			unsigned int b = 0;
			unsigned int c = 1;
			Assert::AreEqual(a.Length(), b);
			Assert::AreEqual(a.GetCapacity(), c);
			
		}

		TEST_METHOD(String_Copy_Char_Constructor)
		{
			String_Class a("hola");
			unsigned int b = 4;
			unsigned int c = 5;
			Assert::AreEqual(a.Length(), b);
			Assert::AreEqual(a.GetCapacity(), c);

		}

		TEST_METHOD(String_Copy_String_Class_Constructor)
		{
			String_Class a("hola");
			String_Class d(a);
			unsigned int b = 4;
			unsigned int c = 5;
			Assert::AreEqual(d.Length(), b);
			Assert::AreEqual(d.GetCapacity(), c);
		}

		//Operators
		TEST_METHOD(String_Operator_Equal_char)
		{
			String_Class a("hola");
			char* p = "hola";
			unsigned int b = 4;
			unsigned int c = 5;
			Assert::IsTrue(a == p);
		}
		
		TEST_METHOD(String_Operator_Equal_String)
		{
			String_Class a("hola");
			String_Class d(a);
			unsigned int b = 4;
			unsigned int c = 5;
			Assert::IsTrue(a == d);
		}

		TEST_METHOD(String_Operator_NotEqual_char)
		{
			String_Class a("hola");
			char* p = "hello";
			unsigned int b = 4;
			unsigned int c = 5;
			Assert::IsTrue(a != p);
		}
		
		TEST_METHOD(String_Operator_NotEqual_String)
		{
			String_Class a("hola");
			String_Class d("hello");
			unsigned int b = 4;
			unsigned int c = 5;
			Assert::IsTrue(a != d);
		}


		TEST_METHOD(String_Operator_Assignation_char)
		{
			String_Class a("hola");
			char* p = "hello_world";
			a = p;
			Assert::IsTrue(a == p);
		}

		TEST_METHOD(String_Operator_Assignation_String)
		{
			String_Class a("hola");
			String_Class p ("hello_world");
			a = p;
			Assert::IsTrue(a == p);
			unsigned int c = 12;
			Assert::AreEqual(a.GetCapacity(), c);
		}

		TEST_METHOD(String_Operator_Plus_Equal_char)
		{
			String_Class a("hello ");
			char* p = "world";
			a += p;
			Assert::IsTrue(a == "hello world");
			unsigned int c = 12;
			Assert::AreEqual(a.GetCapacity(), c);
		}

		TEST_METHOD(String_Operator_Plus_Equal_String)
		{
			String_Class a("hello ");
			String_Class b("world");
			a += b;
			Assert::IsTrue(a == "hello world");
			unsigned int c = 12;
			Assert::AreEqual(a.GetCapacity(), c);
		}

		//METHOD PREFIX

		TEST_METHOD(String_Prefix_char)
		{
			String_Class a("hello ");
			a.Prefix("world");
			unsigned int c = 12;
			unsigned int d = 11;
			Assert::AreEqual(a.Length(), d);
			Assert::AreEqual(a.GetCapacity(), c);
			Assert::AreEqual(strcmp(a.GetString(), "worldhello "), 0);
		}

		TEST_METHOD(String_Prefix_String)
		{
			String_Class a("hello ");
			String_Class b("world");
			a.Prefix(b);
			String_Class ("worldhello ");
			unsigned int c = 12;
			unsigned int d = 11;
			Assert::AreEqual(a.Length(), d);
			Assert::AreEqual(a.GetCapacity(), c);
			Assert::AreEqual(strcmp(a.GetString(), "worldhello "), 0);

			
		}

		TEST_METHOD(String_C_SWAP)
		{
			char* a ="hello";
			char* b = "hola";
			Swap(a, b);
			Assert::IsTrue(a == "hola");
			Assert::IsTrue(b == "hello");

		}
		
		//Method SWAP
		TEST_METHOD(String_SWAP)
		{
			String_Class a("hello");
			String_Class b("hola");
			a.SWAP(b);
			Assert::AreEqual(a.GetString(), "hola");
			Assert::AreEqual(b.GetString(), "hello");

		}

		//METHOD TRIM
		TEST_METHOD(String_TRIM)
		{
			String_Class a("   hello   ");
			unsigned int c = 12;
			unsigned int d = 11;
			Assert::AreEqual(a.Length(), d);
			Assert::AreEqual(a.GetCapacity(), c);
			a.Trim();
			d = 5;
			Assert::AreEqual(a.Length(), d);
		}

		//Find
		TEST_METHOD(String_Find)
		{
			String_Class a("hello world hello world world");

			Assert::AreEqual((int)a.Find("world"), 3);
			
		}


		TEST_METHOD(String_Clear)
		{
			String_Class a("hello ");
			a.Clear();
			Assert::IsTrue(a == "");
			unsigned int c = 7;
			unsigned int d = 0;
			Assert::AreEqual(a.Length(), d);
			Assert::AreEqual(a.GetCapacity(), c);
		}


		//--------------------------------------
		//DoubleLinkList
		//--------------------------------------
		TEST_METHOD(DList_Default_Constructor)
		{
			DLinkList<int> a;
			unsigned int b = 0;
			Assert::AreEqual(a.Count(), b);
		}

		TEST_METHOD(DList_Add)
		{
			DLinkList<int> a;
			a.add(1);
			unsigned int b = 1;
			Assert::AreEqual(a.Count(), b);
		}

		TEST_METHOD(DList_Delete_node)
		{
			DLinkList<int> a;
			a.add(1);
			a.add(2);
			a.add(3);
			a.add(4);
			Assert::IsTrue(a.del(a.Get_node(2)));
			Assert::AreEqual((int)a.Count(), 3);
		}

		TEST_METHOD(DLinkList_Clear)
		{
			DLinkList<int> a;
			a.add(1);
			a.add(2);
			a.Clear();
			Assert::AreEqual((int)a.Count(), 0);
		}

		//Add on the end and on the middle
		TEST_METHOD(DLinkList_plus_equal)
		{
			DLinkList<int> a;
			a.add(1);
			a.add(2);
			DLinkList<int> b;
			b.add(3);
			b.add(4);
			b.add(5);
			a += b;
			Assert::AreEqual((int)a.Count(), 5);
			Assert::AreEqual((int)a.Get_data_node(0), 1);
			Assert::AreEqual((int)a.Get_data_node(1), 3);
			Assert::AreEqual((int)a.Get_data_node(2), 4);
			Assert::AreEqual((int)a.Get_data_node(3), 5);
			Assert::AreEqual((int)a.Get_data_node(4), 2);
			a.Clear();
			Assert::AreEqual((int)a.Count(), 0);
		}

		TEST_METHOD(DLinkList_BubbleSort)
		{
			DLinkList<int> a;
			a.add(5);
			a.add(4);
			a.add(3);
			a.add(2);
			a.add(1);

			a.BubbleSort();

			Assert::AreEqual((int)a.Count(), 5);
			Assert::AreEqual((int)a.Get_data_node(0), 1);
			Assert::AreEqual((int)a.Get_data_node(1), 2);
			Assert::AreEqual((int)a.Get_data_node(2), 3);
			Assert::AreEqual((int)a.Get_data_node(3), 4);
			Assert::AreEqual((int)a.Get_data_node(4), 5);
			a.Clear();
			Assert::AreEqual((int)a.Count(), 0);
		}

		TEST_METHOD(DLinkList_Revert)
		{
			DLinkList<int> a;
			a.add(1);
			a.add(2);
			a.add(3);
			a.add(4);
			a.add(5);

			a.Revert();

			Assert::AreEqual((int)a.Count(), 5);
			Assert::AreEqual((int)a.Get_data_node(0), 5);
			Assert::AreEqual((int)a.Get_data_node(1), 4);
			Assert::AreEqual((int)a.Get_data_node(2), 3);
			Assert::AreEqual((int)a.Get_data_node(3), 2);
			Assert::AreEqual((int)a.Get_data_node(4), 1);
			a.Clear();
			Assert::AreEqual((int)a.Count(), 0);
		}



		//--------------------------------------
		//Dynamic Array
		//--------------------------------------

		TEST_METHOD(DArray_Default_Constructor)
		{
			DynArray<int> a;
			Assert::AreEqual((int)a.Count(), 0);
			Assert::AreEqual((int)a.Capacity(), 140);
		}


		TEST_METHOD(DArray_Copy_Constructor)
		{
			DynArray<int> a(20);
			Assert::AreEqual((int)a.Count(), 0);
			Assert::AreEqual((int)a.Capacity(), 20);
		}

		TEST_METHOD(DArray_Pushback)
		{
			DynArray<int> a(20);
			a.Pushback(1);
			a.Pushback(2);
			a.Pushback(3);
			Assert::AreEqual((int)a.Count(), 3);
			Assert::AreEqual((int)a.Capacity(), 20);
			int b = 0;
			a.Pop(b);
			Assert::AreEqual((int)a.Count(), 2);
			Assert::AreEqual(a[0], 1);
			Assert::AreEqual(a[1], 2);
			a.Pop(b);
			Assert::AreEqual((int)a.Count(), 1);
			Assert::AreEqual(a[0], 1);
		}
		
		TEST_METHOD(DArray_POP)
		{
			DynArray<int> a(20);
			a.Pushback(1);
			a.Pushback(2);
			a.Pushback(3);
			Assert::AreEqual((int)a.Count(), 3);
			Assert::AreEqual((int)a.Capacity(), 20);
			int b = 0;
			a.Pop(b);
			Assert::AreEqual((int)a.Count(), 2);
			Assert::AreEqual(a[0], 1);
			Assert::AreEqual(a[1], 2);
		}

		TEST_METHOD(DArray_Insert)
		{
			DynArray<char> a(20);
			a.Pushback('h');
			a.Pushback('o');
			a.Pushback('l');
			a.Pushback('a');
			unsigned int b = 4;
			Assert::AreEqual(a.Count(), b);
			Assert::AreEqual((int)a.Capacity(), 20);
			char h = 'j';
			a.Insert(h, 1);
			b = 5;
			Assert::AreEqual(a.Count(), b);
			Assert::AreEqual(a[0], 'h');
			Assert::AreEqual(a[1], 'j');
			Assert::AreEqual(a[2], 'o');
			Assert::AreEqual(a[3], 'l');
			Assert::AreEqual(a[4], 'a');
			
		}

		TEST_METHOD(DArray_Insert_middle)
		{
			DynArray<char> a(20);
			a.Pushback('1');
			a.Pushback('2');
			a.Pushback('3');
			a.Pushback('4');

			DynArray<char> b(20);
			b.Pushback('h');
			b.Pushback('o');
			b.Pushback('l');
			b.Pushback('a');
			
			b.Insert_middle(a);

			unsigned int c = 8;
			Assert::AreEqual(b.Count(), c);
			Assert::AreEqual((int)a.Capacity(), 20);
			Assert::AreEqual(b[0], 'h');
			Assert::AreEqual(b[1], 'o');
			Assert::AreEqual(b[2], '1');
			Assert::AreEqual(b[3], '2');
			Assert::AreEqual(b[4], '3');
			Assert::AreEqual(b[5], '4');
			Assert::AreEqual(b[6], 'l');
			Assert::AreEqual(b[7], 'a');
		}

		TEST_METHOD(DArray_Flip)
		{
			DynArray<int> a(20);
			a.Pushback(1);
			a.Pushback(2);
			a.Pushback(3);
			a.Pushback(4);

			a.Flip();

			Assert::AreEqual((int)a.Count(), 4);
			Assert::AreEqual(a[0], 4);
			Assert::AreEqual(a[1], 3);
			Assert::AreEqual(a[2], 2);
			Assert::AreEqual(a[3], 1);
		}

		TEST_METHOD(DArray_Buble_sort)
		{
			DynArray<int> a(20);
			a.Pushback(4);
			a.Pushback(2);
			a.Pushback(1);
			a.Pushback(3);

			a.BubleSort();

			Assert::AreEqual((int)a.Count(), 4);
			Assert::AreEqual(a[0], 1);
			Assert::AreEqual(a[1], 2);
			Assert::AreEqual(a[2], 3);
			Assert::AreEqual(a[3], 4);
		}

		TEST_METHOD(DArray_At)
		{
			DynArray<int> a(20);
			a.Pushback(4);
			a.Pushback(2);
			a.Pushback(1);
			a.Pushback(3);

			Assert::AreEqual((int)a.Count(), 4);
			Assert::AreEqual(*(a.At(0)), 4);
			Assert::AreEqual(*(a.At(1)), 2);
			Assert::AreEqual(*(a.At(2)), 1);
			Assert::AreEqual(*(a.At(3)), 3);
		}

		TEST_METHOD(DArray_Find)
		{
			DynArray<int> a(20);
			a.Pushback(4);
			a.Pushback(2);
			a.Pushback(1);
			a.Pushback(3);
			DynArray<int> b;
			b.Pushback(4);
			
			Assert::AreEqual((int)a.Find(b), 1);
		}

		TEST_METHOD(DArray_Pop_data)
		{
			DynArray<int> a(20);
			a.Pushback('h');
			a.Pushback('o');
			a.Pushback('l');
			a.Pushback('a');
			
			Assert::AreEqual((int)a.Count(), 4);
			int b = 0;
			a.Pop_data(1);
			Assert::AreEqual((int)a.Count(), 3);
			Assert::AreEqual((char)a[0], 'h');
			Assert::AreEqual((char)a[1], 'l');
			Assert::AreEqual((char)a[2], 'a');
		}
		TEST_METHOD(DArray_Pop_spaces_Fisrt)
		{
			DynArray<int> a(20);
			a.Pushback(' ');
			a.Pushback(' ');
			a.Pushback('h');
			a.Pushback('o');
			a.Pushback('l');
			a.Pushback('a');

			a.del_Space();

            Assert::AreEqual((int)a.Count(), 4);
            Assert::AreEqual((char)a[0], 'h');
			Assert::AreEqual((char)a[1], 'o');
			Assert::AreEqual((char)a[2], 'l');
			Assert::AreEqual((char)a[3], 'a');
		}

		TEST_METHOD(DArray_Pop_spaces_Last)
		{
			DynArray<int> a(20);
			
			a.Pushback('h');
			a.Pushback('o');
			a.Pushback('l');
			a.Pushback('a');
            a.Pushback(' ');
			a.Pushback(' ');

			a.del_Space();

			Assert::AreEqual((int)a.Count(), 4);
			Assert::AreEqual((char)a[0], 'h');
			Assert::AreEqual((char)a[1], 'o');
			Assert::AreEqual((char)a[2], 'l');
			Assert::AreEqual((char)a[3], 'a');
		}

		TEST_METHOD(DArray_Pop_spaces_First_and_last)
		{
			DynArray<int> a(20);
			a.Pushback(' ');
			a.Pushback(' ');
			a.Pushback('h');
			a.Pushback('o');
			a.Pushback('l');
			a.Pushback('a');
			a.Pushback(' ');
			a.Pushback(' ');

			a.del_Space();

			Assert::AreEqual((int)a.Count(), 4);
			Assert::AreEqual((char)a[0], 'h');
			Assert::AreEqual((char)a[1], 'o');
			Assert::AreEqual((char)a[2], 'l');
			Assert::AreEqual((char)a[3], 'a');
		}





		//--------------------------------------
		
		//PARCIAL EXAM

		//--------------------------------------

		//EXERCICE 1: PROJECTILE

		TEST_METHOD(Projectile_test)
		{
			Projectile p;

			p.point.x = 10.0f;
			p.point.y = 10.0f;

			p.speed.x = 2.0f;
			p.speed.y = 0.0f;

			Point<float> current = p.GetCurrentPoisition(3.0f);

			Assert::AreEqual((float)16.0f, current.x, 0.00001f);
			Assert::AreEqual((float)10.0f, current.y, 0.00001f);
		}

		//EXERCICE 2: DYNARRAY

		TEST_METHOD(ArrDyn_optimizeMem)
		{
			DynArray<int> array(10);

			array.Pushback(1);
			array.Pushback(2);
			array.Pushback(3);

			Assert::AreEqual((unsigned int)10, array.Capacity());

			unsigned int wasted = array.removeWastedMemory();

			Assert::AreEqual((unsigned int)3, array.Capacity());
			Assert::AreEqual((unsigned int)7, wasted);
			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
		}

		//EXERCICE 3: DLink_List

		TEST_METHOD(DLinkList_delNodes_mid)
		{
			DLinkList<int> l;

			l.add(1);
			l.add(2);
			l.add(3);
			l.add(4);

			Assert::IsTrue(l.delNodes(1,3));

			Assert::AreEqual(l.start->data, (int)1);
			Assert::AreEqual(l.end->data,(int)1);
			Assert::AreEqual((unsigned int)1, l.Count());
		}


		//--------------------------------------

		//STACK

		//--------------------------------------
		TEST_METHOD(Stack_1_test_methods)
		{
			Stack<int> lifo;

			lifo.Push(10);
			lifo.Push(20);
			lifo.Push(30);
			lifo.Push(40);

			Assert::AreEqual((int)lifo.Count(), 4);
			Assert::AreEqual((int)*(lifo.PEEK(1)), 20);

			
		

			Assert::AreEqual((int)lifo.Pop(), 40);
			Assert::AreEqual((int)lifo.Count(), 3);
		}


		TEST_METHOD(Stack_2_test_methods)
		{
			Stack_2<int> lifo;

			lifo.Push_s2(10);
			lifo.Push_s2(20);
			lifo.Push_s2(30);
			lifo.Push_s2(40);

			Assert::AreEqual((int)lifo.Count(), 4);
			Assert::AreEqual((int)*(lifo.PEEK_s2(1)), 20);

			int result;
			bool r = lifo.Pop_s2(result);

			Assert::AreEqual((int)result, 40);
			Assert::AreEqual((int)lifo.Count(), 3);
		}

		//--------------------------------------

		//QEUE

		//--------------------------------------

		TEST_METHOD(Qeue1_Methods_test)
		{
			Qeue<int> fifo;


			fifo.Push_Qeue(11);
			fifo.Push_Qeue(22);
			fifo.Push_Qeue(33);

			Assert::AreEqual((int)fifo.Count(), 3);
			Assert::AreEqual((int)fifo.Get_data_nodes(2), 33);
			Assert::AreEqual((int)*(fifo.PEEK_Q(2)), 33);

			int result = 0;
			Assert::IsTrue(fifo.Del_Qeue_Start(result));
			
			Assert::AreEqual((int)fifo.Get_data_nodes(0), 22);
			Assert::AreEqual((int)fifo.start->data, 22);
			Assert::AreEqual((int)fifo.Count(), 2);

			fifo.Clear();
			Assert::AreEqual((int)fifo.Count(), 0);

			
		}

		TEST_METHOD(Qeue2_Methods_test)
		{
			Qeue_2<int> fifo;


			fifo.Push_Q2(11);
			fifo.Push_Q2(22);
			fifo.Push_Q2(33);

			Assert::AreEqual((int)fifo.Count(), 3);
			Assert::AreEqual((int)*(fifo.PEEK(2)), 33);

			int result = 0;
			Assert::IsTrue(fifo.Pop_End(result));

		    Assert::AreEqual((int)*(fifo.PEEK(1)), 22);
			Assert::AreEqual(result, 33);
			Assert::AreEqual((int)fifo.Count(), 2);

			fifo.Clear();
			Assert::AreEqual((int)fifo.Count(), 0);
		}

		
		//--------------------------------------

		//TREE

		//--------------------------------------

		TEST_METHOD(PreOrder_Rec)
		{
			cTree<char> Arbolito;
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			Arbolito.Add('I', puntero);
			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);
			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);
			DLinkList<char> lista;

			Arbolito.VisitPreOrder_Rec(&lista);

			Assert::AreEqual(lista.Get_data_node(0), 'F');
			Assert::AreEqual(lista.Get_data_node(1), 'B');
			Assert::AreEqual(lista.Get_data_node(2), 'A');
			Assert::AreEqual(lista.Get_data_node(3), 'D');
			Assert::AreEqual(lista.Get_data_node(4), 'C');
			Assert::AreEqual(lista.Get_data_node(5), 'E');
			Assert::AreEqual(lista.Get_data_node(6), 'G');
			Assert::AreEqual(lista.Get_data_node(7), 'H');
			Assert::AreEqual(lista.Get_data_node(8), 'I');
		}

		TEST_METHOD(PreOrder_Iterative)
		{
			cTree<char> Arbolito;
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			Arbolito.Add('I', puntero);
			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);
			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);

			DLinkList<char> lista;

			Arbolito.VisitPreOrder(&lista);

			Assert::AreEqual(lista.Get_data_node(0), 'F');
			Assert::AreEqual(lista.Get_data_node(1), 'B');
			Assert::AreEqual(lista.Get_data_node(2), 'A');
			Assert::AreEqual(lista.Get_data_node(3), 'D');
			Assert::AreEqual(lista.Get_data_node(4), 'C');
			Assert::AreEqual(lista.Get_data_node(5), 'E');
			Assert::AreEqual(lista.Get_data_node(6), 'G');
			Assert::AreEqual(lista.Get_data_node(7), 'H');
			Assert::AreEqual(lista.Get_data_node(8), 'I');
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(PostOrder_Recursive)
		{
			cTree<char> Arbolito;
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			puntero = Arbolito.Add('I', puntero);

			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);

			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);

			DLinkList<char> lista;

			Arbolito.VisitPostOrder_Rec(&lista);

			Assert::AreEqual(lista.Get_data_node(0), 'A');
			Assert::AreEqual(lista.Get_data_node(1), 'C');
			Assert::AreEqual(lista.Get_data_node(2), 'E');
			Assert::AreEqual(lista.Get_data_node(3), 'D');
			Assert::AreEqual(lista.Get_data_node(4), 'B');
			Assert::AreEqual(lista.Get_data_node(5), 'I');
			Assert::AreEqual(lista.Get_data_node(6), 'H');
			Assert::AreEqual(lista.Get_data_node(7), 'G');
			Assert::AreEqual(lista.Get_data_node(8), 'F');
		}

		TEST_METHOD(PostOrder_Iterative)
		{
			cTree<char> Arbolito;
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			puntero = Arbolito.Add('I', puntero);

			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);

			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);

			DLinkList<char> lista;

			Arbolito.VisitPostOrderIterative(&lista);

			Assert::AreEqual(lista.Get_data_node(0), 'A');
			Assert::AreEqual(lista.Get_data_node(1), 'C');
			Assert::AreEqual(lista.Get_data_node(2), 'E');
			Assert::AreEqual(lista.Get_data_node(3), 'D');
			Assert::AreEqual(lista.Get_data_node(4), 'B');
			Assert::AreEqual(lista.Get_data_node(5), 'I');
			Assert::AreEqual(lista.Get_data_node(6), 'H');
			Assert::AreEqual(lista.Get_data_node(7), 'G');
			Assert::AreEqual(lista.Get_data_node(8), 'F');
		}

		TEST_METHOD(InOrder_Recursive)
		{
			cTree<char> Arbolito;
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			puntero = Arbolito.Add('I', puntero);

			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);

			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);

			DLinkList<char> lista;

			Arbolito.VisitInOrder_Rec(&lista);

			Assert::AreEqual(lista.Get_data_node(0), 'A');
			Assert::AreEqual(lista.Get_data_node(1), 'B');
			Assert::AreEqual(lista.Get_data_node(2), 'C');
			Assert::AreEqual(lista.Get_data_node(3), 'D');
			Assert::AreEqual(lista.Get_data_node(4), 'E');
			Assert::AreEqual(lista.Get_data_node(5), 'F');
			Assert::AreEqual(lista.Get_data_node(6), 'G');
			Assert::AreEqual(lista.Get_data_node(7), 'H');
			Assert::AreEqual(lista.Get_data_node(8), 'I');
		}

		
		TEST_METHOD(InOrder_Iterative)
		{
			cTree<char> Arbolito;
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			puntero = Arbolito.Add('I', puntero);

			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);

			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);

			DLinkList<char> lista;

			Arbolito.VisitInOrder(&lista);

			Assert::AreEqual(lista.Get_data_node(0), 'A');
			Assert::AreEqual(lista.Get_data_node(1), 'B');
			Assert::AreEqual(lista.Get_data_node(2), 'C');
			Assert::AreEqual(lista.Get_data_node(3), 'D');
			Assert::AreEqual(lista.Get_data_node(4), 'E');
			Assert::AreEqual(lista.Get_data_node(5), 'F');
			Assert::AreEqual(lista.Get_data_node(6), 'G');
			Assert::AreEqual(lista.Get_data_node(7), 'H');
			Assert::AreEqual(lista.Get_data_node(8), 'I');
		}

		TEST_METHOD(Clear)
		{
			cTree<char> Arbolito;
			TreeNode<char>* puntero;
			TreeNode<char>* punteroBis;
			puntero = Arbolito.Add('F');
			punteroBis = Arbolito.Add('B', puntero);
			puntero = Arbolito.Add('G', puntero);
			puntero = Arbolito.Add('H', puntero);
			puntero = Arbolito.Add('I', puntero);
			Arbolito.Add('A', punteroBis);
			punteroBis = Arbolito.Add('D', punteroBis);
			Arbolito.Add('C', punteroBis);
			Arbolito.Add('E', punteroBis);

			Arbolito.Clear();

			Arbolito.Add('P');

			DLinkList<char> lista;

			Arbolito.VisitInOrder_Rec(&lista);

			Assert::IsTrue(lista.Count() == 1);
			Assert::AreEqual(lista.Get_node(0)->data, 'P');

		}






	};
}