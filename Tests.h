#pragma once
#include "LinkedList.h"
#include "LinkedListSequence.h"
#include "ArraySequence.h"
#include "Person.h"
#include "BinaryTree.h"
#include <cassert> 
#include <string>

int array1[5] = { 1, 2, 3, 4, 5 };
int array2[3] = { 2, 3, 4 };
int array3[6] = { 1, 2, 3, 4, 5 ,6 };
int array4[6] = { 0, 1, 2, 3, 4, 5 };
int array5[8] = { 11, 1, 33, 2, 3, 4, 5, 22 };
int array6[10] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
int array7[6] = { 11, 1, 2, 3, 4, 5 };
int array8[7] = { 11, 1, 2, 3, 4, 5, 22 };
int array9[2] = { 1, 2 };
int array10[2] = { 2, 1 };
int array11[1] = { 1 };



//LinkedListSequence

void Test_of_GetLastLinkedListSequence()
{
	LinkedListSequence<int>list(array1, 5);
	assert(list.GetLast() == array1[4]);
}

void Test_of_GetFirst_LinkedListSequence()
{
	LinkedListSequence<int>list(array1, 5);
	assert(list.GetFirst() == array1[0]);
}

void Test_of_GetLength_LinkedListSequence()
{
	LinkedListSequence<int>list(array1, 5);
	assert(list.GetLength() == 5);
}

void Test_of_Get_LinkedListSequence()
{
	LinkedListSequence<int>list(array1, 5);
	for (int i = 0; i != list.GetLength(); i++)
	{
		assert(list.Get(i) == array1[i]);
	}
}

void Test_of_GetSubsequence_LinkedListSequence()
{
	LinkedListSequence<int>list(array1, 5);

	for (int i = 0; i != 5; i++)
	{
		for (int j = i + 1; j != 5; j++)
		{
			LinkedListSequence<int> sub = *(list.GetSubsequence(i, j));
			assert(sub.GetLength() == j - i + 1);
			for (int x = i; x < j; x++)
			{
				assert(array1[x] == sub.Get(x - i));
			}
		}
	}
}

void Test_of_Append_LinkedListSequence()
{
	LinkedListSequence<int>list(array1, 5);

	list.Append(6);
	assert(list.GetLength() == 6);
	for (int i = 0; i != list.GetLength(); i++)
	{
		assert(list.Get(i) == array3[i]);
	}
}

void Test_of_Prepend_LinkedListSequence()
{
	LinkedListSequence<int>list(array1, 5);

	list.Prepend(0);
	assert(list.GetLength() == 6);
	for (int i = 0; i != list.GetLength(); i++)
	{
		assert(list.Get(i) == array4[i]);
	}
}

void Test_of_InsertAt_LinkedListSequence()
{
	LinkedListSequence<int>empty_list;
	empty_list.InsertAt(1, 0);
	assert(empty_list.GetLength() == 1);
	assert(empty_list.Get(0) == 1);

	LinkedListSequence<int>list1(array11, 1);
	list1.InsertAt(2, 0);
	assert(list1.GetLength() == 2);
	for (int i = 0; i != list1.GetLength(); i++)
	{
		assert(list1.Get(i) == array10[i]);
	}

	LinkedListSequence<int>list2(array11, 1);
	list2.InsertAt(2, 1);
	assert(list2.GetLength() == 2);
	for (int i = 0; i != list2.GetLength(); i++)
	{
		assert(list2.Get(i) == array9[i]);
	}

	LinkedListSequence<int>list(array1, 5);
	list.InsertAt(11, 0);
	assert(list.GetLength() == 6);
	for (int i = 0; i != list.GetLength(); i++)
	{
		assert(list.Get(i) == array7[i]);
	}

	list.InsertAt(22, list.GetLength());
	assert(list.GetLength() == 7);
	for (int i = 0; i != list.GetLength(); i++)
	{
		assert(list.Get(i) == array8[i]);
	}

	list.InsertAt(33, 2);
	assert(list.GetLength() == 8);
	for (int i = 0; i != list.GetLength(); i++)
	{
		assert(list.Get(i) == array5[i]);
	}
}


void Test_of_Concat_LinkedListSequence()
{
	LinkedListSequence<int>list(array1, 5);
	LinkedListSequence<int> con_list = *(list.Concat(&list));
	assert(con_list.GetLength() == 10);

	for (int i = 0; i != 10; i++)
	{
		assert(array6[i] == con_list.Get(i));
	}

	LinkedListSequence<int>list1;
	LinkedListSequence<int> con_list1 = *(list.Concat(&list1));
	for (int i = 0; i != 5; i++)
	{
		assert(array1[i] == con_list1.Get(i));
	}
}

