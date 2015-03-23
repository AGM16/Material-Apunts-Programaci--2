#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Apunts_Prog2/Point2D.h"
#include "../Apunts_Prog2/String.h"
#include "../Apunts_Prog2/String.cpp"
#include "../Apunts_Prog2/DinamicArray.h"
#include "../Apunts_Prog2/DoubleClassList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		//-----------------------------------

		//Class Point2D

		//-----------------------------------


		TEST_METHOD(TestPoint2D_menor_major)
		{
			Point2D<int> B, C;
			B.px = 1;
			B.py = 1;
			C.px = 2;
			C.py = 2;

			

			Assert::IsTrue(B.px < C.px );

		}

		TEST_METHOD(TestPoint2D_assignation)
		{
			Point2D<int> B, C;
			B.px = 1;
			B.py = 2;
			C.px = 2;
			C.py = 2;

			C = B;

			Assert::AreEqual(C.px, 1);

		}

		TEST_METHOD(TestPoint2D_multiplication)
		{
			Point2D<int> B, C, Result;
			B.px = 1;
			B.py = 2;
			C.px = 2;
			C.py = 3;

		    Result = C * B;

			Assert::AreEqual(Result.py, 6);
			Assert::AreEqual(Result.px, 2);
		}

		TEST_METHOD(TestPoint2D_division)
		{
			Point2D<int> B, C, Result;
			B.px = 2;
			B.py = 2;
			C.px = 2;
			C.py = 6;

			Result = C / B;

			Assert::AreEqual(Result.py, 3);
			Assert::AreEqual(Result.px, 1);
		}

		
		TEST_METHOD(TestPoint2D_Operator_add)
		{
			Point2D<int> B, C, Result;
			
			B.px = 1;
			B.py = 2;
			C.px = 3;
			C.py = 2;

			Result = B + C;
			Assert::AreEqual(Result.px, 4);

		}

		TEST_METHOD(TestPoint2D_Operator_remove)
		{
			Point2D<int> B, C, Result;

			B.px = 1;
			B.py = 2;
			C.px = 3;
			C.py = 2;

			Result = B - C;
			Assert::AreEqual(Result.px, -2);

		}

		TEST_METHOD(TestPoint2D_Operator_add_equal)
		{
			Point2D<int> B, C;

			B.px = 1;
			B.py = 2;
			C.px = 3;
			C.py = 2;

			B += C;
			Assert::AreEqual(B.px, 4);

		}

		
		TEST_METHOD(TestPoint2D_Operator_add_remove)
		{
			Point2D<int> B, C;

			B.px = 1;
			B.py = 2;
			C.px = 3;
			C.py = 2;

			B -= C;
			Assert::AreEqual(B.px, -2);

		}

		TEST_METHOD(TestPoint2D_Operator_equal)
		{
			Point2D<int> B, C;

			B.px = 2;
			B.py = 2;
			C.px = 2;
			C.py = 2;

			Assert::IsTrue( B == C);

		}

		TEST_METHOD(TestPoint2D_Operator_not_equal)
		{
			Point2D<int> B, C;

			B.px = 0;
			B.py = 1;
			C.px = 2;
			C.py = 3;

			Assert::IsTrue(B != C);

		}

		TEST_METHOD(TestPoint2D_Swap)
		{
			Point2D<int> B,C;

			B.px = 1;
			B.py = 2;
			C.px = 1;
			C.py = 2;

			B.Swap(B.px, B.py);

			Assert::AreEqual(B.px, 2);
			Assert::AreEqual(B.py, 1);
		}
		TEST_METHOD(TestPoint2D_Operator_Is_Zero)
		{
			Point2D<int> B;

			B.px = 0;
			B.py = 0;

			Assert::IsTrue(B.IsZero());

		}


		TEST_METHOD(TestPoint2D_Operator_Set_Zero)
		{
			Point2D<int> B;

			B.px = 8;
			B.py = 6;

			B.SetZero();

			Assert::AreEqual(B.px , 0);
		}

		TEST_METHOD(TestPoint2D_Operator_Convert_Negative)
		{
			Point2D<int> B;

			B.px = 8;
			B.py = 6;

			B.Negate();

			Assert::AreEqual(B.px, -8);
		}

		TEST_METHOD(TestPoint2D_Operator_Distance_To)
		{
			Point2D<double> B, C;

			B.px = 8;
			B.py = 6;
			C.px = 7;
			C.py = 6;

			Assert::AreEqual(B.DistanceTo(C), 1.00);
		}


		//-----------------------------------

		//Class Point2D

		//-----------------------------------

		
		//CONSTRUCTORS
		TEST_METHOD(TestString_empty)
		{
			String b;
			Assert::AreEqual((int)b.Length(), 0);
		}


		TEST_METHOD(TestString_Copy_char_c)
		{
			String b("Hola mundo");
			Assert::AreEqual((int)b.Length(), 10);
		}

		TEST_METHOD(TestString_Copy_of_other_String_Class)
		{
			String b("Hola mundo"),c;
			c = b;
			Assert::AreEqual((int)b.Length(), 10);
		}

		//OPERATORS
		TEST_METHOD(TestString_equal_string_c)
		{
			String b("Hola");
			Assert::IsTrue(b == "Hola");
		}

		TEST_METHOD(TestString_not_equal_string_c)
		{
			String b("%s%s%d", "hola", "mundo",18);
			unsigned int a = 11;
			Assert::AreEqual(b.Length(), a);
		}

		TEST_METHOD(TestString_equal_string_class)
		{
			String b("Hola"), c("Hola");
			Assert::IsTrue(b == c);
		}

		TEST_METHOD(TestString_are_not_equal_string_class)
		{
			String b("Hi"), c("Hey");
			Assert::IsTrue(b != c);
		}

		TEST_METHOD(TestString_assignation_string_c)
		{
			String b("Pablo");
			b = "Jose Maria";
			Assert::IsTrue(b == "Jose Maria");
		}

		TEST_METHOD(TestString_assignation_string_class)
		{
			String b("Pablo"), c ("Pedro");
			b = c;
			Assert::IsTrue(b == "Pedro");
		}

		TEST_METHOD(TestString_equal_add_string_c)
		{
			String b("Pablo ");
			b += "Manolo";
			Assert::IsTrue(b == "Pablo Manolo");
		}
		
		TEST_METHOD(TestString_equal_add_string_class)
		{
			String b("Pablo "), c("Pedro");
			b += c;
			Assert::IsTrue(b == "Pablo Pedro");
		}

		//OTHERS METHODS

		TEST_METHOD(TestString_Length)
		{
			String b("Pablo");
			Assert::AreEqual((int)b.Length(), 5 );
		}

		TEST_METHOD(TestString_Capacity)
		{
			String b("P");
			Assert::AreEqual((int)b.Capacity(), 2);
		}

		TEST_METHOD(TestString_GetString)
		{
			String b("P");
			Assert::AreEqual(b.getString(), "P");
		}


		TEST_METHOD(TestString_Clear)
		{
			String b("Pedro");
			b.Clear();
			Assert::AreEqual((int)b.Length(), 0);
		}



		//-----------------------------------

		//DoubleLinkList

		//-----------------------------------
		TEST_METHOD(TestLinklist_Add_Double)
		{
			DoubleClassList<int> A;
			A.AddDoubleNode(1);
			A.AddDoubleNode(2);
			unsigned int b = 2;
			Assert::AreEqual(A.DoubleCount(), b);
		}


		TEST_METHOD(TestLinklist_Delete_Double_Node)
		{
			DoubleClassList<int> A;
			A.AddDoubleNode(5);
			A.AddDoubleNode(2);
			A.AddDoubleNode(3);
			A.DeleDoubleNode(A.End);
			unsigned int b = 2;
			Assert::AreEqual(A.DoubleCount(), b);
		}


		TEST_METHOD(TestLinklist_Double_Delete_All)
		{
			DoubleClassList<int> A;
			A.AddDoubleNode(5);
			A.DeleAll();
			unsigned int b = 0;
			Assert::AreEqual(A.DoubleCount(), b);
		}


		TEST_METHOD(TestLinklist_Operator)
		{
			DoubleClassList<int> A;
			A.AddDoubleNode(5);
			A[0] = 1;
			int b = 1;
			Assert::AreEqual(A[0], b);
		}


		TEST_METHOD(TestLinklist_Double_Count)
		{
			DoubleClassList<int> A;
			A.AddDoubleNode(5);
			unsigned int b = 1;
			Assert::AreEqual(A.DoubleCount(), b);
		}



		//-----------------------------------

		//DinamicArray

		//-----------------------------------

		TEST_METHOD(TestString_Inicial)
		{
			DinamicArray<int> word;
			unsigned int b = 0;
			Assert::AreEqual(word.Count(), b);
			
		}
		
		TEST_METHOD(TestString_Insert)
		{
			DinamicArray<int> word(3);
			word.Insert(2, 0);
			word.Insert(1, 2);
		    //word.PushBack(3);
			//word.Pop1();
			unsigned int b = 4;
			Assert::AreEqual(word[0], 2);
			Assert::AreEqual(word[2], 1);
		}

		TEST_METHOD(TestString_PushBack)
		{
			DinamicArray<int> word(1);
			word.PushBack(3);
			//word.Pop1();
			unsigned int b = 2;
			Assert::AreEqual(word[1], 3);
			Assert::AreEqual(word.Count(), b);
		}
		
		TEST_METHOD(TestString_Pop)
		{
			DinamicArray<int> word(1);
			word.Pop1();
			unsigned int b = 0;
			Assert::AreEqual(word.Count(), b);
		}

		TEST_METHOD(TestString_Operator)
		{
			DinamicArray<int> word(2);
			word[0] = 1;
			word[1] = 2;
			Assert::AreEqual(word[0], 1);
			Assert::AreEqual(word[1], 2);
		}

		TEST_METHOD(TestString_getCapacity)
		{
			DinamicArray<int> word(10);
			unsigned int b = 10;
			Assert::AreEqual(word.GetCapacity(), b);
		}
		
		TEST_METHOD(TestString_clear)
		{
			DinamicArray<int> word(10);
			word.Clear();
			unsigned int b = 0;
			Assert::AreEqual(word.Count(), b);

		}


		TEST_METHOD(TestString_at)
		{
			DinamicArray<int> word;

			word.PushBack(1);
			word.PushBack(2);
			word.PushBack(3);

			Assert::AreEqual(*(word.At(0)), 1);
			Assert::AreEqual(*(word.At(1)), 2);
			Assert::AreEqual(*(word.At(2)), 3);
			Assert::IsNull(word.At(3));
		}


	};
}