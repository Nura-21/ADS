#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> p(n);
    for (int i = 1; i < n; i++)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}


int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        string t; cin >> t;
        s = t + "#" + s;
        vector<int> p = prefix_function(s);
        vector<int> ans;
        int cnt = 0;
        for(int j = 0; j < p.size(); j++){
            if(p[j] == t.size()){
                cnt++;
                ans.push_back(j + 1 - t.size() * 2);
            }
        }
        if(cnt == 0){
            cout << "Not Found" << endl;
        }else{
            cout << cnt << endl;
            for(auto i : ans){
                cout << i << " ";
            }
            cout << endl;
        }
    }
}