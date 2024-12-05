#include <iostream>
#include <stdexcept>
#include <string>
#include "Tests.h"
#include "ArraySequence.h"
#include "DictionaryOnSequence.h"
#include "SparseVector.h"
#include "BinaryTree.h"
#include "SetOnBinaryTree.h"
#include "Histogram.h"
#include "SortedSequenceOnSequence.h"

using namespace std;

template<class T>
void EnterSparseVector(SparseVector<T>* seq, int Size)
{
    int size = Size;

    if (!cin)
    {
        cerr << "Error: invalid input (not an integer)." << endl;
        exit(1);
    }

    int elem;
    if (size != 0) 
    {
        cout << "enter the values\n";
    }

    for (int i = 0; i < size; i++) 
    {
        cin >> elem;

        if (!cin)
        {
            cerr << "Error: invalid input (not an integer)." << endl;
            exit(1);
        }
        seq->Set(i, elem);
    }
}

template<class T>
void EnterSequence(SortedSequenceOnSequence<T>* seq)
{
    cout << "enter the size\n";
    int size;
    cin >> size;

    if (!cin)
    {
        cerr << "Error: invalid input (not an integer)." << endl;
        exit(1);
    }

    int elem;
    if (size != 0) 
    {
        cout << "enter the values\n";
    }

    for (int i = 0; i < size; i++) 
    {
        cin >> elem;

        if (!cin)
        {
            cerr << "Error: invalid input (not an integer)." << endl;
            exit(1);
        }
        seq->Add(elem);
    }
}

void histogramMenu() 
{
    Histogram<int> histogram;
    SortedSequenceOnSequence<int> sequence;
    EnterSequence<int>(&sequence);

    while (true) 
    {
        std::cout << "\n--- Histogram Menu ---\n";
        std::cout << "1. Add element to sequence\n";
        std::cout << "2. Create histogram\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int value;
            std::cout << "Enter an integer value: ";
            std::cin >> value;
            sequence.Add(value);
            std::cout << "Value added.\n";
        }
        
        else if (choice == 2) 
        {
            int range;
            std::cout << "Enter range for grouping: ";
            std::cin >> range;

            try 
            {
                auto hist = histogram.CreateHistogramInt(sequence, range); 
                histogram.PrintHistogram(hist);
            }
            catch (const char* error_message)
            {
                cout << endl << error_message << " ";
            }
        }
        
        else if (choice == 3) 
        {
            break;
        }

        else 
        {
            std::cout << "Invalid option. Try again.\n";
        }
    }
}

void sparseVectorMenu() 
{
    std::cout << "\n--- Sparse Vector Menu ---\n";
    int size;
    std::cout << "Enter size of sparse vector: ";
    std::cin >> size;


    SparseVector<int> sparseVector(size, 0);
    EnterSparseVector<int>(&sparseVector, size);

    while (true) 
    {
        std::cout << "\n--- Sparse Vector Menu ---\n";
        std::cout << "1. Set value\n";
        std::cout << "2. Get value\n";
        std::cout << "3. Append value\n";
        std::cout << "4. Print vector\n";
        std::cout << "5. Get non-zero count\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) 
        {
            int index, value;
            std::cout << "Enter index: ";
            std::cin >> index;
            std::cout << "Enter value: ";
            std::cin >> value;

            try
            {
                sparseVector.Set(index, value);
                std::cout << "Value set.\n";
            }
            catch (const char* error_message)
            {
                cout << endl << error_message << " ";
            }
        }

        else if (choice == 2) 
        {
            int index;
            std::cout << "Enter index: ";
            std::cin >> index;

            try 
            {
                int value = sparseVector.Get(index);
                std::cout << "Value at index " << index << ": " << value << "\n";
            }
            catch (const char* error_message)
            {
                cout << endl << error_message << " ";
            }
        }
        
        else if (choice == 3) 
        {
            int value;
            std::cout << "Enter value to append: ";
            std::cin >> value;
            try
            {
                sparseVector.Append(value);
                std::cout << "Value appended.\n";
            }
            catch (const char* error_message)
            {
                cout << endl << error_message << " ";
            }
        }
        else if (choice == 4) 
        {
            std::cout << sparseVector << "\n";
        }
        else if (choice == 5) 
        {
            std::cout << "Non-zero count: " << sparseVector.GetNonZeroCount() << "\n";
        }
        else if (choice == 6) 
        {
            break;
        }
        else 
        {
            std::cout << "Invalid option. Try again.\n";
        }
    }
}

int main()
{
    Test_of_GetLastLinkedListSequence();
    Test_of_GetFirst_LinkedListSequence();
    Test_of_GetLength_LinkedListSequence();
    Test_of_Get_LinkedListSequence();
    Test_of_GetSubsequence_LinkedListSequence();
    Test_of_Append_LinkedListSequence();
    Test_of_Prepend_LinkedListSequence();
    Test_of_InsertAt_LinkedListSequence();
    Test_of_Concat_LinkedListSequence();

    Test_BinaryTree_GetLength_Int();
    Test_BinaryTree_Get_Int();
    Test_BinaryTree_Insert_Int();
    Test_BinaryTree_DeleteElem_Int();
    Test_BinTree_SearchSubtree_Int();
    Test_BinTree_SubTree_Int();
    Test_BinTree_SearchBool_Int();

    Test_of_GetLastArraySequence();
    Test_of_GetFirst_ArraySequence();
    Test_of_GetLength_ArraySequence();
    Test_of_Get_ArraySequence();
    Test_of_GetSubsequence_ArraySequence();
    Test_of_Append_ArraySequence();
    Test_of_Prepend_ArraySequence();
    Test_of_InsertAt_ArraySequence();
    Test_of_Concat_ArraySequence();

    while (true) 
    {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Histogram\n";
        std::cout << "2. Sparse Vector\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) 
        {
            histogramMenu();
        }
        else if (choice == 2) 
        {
            sparseVectorMenu();
        }
        else if (choice == 3) 
        {
            break;
        }
        else 
        {
            std::cout << "Invalid option. Try again.\n";
        }
    }
}