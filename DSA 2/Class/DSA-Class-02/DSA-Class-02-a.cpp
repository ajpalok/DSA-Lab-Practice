#include<iostream>

using namespace std;

int main(){
    string s1 = "Hello";
    char temp[] = "World";
    string s2 = string(temp);
    s2 += " UIU";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    string s3;

    // cin >> s3;

    getline(cin, s3);

    if (s3 == "Hello"){
        cout << "s3 is Hello" << endl;
    } else {
        cout << "s3 is not Hello" << endl;
    } 

    return 0;
}