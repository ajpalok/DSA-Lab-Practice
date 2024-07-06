#include<iostream>
#include<stack>
#include<map>

using namespace std;

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    s.pop();

    cout << "Top: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl;

    cout << "pop all: ";
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    map<string, float> m;

    m["s1"]=2.35;
    m["s2"]=3.5;
    m["s3"]=4.5;

    m.insert(pair<string, float>("s4", 5.5));

    m.find("s2");
    
    if (m.find("s2") != m.end()){
        cout << "Found s2" << endl;
    } else {
        cout << "Not found s2" << endl;
    }

    cout << "size: " << m.size() << endl;

    return 0;
}