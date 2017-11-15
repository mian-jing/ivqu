// http://www.bogotobogo.com/Algorithms/mergesort.php
// http://stackoverflow.com/questions/12030683/implementing-merge-sort-in-c
// http://www.geeksforgeeks.org/iterative-merge-sort/
//http://www.codecodex.com/wiki/Merge_sort#C.2B.2B
//https://www.hackerrank.com/challenges/security-tutorial-functions
#include <iostream>
#include <vector>

extern void printArray(int arr[], int size);

void merge(int *arr, int sizeL, int sizeR)
{
    std::vector<int> mergeArr(sizeL + sizeR);
    int indexL = 0, indexR = 0;
    int *arrLeft = arr, *arrRight = arr + sizeL;

    while (indexL + indexR < sizeL + sizeR)
    {
        if ((indexL < sizeL) &&
            (arrLeft[indexL] <= arrRight[indexR] || indexR >= sizeR))
        {
            // Move the value from left array into merged array when
            // 1) The value is smaller than current value in right array
            // 2) There is no remaining value in right array
            mergeArr[indexL + indexR] = arrLeft[indexL];
            indexL++;
        }

        if ((indexR < sizeR) &&
            (arrRight[indexR] < arrLeft[indexL] || indexL >= sizeL))
        {
            // Move the value from right  array into merged array when
            // 1) The value is smaller than current value in left array
            // 2) There is no remaining value in left array
            mergeArr[indexL + indexR] = arrRight[indexR];
            indexR++;
        }
    }

    for (int index=0; index < sizeL + sizeR; ++index)
    {
        arr[index] = mergeArr[index];
    }
}

void mergeSort(int *arr, int size)
{
    if (size == 1)
    {
        return;
    }

    // Divide the array into half
    int sizeL = size / 2;
    int sizeR = size - sizeL;

    // Merge sort each half
    mergeSort(arr, sizeL);
    mergeSort(arr + sizeL, sizeR);

    // Mege two sorted array
    merge(arr, sizeL, sizeR);
}

void mergeSortTest()
{
     /*
     cout << "How many numbers do you want to sort: ";
     cin >> num;
     int a[num];
     for (int i = 0; i < num; i++) {
       cout << (i + 1) << ": ";
       cin >> a[i];
     }
    */
    int arr[] = { 7, 1, 2, 10, 5};
    int num = sizeof(arr) / sizeof(arr[0]);

    // Start merge sort
    mergeSort(arr, num);

    // Print the sorted array
    printArray(arr, num);
}

