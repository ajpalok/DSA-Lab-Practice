#include<iostream>
using namespace std;

// use pair to find minimum maximum

pair<int, int> findMinMax(int arr[], int n) {
    pair<int, int> minMax;
    if (n == 1) {
        minMax.first = arr[0];
        minMax.second = arr[0];
        return minMax;
    }
    if (arr[0] > arr[1]) {
        minMax.first = arr[1];
        minMax.second = arr[0];
    } else {
        minMax.first = arr[0];
        minMax.second = arr[1];
    }
    for (int i = 2; i < n; i++) {
        if (arr[i] > minMax.second) {
            minMax.second = arr[i];
        } else if (arr[i] < minMax.first) {
            minMax.first = arr[i];
        }
    }
    return minMax;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    pair<int, int> minMax = findMinMax(arr, n);
    cout << "Minimum element is " << minMax.first << endl;
    cout << "Maximum element is " << minMax.second << endl;
    return 0;
}