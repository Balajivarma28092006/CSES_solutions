#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

void dosomething(int index, string &s, set <string> &ans){
    if(index ==  s.size()){
        ans.insert(s);
        return;
    }

    for (int i = index; i < s.size(); i++){
        swap(s[index], s[i]);
        dosomething(index + 1, s, ans);
        swap(s[index], s[i]);
    }
}

set<string> getAll(string &c){
    set<string> res;
    dosomething(0, c, res);
    return res;
}

int main() {
    string c;
    cin >> c;
    set<string>res = getAll(c);
    cout << res.size() << "\n";
    for (string s : res) cout << s << "\n";
    return 0;
}

/*
 * found this thing after doing this: we can use std::next_permutation(begin, end)
 * which returns bool so the usage can be do {} while(next_permutation);
 */
