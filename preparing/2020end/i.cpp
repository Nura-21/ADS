#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r",stdin);
    // freopen("output.txt", "w",stdout);
    int n, m;
    cin >> n >> m;
    string v1[n];
    string v2[m];
    for(int i = 0; i < n; ++i){
        cin >> v1[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> v2[i];
    }
    
    vector<bool> v3(m, false);
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n ; ++j){
            if(v2[i].substr(0,v1[j].size()) == v1[j] and v2[i].size() != v1[j].size()){
                v3[i] = true;
                break;
            }
        }
    }

    for(auto i : v3){
        cout << (i ? "YES\n" : "NO\n");
    }
}