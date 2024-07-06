#include <iostream>

using namespace std;

struct data{
    string name;
    int height;
    int age;
};
typedef struct data Data;

void swap(Data &a, Data &b){
    Data temp = a;
    a = b;
    b = temp;
}

void sort_by_height(Data d[], int n){
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (d[i].height > d[j].height)
                swap(d[i], d[j]);
}

int main() {
    int n;
    cout << "Enter number of user: ";
    cin >> n;
    Data d[n];

    for (int i = 0; i < n; i++){
        cout << "Enter name, height, age: ";
        cin >> d[i].name >> d[i].height >> d[i].age;
    }

    sort_by_height(d, n);

    for (int i = 0; i < n; i++){
        cout << d[i].name << " " << d[i].height << " " << d[i].age << endl;
    }

    return 0;
}