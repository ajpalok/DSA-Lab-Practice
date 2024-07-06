#include <iostream>

using namespace std;

int pow_dc(int x, int y){
    if( y == 0) return 1;
    int ret = pow_dc(x, y/2);

    if(y%2 == 0) return ret*ret;
    else return x*ret*ret;



}

int main(){
    int x, y;
    cin >> x >> y;
    cout << pow_dc(x,y) << endl;
    return 0;
}
