// Today we will learn about Sorting Algorithms
// Bubble Sort
// Selection Sort
// Insertion Sort

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int BubbleSort(int *arr, int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int SelectionSort(int *arr, int size){
    int min;
    for(int i=0; i<size-1; i++){
        min = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

int InsertionSort(int *arr, int size){
    int key, j;
    for(int i=1; i<size; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void main(){
    int arr[] = {5,4,3,2,1}, size=5;

    // BubbleSort
    BubbleSort(arr, size);
    printArray(arr, size);

    // SelectionSort
    SelectionSort(arr, size);
    printArray(arr, size);

    // InsertionSort
    InsertionSort(arr, size);
    printArray(arr, size);
}