//Array

void Test_of_GetLastArraySequence()
{
	ArraySequence<int>array(array1, 5);
	assert(array.GetLast() == array1[4]);
}

void Test_of_GetFirst_ArraySequence()
{
	ArraySequence<int>array(array1, 5);
	assert(array.GetFirst() == array1[0]);
}

void Test_of_GetLength_ArraySequence()
{
	ArraySequence<int>array(array1, 5);
	assert(array.GetLength() == 5);
}

void Test_of_Get_ArraySequence()
{
	ArraySequence<int>array(array1, 5);
	for (int i = 0; i != array.GetLength(); i++)
	{
		assert(array.Get(i) == array1[i]);
	}
}

void Test_of_GetSubsequence_ArraySequence()
{
	ArraySequence<int>array(array1, 5);

	for (int i = 0; i != 5; i++)
	{
		for (int j = i + 1; j != 5; j++)
		{
			ArraySequence<int> sub = *(array.GetSubsequence(i, j));
			assert(sub.GetLength() == j - i + 1);
			for (int x = i; x < j; x++)
			{

				assert(array1[x] == sub.Get(x - i));
			}
		}
	}
}

void Test_of_Append_ArraySequence()
{
	ArraySequence<int>array(array1, 5);

	array.Append(6);
	assert(array.GetLength() == 6);
	for (int i = 0; i != array.GetLength(); i++)
	{
		assert(array.Get(i) == array3[i]);
	}

}

void Test_of_Prepend_ArraySequence()
{
	ArraySequence<int>array(array1, 5);

	array.Prepend(0);
	assert(array.GetLength() == 6);
	for (int i = 0; i != array.GetLength(); i++)
	{
		assert(array.Get(i) == array4[i]);
	}
}

void Test_of_InsertAt_ArraySequence()
{
	ArraySequence<int>empty_array;
	empty_array.InsertAt(1, 0);
	assert(empty_array.GetLength() == 1);
	assert(empty_array.Get(0) == 1);

	ArraySequence<int>arr1(array11, 1);
	arr1.InsertAt(2, 0);
	assert(arr1.GetLength() == 2);
	for (int i = 0; i != arr1.GetLength(); i++)
	{
		assert(arr1.Get(i) == array10[i]);
	}

	ArraySequence<int>arr2(array11, 1);
	arr2.InsertAt(2, 1);
	assert(arr2.GetLength() == 2);
	for (int i = 0; i != arr2.GetLength(); i++)
	{
		assert(arr2.Get(i) == array9[i]);
	}

	ArraySequence<int>arr(array1, 5);
	arr.InsertAt(11, 0);
	assert(arr.GetLength() == 6);
	for (int i = 0; i != arr.GetLength(); i++)
	{
		assert(arr.Get(i) == array7[i]);
	}

	arr.InsertAt(22, arr.GetLength());
	assert(arr.GetLength() == 7);
	for (int i = 0; i != arr.GetLength(); i++)
	{
		assert(arr.Get(i) == array8[i]);
	}

	arr.InsertAt(33, 2);
	assert(arr.GetLength() == 8);
	for (int i = 0; i != arr.GetLength(); i++)
	{
		assert(arr.Get(i) == array5[i]);
	}
}

void Test_of_Concat_ArraySequence()
{
	ArraySequence<int>array(array1, 5);
	ArraySequence<int> con_array = *(array.Concat(&array));
	assert(con_array.GetLength() == 10);

	for (int i = 0; i != 10; i++)
	{
		assert(array6[i] == con_array.Get(i));
	}

	ArraySequence<int>arr1;
	ArraySequence<int> con_array1 = *(array.Concat(&arr1));
	for (int i = 0; i != 5; i++)
	{
		assert(array1[i] == con_array1.Get(i));
	}
}

//Binary Tree

void Test_BinaryTree_GetLength_Int()
{
	int elem = 3;
	int arr1[3] = { 1, 2, 3 };

	BinaryTree<int> bin_tree1(elem);
	BinaryTree<int> bin_tree2(arr1, 3);
	BinaryTree<int> bin_tree3;

	assert(bin_tree1.GetLength() == 1);
	assert(bin_tree2.GetLength() == 3);
	assert(bin_tree3.GetLength() == 0);
}

void Test_BinaryTree_Get_Int()
{
	int arr1[3] = { 1, 2, 3 };
	BinaryTree<int> bin_tree(arr1, 3);
	for (int i = 0; i != bin_tree.GetLength(); i++)
	{
		assert(bin_tree.Get(i) == arr1[i]);
	}
}

