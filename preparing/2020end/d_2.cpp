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

int main()
{
    string s, t;
    cin >> t >> s;
    s = t + '#' + s;
    vector<int> p = prefix_function(s);
    int cnt = 0;
    int mx = 0;

    // for(auto i : p){
    //     cout << i << " ";
    // }
    // cout << endl;

    for (int i = 0; i <= s.size(); i += t.size())
        if (p[i] == t.size()){
            cnt++;
            if(mx < cnt){
                mx = cnt;
            }
        }else{
            cnt = 0;
        }
    cout << mx;
}