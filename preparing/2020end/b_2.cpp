#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r",stdin);
    // freopen("output.txt", "w",stdout);
    int n, m;
    cin >> n >> m;
    vector<string> v1;

    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        v1.push_back(s);
    }
    
    for(int i = 0; i < m; ++i){
        int cnt = 0;
        string t; cin >> t;
        for(int j = 0; j < n ; ++j){
            int tsz = v1[j].size();
            //cout << v1[j].substr(tsz - sz , sz) << " ";
            if(v1[j].substr(tsz - t.size(), t.size()) == t and t.size() <= tsz){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}