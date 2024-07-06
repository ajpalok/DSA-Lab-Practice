#include <iostream>
using namespace std;

void print_odd(int arr[], int start, int end){
    if (start > end) return;

    if (arr[start] % 2 != 0)
        cout<< arr[start] << " ";

    print_odd(arr, start+1, end);
}

int main(){
    int arr[13] = {1,2,3,4,5,6,7,8,9,91,7,76,0};
    int size = sizeof(arr)/sizeof(int);

    print_odd(arr, 0, size-1);

    return 0;
}
