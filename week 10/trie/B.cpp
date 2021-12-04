#include <bits/stdc++.h>
using namespace std;


int main(){
    string s; cin >> s;
    int n ; cin >> n;
    for(int i = 0; i < n; ++i){
        string t; cin >> t;
        vector<int> v;
        int cnt = 0;
        int index = s.find(t,0);
        while(index <= s.size() or index != -1){
            v.push_back(index+1);
            cnt++;
            index = s.find(t, index + 1);
        }
        v.insert(v.begin(), cnt);
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
}