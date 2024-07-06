#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "Size: " << v.size() << endl;
    v.pop_back();

    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Max Size: " << v.max_size() << endl;

    v.push_back(60);
    cout << "Size: " << v.size() << endl;
    for (int i : v){
        cout << v[i] << " ";
    }

    v.erase(v.begin() + 2);
    v.erase(v.end() - 1);

    v.pop_back();
    cout << endl;
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}