// {10, 32, 12, 52, 43, 51}
// after descending order sort at odd position = {10, 52, 12, 51, 43, 32}
// Print kth odd position value after sort

#include<iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end){
    int size_1 = mid-start+1,
        size_2 = end - mid;

    int arr_1[size_1];
    int arr_2[size_2];

    for (int i=0; i<size_1; i++)
        arr_1[i] = arr[start+i];

    for (int i=0; i<size_2; i++)
        arr_2[i] = arr[mid+1+i];
    
    int i=0, j=0;

    if (start%2==0){
        i=1;
    }

    if ((mid+1)%2==0){
        j=1;
    }

    int k = start+i;

    while (i<size_1 && j<size_2){
        if (arr_1[i] <= arr_2[j]){
            arr[k]=arr_2[j];
            j+=2;
        }
        else{
            arr[k]=arr_1[i];
            i+=2;
        }
        k+=2;
    }

    // remaining left sides
    while(i<size_1){
        arr[k]=arr_1[i];
        i+=2;
        k+=2;
    }

    // remaining right sides
    while(j<size_2){
        arr[k]=arr_2[j];
        j+=2;
        k+=2;
    }
}

void sort(int *arr, int start, int end){
    if (start==end)
        return;
    int mid = (start + end)/2;
    sort(arr, start, mid);
    sort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(){
    int size;
    cout << "Enter the size: ";
    cin >> size;

    int arr[size];
    cout << "Enter the values of the data: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    // Call the sort function
    sort(arr, 0, size-1);

    for (int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;

    int position;
    cout << "Enter Kth odd position: ";
    cin >> position;

    if (2*position-1<size)
        cout << "Value in position " << position << " is: " << arr[2*position-1];
    else
        cout << "position invalid";

    return 0;
}

/*
6
10 32 12 52 43 51
2

*/