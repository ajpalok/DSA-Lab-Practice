#include <stdio.h>

void printArray(int arr[], int arrSize){
    for(int i=0; i<arrSize; i++){
        printf("%d ", arr[i]);
    }
}

void dataEntry(int *arr, int size){
    for(int i=0; i<size; i++){
        arr[i]= (i+1)*100;
    }
}

void main(){
    int size=10, n[size];

    dataEntry(n, size);

    printArray(n, size);

} 

// 100,200,300,400,500....1000

// &n[0] = n