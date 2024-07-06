#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int array_reverse(int arr[], int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    return 0;
}

int array_reverse_recursive(int arr[], int start, int end) {
    if (start >= end) return 0;
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    array_reverse_recursive(arr, start + 1, end - 1);
    return 0;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;

    int arr[] = {1, 2, 3, 4, 5};
    array_reverse(arr, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    

    return 0;
}