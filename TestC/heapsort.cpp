// C++ program for implementation of Heap Sort
// http://quiz.geeksforgeeks.org/heap-sort/
#include <iostream>
using namespace std;
 
void swap(int& value1, int& value2)
{
    int temp = value2;
    value2 = value1;
    value1 = temp;
}

/* A utility function to print array of size n */
void printArray(int arr[], int size)
{
    for (int index = 0; index < size; ++index)
    {
        cout << arr[index] << " ";
    }
    cout << endl;
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. size is size of heap
void heapify(int arr[], int size, int current)
{
    int largest = current;  // Initialize largest as root
    int left = 2 * current + 1;  // left = 2*i + 1
    int right = 2 * current + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not root
    if (largest != current)
    {
        swap(arr[current], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int size)
{
    // Build heap bottom up (rearrange array)
    for (int index = size / 2 - 1; index >= 0; --index)
    {
        heapify(arr, size, index);
    }

    // One by one extract an element from heap
    for (int index = size - 1; index >= 0; --index)
    {
        // Move current root to end
        swap(arr[0], arr[index]);
 
        // call max heapify on the reduced heap
        heapify(arr, index, 0);
    }
}
 
void heapSortTest() 
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, size);
 
    cout << "Sorted array is \n";
    printArray(arr, size);
}