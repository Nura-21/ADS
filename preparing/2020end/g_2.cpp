#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int n ; cin >> n;
    for(int i=0; i<n; i++){
        string c; cin >> c;
        //cout << c << " ";
        if(s.find(c) != -1){
            s = s.substr(s.find(c) + c.size(), s.size() - c.size());
        }
    }
    if(s.empty()){
        cout << "YES";
    }else{
        cout << "NO";
    }
}