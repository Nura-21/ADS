#include <bits/stdc++.h>
using namespace std;

bool postfix(string s, string t){
    if (t.size() > s.size()) return false;
    return (s.substr(s.size() - t.size(), t.size()) == t);
}

int main(){

    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }
    while(m--){
        string temp;
        cin >> temp;
        int cnt = 0;
        for (int i = 0; i < v.size(); ++i){
            if (postfix(v[i], temp)) cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}