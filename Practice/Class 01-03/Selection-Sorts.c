// 9,5,1,4,3

#include<stdio.h>

void swap(int *a, int *b){
    int temp= *a;
    *a=*b;
    *b=temp;
}

void printFunction(int *arr, int size){
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

void selectionAscendingSort(int *array, int size){
    for(int step=0; step<size-1; step++){
        int min_index=step;
        for(int i=min_index; i<size; i++){
            if(array[min_index]>array[i+1])
                min_index=i+1;
        }
        swap(&array[step], &array[min_index]);
    }
}

void selectionDescendingSort(int *array, int size){
    for(int step=0; step<size-1; step++){
        int min_index=step;
        for(int i=size; i>min_index; i--){
            if(array[min_index]<array[i-1])
                min_index=i-1;
        }
        swap(&array[step], &array[min_index]);
    }
}

void main(){
    int arr[]={9,5,1,4,3},
        size= sizeof(arr)/sizeof(arr[0]);
    selectionAscendingSort(arr, size);
    printFunction(arr, size);
    puts("");
    selectionDescendingSort(arr, size);
    printFunction(arr, size);
}
