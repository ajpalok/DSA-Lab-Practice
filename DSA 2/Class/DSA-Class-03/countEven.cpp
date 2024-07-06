#include<iostream>
using namespace std;


int countEven(int arr[], int i, int j){
    if (i==j && arr[i]%2 == 0){
        return 1;
    }

    if (i==j && arr[i]%2 != 0){
        return 0;
    }

    // if (i==j)
    //     return (arr[i]%2==0)?1:0;

    int mid = (i+j)/2;
    int leftResult = countEven(arr, i, mid);
    int rightResult = countEven(arr, mid+1, j);

    return leftResult+rightResult;
}

int main(){
    int arr[12] = {1,23,4,5,4,3,342,2,34,5,7,8};

    cout << countEven(arr, 0, sizeof(arr) / sizeof(int));
    return 0;
}