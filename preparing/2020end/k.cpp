#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    char ss, tt;
    string f = "", se = "";
    int n,m;
    for(int i = 0; i < s.size(); ++i){
        if(isupper(s[i])){
            ss = s[i];
            n = i + 1;
        }
        if(isupper(t[i])){
            tt = t[i];
            m = i + 1;
        }
    }

    // for(int i = 0; i < s.size(); ++i){
    //     if(isupper(s[i])){
    //         ss = s[i];
    //         n = i + 1;
    //     }
    //     if(isupper(t[i])){
    //         tt = t[i];
    //         m = i + 1;
    //     }
    // }
    for(int i = n; i < s.size(); ++i){
        f += s[i];
    }
    for(int i = m; i < t.size(); ++i){
        se += t[i];
    }
    if(ss != tt){
        cout << "NO" << endl;
    }else{
        if(f == se){
            cout << "YES";
        }else{
            cout << "NO";
        }
    }
}