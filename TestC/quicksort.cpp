// http://quiz.geeksforgeeks.org/quick-sort/
#include <stdio.h>
#include <iostream>

extern void swap(int& value1, int& value2);
extern void printArray(int arr[], int size);

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = low;  // Index of smaller element
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            swap(arr[i],  arr[j]);
            i++;    // increment index of smaller element
        }
    }
    
    // The pivot is i
    swap(arr[i ], arr[high]);
    return i ;
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pivot = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
 
// Driver program to test above functions
void quickSortTest()
{
    int arr[] = {10, 7, 8, 9, 1, 5} ;
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
}