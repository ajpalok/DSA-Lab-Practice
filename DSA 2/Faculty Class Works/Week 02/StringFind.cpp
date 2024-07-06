#include <iostream>

using namespace std;

int main(){
    string s1 = "Yes, we went to Gates after we left the dorm.";
    int first_occ = s1.find("we");
    int sec_occ = s1.find("we", first_occ+1);
    int Gpos = s1.find('G');
    int zpos = s1.find('z');
    if(zpos == string::npos) cout << "z not found." << endl;
    cout << zpos << endl;

    string old_s = "Thank_you_very_very_much.";
    cout << old_s << endl;
    string new_s = old_s.substr(0,old_s.find("very"));
    cout << new_s << endl;
    cout << new_s + old_s.substr(old_s.find("very")+5) << endl;
    return 0;
}
