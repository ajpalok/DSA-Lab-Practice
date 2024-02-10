// 9,5,1,4,3

#include<stdio.h>

void printFunction(int *arr, int size){
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

void insertionAscendingSort(int *array, int size){
    for(int step=1; step<=size-1; step++){
        int index = step,
            key = array[index];
        while(index!=0 && key<array[index-1]){
            array[index]=array[index-1];
            index--;
        }
        array[index]=key;
    }
}

void insertionDescendingSort(int *array, int size){
    for(int step=1; step<=size-1; step++){
        int index = step,
            key = array[index];
        while(index!=0 && key>array[index-1]){
            array[index]=array[index-1];
            index--;
        }
        array[index]=key;
    }
}

void main(){
    int arr[]={9,5,1,4,3},
        size= sizeof(arr)/sizeof(arr[0]);
    insertionAscendingSort(arr, size);
    printFunction(arr, size);
    puts("");
    insertionDescendingSort(arr, size);
    printFunction(arr, size);
}
