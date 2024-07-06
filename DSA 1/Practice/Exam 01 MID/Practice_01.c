// We are going to sort an array
// arr[8]={9,4,5,2,7,8,1,6}
// where odd index will sort in ascending order using insertion sort
// and even index will sort in descending order using selection sort

#include <stdio.h>
#include <stdbool.h>
// A counter function that will return amount odd numbers
int oddcounter(int *arr, int size){
    int counter=0;
    for(int i=0; i<size; i++) if(arr[i]%2!=0) ++counter;
    return counter;
}

// A counter function that will return amount even numbers
int evencounter(int *arr, int size){
    int counter=0;
    for(int i=0; i<size; i++) if(arr[i]%2==0) ++counter;
    return counter;
}


// A function that will swap 2 values of an array
void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// A function that will print the arr
void printArray(int *arr, int size){
    for(int i = 0; i < size; i++) printf("%d ",arr[i]);
}

// this will sort even numbers in
// odd indexes in ascending order
// using insertion sort
void oddIndexSort(int *arr, int size){
    int odd_count = oddcounter(arr, size);
    for(int step = 1; step<=odd_count-1; step++){
        int possition = 2*step+1,
            key = arr[possition];
        // This will do each index sort in each step
        for(int index=possition; index>=possition; index=index-2){
            // sorting ascending order
            if(arr[index]<arr[index-2]){
                arr[index] = arr[index-2];
                arr[index-2] = key;
            }
        }
    }
}

// this will sort odd numbers in
// even indexes in descending order
// using selection sort
void evenIndexSort(int *arr, int size){
    int even_count=evencounter(arr, size);
    for(int step=1; step<=even_count-1; step++){
        int swapping_index=2*step-2,
            big_data_index=swapping_index;
        for(int index=swapping_index; index<size-1; index+=2){
            // Searching and selecting big data index
            if(arr[big_data_index]<arr[index]){
                big_data_index=index;
            }
        }
        swap(arr, swapping_index, big_data_index);
    }
}

// Linear Searching Function
void linearSearch(int *arr, int size, int searchItem){
    bool found = false;
    int i = 0;
    while(!found){
        if(arr[i]==searchItem){
            printf("Item Found in: %d\n", i);
            found=true;
        }
        i++;
        if(i==size) break;
    }
    if(!found) printf("Item not Found!!!\n");
}

// Binary Searching Function

bool oddBinarySearch(int *arr, int size, int searchItem){

}

bool evenBinarySearch(int *arr, int size, int searchItem){
    
}

void binarySearch(int *arr, int size, int searchItem){
    bool found = false;

    if(searchItem%2==0) found=evenBinarySearch(*arr, size, searchItem);
    else found=oddBinarySearch(*arr, size, searchItem);

    if(!found) printf("Item not Found!!!\n");
}

void main(){
    // take input of array
    int size;
    printf("Input size(even number): ");
    scanf("%d", &size);
    while (size%2!=0)
    {
        printf("Please input EVEN size: ");
        scanf("%d", &size);
    }
    
    int arr[size];

    printf("Please input:\n");
    for(int i=0; i<size; i++){
        if(i%2==0){
            printf("ODD data for Even index %d: ", i);
            scanf("%d", &arr[i]);
            // Error handle of taking even data as input
            while(arr[i]%2==0){
                printf("Please input Correct ODD data: ");
                scanf("%d", &arr[i]);
            }
        }else{
            printf("EVEN data for Odd index %d: ", i);
            scanf("%d", &arr[i]);
            // Error handle of taking even data as input
            while(arr[i]%2!=0){
                printf("Please input Correct EVEN data: ");
                scanf("%d", &arr[i]);
            }
        }
    }

    oddIndexSort(arr,size);
    printf("After sorting Odd Indexes: ");
    printArray(arr, size);
    puts("");

    evenIndexSort(arr,size);
    printf("After sorting Even Indexes: ");
    printArray(arr, size);
    puts("");

    // Topic: Searching
    //
    int searchItem;
    // 
    // Linear Search

    printf("Enter number to search\n(Using linear search): ");
    scanf("%d", &searchItem);

    linearSearch(arr, size, searchItem);

    // Binary Search

    printf("Enter number to search\n(Using binary search): ");
    scanf("%d", &searchItem);

    binarSearch(arr, size, searchItem);
}


/*
8
9
4
5
2
7
8
1
6

*/