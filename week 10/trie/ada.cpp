#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    while(n--){
        string s;
        set<string> a;
        int k,m; cin >> m >> k;
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            string temp = "";
            for(int j = i; j < s.size(); j++){
                temp += s[j];
                a.insert(temp);
            }
        }
        int cnt = 0;
        for(auto i : a){
            if(i.size() == k){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}