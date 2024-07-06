#include <iostream>

using namespace std;

int main(){
    string s = "Thank_you_very_very_much_very_much.";
    string p = "very";
    cout << p.length() << endl;
    string res;
    int next_occ;
    int focc = s.find(p);
    if(focc == string::npos) res = s;
    else{
        res = s.substr(0, focc+p.length());
        cout << res << endl;
        next_occ = s.find(p, focc+p.length());
        cout << focc << " " << next_occ << endl;
        while(next_occ != string::npos){
            cout << focc << " " << next_occ << endl;
            string tmp = s.substr(focc+p.length(), next_occ);
            res += tmp;

            cout << tmp << endl;

            focc = next_occ;
            next_occ = s.find(p, focc+p.length());

        }
        res += s.substr(focc+p.length());
    }
    cout << res << endl;
    return 0;
}

