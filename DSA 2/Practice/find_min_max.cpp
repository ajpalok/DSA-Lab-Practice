#include <iostream>
using namespace std;

pair<int, int> find_min_max(int Arr[], int i, int j){
    if (i==j)
        return pair <int, int> (Arr[i], Arr[i]);

    int mid = (i+j)/2;
    pair <int, int> leftData = find_min_max(Arr, i, mid);
    pair <int, int> rightData = find_min_max(Arr, mid+1, j);

    // combine
    pair<int, int> returnValue;

    if (leftData.first < rightData.first)
        returnValue.first = leftData.first;
    else
        returnValue.first = rightData.first;

    if (leftData.second > rightData.second)
        returnValue.second = leftData.second;
    else
        returnValue.second = rightData.second;

    return returnValue;
}

int main(){
    int arr[10] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(int);

    pair<int, int> result = find_min_max(arr, 0, size-1);

    cout << "Min: " << result.first << endl << "Max: " << result.second;
    return 0;
}