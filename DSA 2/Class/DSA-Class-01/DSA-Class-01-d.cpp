#include <bits/stdc++.h> // This is a header file which includes every standard library
using namespace std;

typedef struct Person {
    string name;
    int age;
    int height;
} Person;

bool compare(Person a, Person b) {
    return a.height < b.height;
}

int main() {
    Person p[5];
    for (int i = 0; i < 5; i++) {
        cout << "Enter name, age, height: ";
        cin >> p[i].name >> p[i].age >> p[i].height;
    }

    sort(p, p + 5, compare);

    for (int i = 0; i < 5; i++) {
        cout << p[i].name << " " << p[i].age << " " << p[i].height << endl;
    }

    return 0;
}