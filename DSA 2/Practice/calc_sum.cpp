#include <iostream>
using namespace std;

int calc_sum(int arr[], int start, int end){
    if (start == end) return arr[end]; //BaseCase

    return arr[start] + calc_sum(arr, start+1, end);
}

int main(){
    int arr[13] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);

    cout << calc_sum(arr, 0, size-1);

    return 0;
}
