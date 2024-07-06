#include <iostream>

using namespace std;

int main(){
    string s1 = "Hello";
    char tmp[] = "World";
    string s2 = string(tmp);
    s2 +=  " UIU.";
    cout << "s2: " << s2 << endl;
    cout << s1 << " " << s2 << endl;

    string s3;
    getline(cin, s3);
    if (s3 > "a") cout << "s3 greater than a" << endl;
    else cout << "s3 less than a" << endl;
    cout << "s3: " << s3 << endl;
    return 0;
}
