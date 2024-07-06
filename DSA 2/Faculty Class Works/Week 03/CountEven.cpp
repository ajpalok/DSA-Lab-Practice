#include <iostream>

using namespace std;

int countEven(int a[], int i, int j){
    if(i == j){
        return (a[i]%2 == 1) ? 0 : 1; // a[i] in place of 1 for evenSum

    }
    int mid = (i+j)/2;
    return countEven(a, i, mid) + countEven(a, mid+1, j);
}

int main(){
    int a[100];
    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    cout << countEven(a, 0, n-1) << endl;


    return 0;
}
