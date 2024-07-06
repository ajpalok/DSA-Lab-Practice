#include <iostream>
using namespace std;

int power(int a, int b){
    if (b==0) return 1;
    if (b==1) return a;
    return a * power(a, b-1);
}

int main(){
    int x = 3, y = 2;
    cout << "Result: " << power(x, y);
    return 0;
}