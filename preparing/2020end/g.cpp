#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("input.txt", "r",stdin);
    string s; cin >> s; 
    int n; cin >> n;
    vector<string> v;
    for(int i = 0; i < n; ++i){
        string c; cin >> c;
        if(s.find(c) != -1){
            v.push_back(c);
        }
    }

    // for(auto i : v){
    //     cout << i << " ";
    // }

    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < v.size(); ++j){
            if(s == v[i] + v[j]){
                cout << "YES";
                exit(0);
            }
        }
    }
    cout << "NO";
}