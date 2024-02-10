// Write an Algorithm where an given array 
// a[]={5,3,1,2,4,8,7} will be:

// a) sorted in a following rules:
//     1) odd indexes will sort in ascending
//        order with even numbers of the array
//        using bubble sort
//     2) even indexes will sort in descending
//        order with odd numbers of the array using selection sort

// b) Now using binary search, find 8 from the array

#include <stdio.h>

void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i += 2)
    {
        for (j = 0; j < n - i - 1; j += 2)
        {
            if (a[j] > a[j + 2])
            {
                temp = a[j];
                a[j] = a[j + 2];
                a[j + 2] = temp;
            }
        }
    }
}

void selectionSort(int a[], int n)
{
    int i, j, temp, min;
    for (i = 0; i < n; i += 2)
    {
        min = i;
        for (j = i + 2; j < n; j += 2)
        {
            if (a[j] > a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int binarySearch(int a[], int n, int x)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int a[] = {5, 2, 1, 4, 3, 8, 7};
    int n = 7, i, x = 8;
    bubbleSort(a, n);
    selectionSort(a, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int index = binarySearch(a, n, x);
    if (index == -1)
    {
        printf("%d is not found in the array\n", x);
    }
    else
    {
        printf("%d is found at index %d\n", x, index);
    }
    return 0;
}

// Output:
// Sorted array: 1 3 2 5 4 7 8
// 8 is found at index 6