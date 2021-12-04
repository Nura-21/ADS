#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    set<string> a;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        string temp = "";
        for(int j = i; j < s.size(); j++){
            temp += s[i];
            a.insert(temp);
        }
    }
    cout << a.size();
}