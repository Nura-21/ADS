#include <bits/stdc++.h>
using namespace std;

string concat(string &s, string &t){
    int i = min(s.size(), t.size()), cnt = i;
    while(s.substr(s.size() - i, i) != t.substr(0, i)){
        cnt = --i;
    }
    while(cnt--){
        t.erase(0, 1);
    }
    return s + t;
}


int main(){

    // freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    cout << concat(s, t);

    return 0;
}