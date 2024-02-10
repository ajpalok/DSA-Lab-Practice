// Today we will learn about Searching Algorithms
// Linear Search
// Binary Search

#include <stdio.h>
#include <string.h> // for strlen()

int LinearSearch(int *arr, int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

// Class practice

// Search Employee data where name has a at end and also have salary>500 using stucture

struct Employee{
    char name[20];
    int salary;
};

int EmployeeSearch(struct Employee arr, int size){
    for(int i=0; i<size; i++){
        // check if someone's name ends with 'a' and salary > 500
        if(arr[i]->name[strlen(arr[i]->name)-1] == 'a' && arr[i]->salary > 500){
            return i;
        }
    }
    return -1;
}


int BinarySearch(int *arr, int size, int key){
    int low = 0, high = size-1, mid;
    while(low <= high){
        mid = (low+high)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

// find nearest sqrt in int format in binary search way
int Sqrt(int n){
    int low = 0, high = n, mid, ans;
    while(low <= high){
        mid = (low+high)/2;
        if(mid*mid == n){
            return mid;
        }
        else if(mid*mid < n){
            low = mid+1;
            ans = mid;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {1,2,3,4,5},
        size=sizeof(arr)/sizeof(arr[0]),
        key=3;
    // printf("Linear Search: %d\n", LinearSearch(arr, size, key));
    printf("Binary Search: %d\n", BinarySearch(arr, size, key));

    struct Employee emp[] = {{"Rashed", 500},
                             {"Saddam", 200},
                             {"Rana", 450},
                             {"Mithila", 600},
                             {"Sumaya", 8000}};
    int size_emp = sizeof(emp)/sizeof(emp[0]);

    printf("Employee Search: %d\n", EmployeeSearch(emp, size_emp));

    printf("Sqrt: %d\n", Sqrt(10));

    return 0;
}