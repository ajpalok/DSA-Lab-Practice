#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main(){
    map <string, float> m;
    m["s1"] = 2.35;
    m["s2"] = 3.5;
    m["s3"] = 3.8;
    m.insert(pair<string, float>("s3", 4.00));
    cout << m.size() << endl;
//    m.find("s3")->pointer;
    if(m.find("s3") == m.end()) cout << "not found." << endl;
    else cout << m["s3"] << endl;

}
