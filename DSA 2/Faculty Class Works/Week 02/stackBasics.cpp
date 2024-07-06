#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
//    stack<int> st;
//    if(st.empty()) cout << "Empty" << endl;
//    st.push(32); st.push(44); st.push(322);
//    cout << st.top() << endl;
//    st.pop();
//    cout << st.top() << endl;
//    cout << st.size() << endl;
    queue <int> q;
    q.push(264); q.push(242); q.push(100);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;

    return 0;
}

