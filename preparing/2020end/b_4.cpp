#include <bits/stdc++.h>
using namespace std;

vector<long long> prefix_function(string s)
{
    long long n = s.size();
    vector<long long> p(n);
    for (int i = 1; i < n; i++)
    {
        long long j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

int main(){   
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt","w", stdout);
    long long n, m; cin >> n >> m;
    
    vector<string> v1(n);
    vector<string> v2(m);
    for(long long i = 0; i < n; i++){
        cin >> v1[i];
    }
    for(long long i = 0; i < m; i++){
        cin >> v2[i];
    }

    for(long long i = 0; i < m; i++){
        long long cnt = 0;
        for(long long j = 0; j < n; j++){
            //cout << v2[i] + "#" + v1[j].substr(v1[j].size() - v2[i].size(), v2[i].size()) << " ";
            vector<long long> temp = prefix_function((v2[i] + "#" + v1[j].substr(v1[j].size() - v2[i].size(), v2[i].size())));
            if(temp[temp.size() - 1] == v2[i].size()){
                cnt ++;
            }
        }
        cout << cnt << endl;
    }
    
}