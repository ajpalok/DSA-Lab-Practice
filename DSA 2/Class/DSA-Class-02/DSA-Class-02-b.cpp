#include<iostream>

using namespace std;

int main(){
    string s1 = "Yes we went to Gates after we went to the park";

    int first_we = s1.find("we");
    cout << "First we: " << first_we << endl;

    int second_we = s1.find("we", first_we + 1);
    cout << "Second we: " << second_we << endl;

    int third_we = s1.find("we", second_we + 1);
    cout << "Third we: " << third_we << endl;

    int last_we = s1.rfind("we");
    cout << "Last we: " << last_we << endl;

    int find_z = s1.find("z");
    cout << "Find z: " << find_z << endl;

    if (find_z == string::npos){
        cout << "z not found" << endl;
    } else {
        cout << "z found at: " << find_z << endl;
    }

    string old_s = "Thank you very very much";
    cout << "Old string: " << old_s << endl;

    int found = old_s.find("very");

    old_s.replace(found, 4, "much"); // replace 4 characters from found with "much"
    cout << "Replaced Old string: " << old_s << endl;

    string new_s = old_s.substr(0, found); // from 0 to found - 1
    cout << "New string: " << new_s << endl;

    new_s += old_s.substr(found + 5); // from found + 5 to end
    cout << "New string: " << new_s << endl;

    string s = "Thank_you_very_very_much_very_much";
    cout << "S: " << s << endl;
    string p = "very";
    string res;

    int first_occourance = s.find(p);
    int next_occourance;

    if (first_occourance != string::npos){
        res = s;
    }
    else {
        res = s.substr(0, first_occourance+p.length());
        next_occourance = s.find(p, first_occourance+p.length());
        while (next_occourance != string::npos){
            res += s.substr(first_occourance+p.length(), next_occourance);
            first_occourance = next_occourance;
            next_occourance = s.find(p, first_occourance+p.length());
        }
        res += s.substr(first_occourance+p.length());
    }

    cout << "Res: " << res << endl;

    return 0;
}