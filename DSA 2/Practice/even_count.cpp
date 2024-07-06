#include <iostream>
using namespace std;

int countEven(int Arr[], int i, int j){
    if (i==j){ // Base-Case
        if (Arr[i]%2 == 0) return 1;
        else return 0;
    }

    int mid = (i+j)/2;

    // int leftResult = countEven(Arr, i, mid);
    // int rightResult = countEven(Arr, mid+1, j);

    // return leftResult + rightResult;

    return countEven(Arr, i, mid) + countEven(Arr, mid+1, j);
}

int main(){
    int arr[10] = {1,2,3,4,5,6,8,9,10,6},
        end = sizeof(arr)/sizeof(int);

    int result = countEven(arr, 0, end-1);

    cout << result;
    return 0;
}