#include<iostream>
using namespace std;


int calcPower(int x, int y){
    if (y == 0) return 1;
    if (y == 1) return x;
    return x*calcPower(x, --y);
}

int main(){
    int x = 3, y = 0;
    cout << "Result: " << calcPower(x, y);
    return 0;
}