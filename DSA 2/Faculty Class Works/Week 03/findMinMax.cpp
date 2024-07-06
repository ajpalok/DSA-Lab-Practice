#include <iostream>

using namespace std;

pair<int, int> findMaxMin(int a[], int i, int j){
    //Base Case
    if(i == j){
        return pair<int, int>(a[i], a[i]);

    }

    // Divide
    int mid = (i+j)/2;
    pair<int, int> left = findMaxMin(a, i, mid);
    pair<int, int> right = findMaxMin(a, mid+1, j);
    //----------------------------------------------

    // Combine
    pair<int, int> ret;
    if(left.first > right.first) ret.first = left.first;
    else ret.first = right.first;

    if(left.second < right.second) ret.second = left.second;
    else ret.second = right.second;

    return ret;

}

int main(){
    int a[100];
    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    pair<int, int> ret = findMaxMin(a, 0, n-1);
    cout <<  ret.first << " " << ret.second << endl;


    return 0;
}
