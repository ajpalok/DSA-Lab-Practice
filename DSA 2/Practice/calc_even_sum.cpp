#include <iostream>
using namespace std;

int calc_even_sum(int arr[], int start, int end){
    if (start == end){
        if (arr[end] % 2 == 0)
            return arr[end]; //BaseCase
        else
            return 0;
    }

    if (arr[start] % 2 == 0)
        return arr[start] + calc_even_sum(arr, start+1, end);
    else
        return calc_even_sum(arr, start+1, end);
}

int main(){
    int arr[13] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);

    cout << calc_even_sum(arr, 0, size-1);

    return 0;
}
