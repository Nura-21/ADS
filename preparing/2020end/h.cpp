#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s)
{
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
    string s; cin >> s;
    int n; cin >> n;
    vector<vector<int>> v; 
    vector<string> v1;
    for(int i = 0; i < n; ++i){
        string c; cin >> c;
        v1.push_back(c);
        v.push_back(prefix_function(c + "#" + s));
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < v[i].size(); ++j){
            if(v[i][j] == v1[i].substr(0,j).size() ){
                cnt++;
            }
        }
    }
    cout << cnt;
}