void Test_BinaryTree_Insert_Int()
{
	int element = 3;
	int arr1[3] = { 1, 2, 3 };
	int arr2[3] = { 1, 2, 4 };
	std::string ans1 = "3 ", ans2 = "1 2 3 ", ans3 = "1 2 3 4 ";
	int arr3[1] = { 3 };
	int arr4[4] = { 1, 2, 3, 4 };

	BinaryTree<int> bin_tree1;
	BinaryTree<int> bin_tree2(arr1, 3);
	BinaryTree<int> bin_tree3(arr2, 3);

	bin_tree1 += element;
	bin_tree2 += element;
	bin_tree3 += element;

	for (int i = 0; i != bin_tree1.GetLength(); i++)
	{
		assert(bin_tree1.Get(i) == arr3[i]);
	}

	for (int i = 0; i != bin_tree2.GetLength(); i++)
	{
		assert(bin_tree2.Get(i) == arr1[i]);
	}

	for (int i = 0; i != bin_tree3.GetLength(); i++)
	{
		assert(bin_tree3.Get(i) == arr4[i]);
	}

}

void Test_BinaryTree_DeleteElem_Int()
{
	char order[]{ "lRr" };
	int element = 3;
	int arr1[3] = { 1, 2, 3 };
	int arr2[3] = { 1, 2, 4 };
	std::string ans1 = "", ans2 = "1 2 ", ans3 = "1 2 4 ";
	int arr3[2] = {1, 2};

	BinaryTree<int> bin_tree1;
	BinaryTree<int> bin_tree2(arr1, 3);
	BinaryTree<int> bin_tree3(arr2, 3);
	BinaryTree<int> bin_tree4(element);

	bin_tree1 -= element;
	bin_tree2 -= element;
	bin_tree3 -= element;
	bin_tree4 -= element;

	for (int i = 0; i != bin_tree1.GetLength(); i++)
	{
		assert(bin_tree1.GetLength() == 0);
	}

	for (int i = 0; i != bin_tree2.GetLength(); i++)
	{
		assert(bin_tree2.Get(i) == arr3[i]);
	}

	for (int i = 0; i != bin_tree3.GetLength(); i++)
	{
		assert(bin_tree3.Get(i) == arr2[i]);
	}

	for (int i = 0; i != bin_tree4.GetLength(); i++)
	{
		assert(bin_tree4.GetLength() == 0);
	}
}

void Test_BinTree_SearchSubtree_Int()
{
	int element = 3;
	int arr1[3] = { 1, 2, 3 };
	bool ans1 = true, ans2 = true, ans3 = true, ans4 = false;

	BinaryTree<int> bin_tree1(arr1, 3);
	BinaryTree<int> bin_tree2(element);

	bool bool1 = bin_tree1.SearchSubtree(&bin_tree1);
	assert(bool1 == ans1);

	bool bool2 = bin_tree1.SearchSubtree(&bin_tree2);
	assert(bool2 == ans2);

	bool bool3 = bin_tree2.SearchSubtree(&bin_tree2);
	assert(bool3 == ans3);

	bool bool4 = bin_tree2.SearchSubtree(&bin_tree1);
	assert(bool4 == ans4);
}

void Test_BinTree_SubTree_Int()
{
	int element = 3;
	int arr1[3] = { 1, 2, 3 };
	std::string ans1 = "", ans2 = "3 ";
	int arr2[1] = { 3 };

	BinaryTree<int> bin_tree2(arr1, 3);

	BinaryTree<int>* sub = bin_tree2.SubTree(element);

	for (int i = 0; i != sub->GetLength(); i++)
	{
		assert(sub->Get(i) == arr2[i]);
	}
}

void Test_BinTree_SearchBool_Int()
{
	int element1 = 3;
	int element2 = 4;
	int arr1[3] = { 1, 2, 3 };
	int arr2[3] = { 5, 6, 7 };

	BinaryTree<int> bin_tree1(arr1, 3);
	BinaryTree<int> bin_tree2(arr2, 3);
	BinaryTree<int> bin_tree_empty;

	bool result1 = bin_tree1.SearchBool(element1);
	assert(result1 == true);

	bool result2 = bin_tree1.SearchBool(element2);
	assert(result2 == false);

	bool result3 = bin_tree_empty.SearchBool(element1);
	assert(result3 == false);

	bool result4 = bin_tree2.SearchBool(element1);
	assert(result4 == false);
}

// SortedSequence

//Dictionary

//Set

//SparceVector