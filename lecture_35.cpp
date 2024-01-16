// Approach number 01
#include <iostream>
using namespace std;
// In this, function it will merge left and right array part - 1:
void merge(int *arr, int start, int end)
{
    // Mid of an array:
    int mid = start + (end - start) / 2;
    // length of left and right array:
    int len1 = mid - start + 1;
    int len2 = end - mid;
    // Creating two new array:
    int *first = new int[len1];
    int *second = new int[len2];
    // Copying value into created array:
    int mainIndexArray = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainIndexArray++];
    }
    mainIndexArray = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainIndexArray++];
    }
    // Merging left and right array:
    int index1 = 0;
    int index2 = 0;
    mainIndexArray = start;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainIndexArray++] = first[index1++];
        }
        else
        {
            arr[mainIndexArray++] = second[index2++];
        }
    }
    // it will only add the element of left array because may be it will bigger than right:
    while (index1 < len1)
    {
        arr[mainIndexArray++] = first[index1++];
    }
    // it will only add the element of right array because may be it will bigger than left:
    while (index2 < len2)
    {
        arr[mainIndexArray++] = second[index2++];
    }
    delete[] first;
    delete[] second;
}
// Function of creating 2 different arrays part - 1:
void mergeSort(int *arr, int start, int end)
{
    // Base case:
    if (start >= end)
    {
        return;
    }
    // Mid of an array:
    int mid = start + (end - start) / 2;
    // Left part of an array:
    mergeSort(arr, start, mid);
    // Right part of an array:
    mergeSort(arr, mid + 1, end);
    // Merging left and right part of an array:
    merge(arr, start, end);
}
// function of inversion count:
int getInvCount(int arr2[], int size2)
{
    int count = 0;
    for (int i = 0; i < size2 - 1; i++)
    {
        for (int j = i + 1; j < size2; j++)
        {
            if (arr2[i] > arr2[j])
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    // Merge Sort:
    int arr1[5] = {10, 20, 5, 2, 50};
    int size1 = 5;
    int start = 0;
    int end = size1 - 1;
    cout << "Merge Sorted array is: ";
    mergeSort(arr1, start, end);
    for (int i = 0; i < size1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Inversion code:
    int arr2[5] = {10, 20, 5, 2, 50};
    int size2 = 5;
    int ans = getInvCount(arr2, size2);
    cout << "Inversion count in the array is: " << ans << endl;
}

/*Approach number 02:
#include <iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end)
{
    int start2 = mid + 1;

    // If the direct merge is already sorted
    if (arr[mid] <= arr[start2])
    {
        return;
    }

    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && start2 <= end)
    {

        // If element 1 is in right place
        if (arr[start] <= arr[start2])
        {
            start++;
        }
        else
        {
            int value = arr[start2];
            int index = start2;

            // Shift all the elements between element 1
            // element 2, right by 1.
            while (index != start)
            {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;

            // Update all the pointers
            start++;
            mid++;
            start2++;
        }
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        // Same as (l + r) / 2, but avoids overflow
        // for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
    cout << endl;
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = 6;

    mergeSort(arr, 0, arr_size - 1);
    printArray(arr, arr_size);
    return 0;
}*/
