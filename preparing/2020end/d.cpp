#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("input.txt", "r",stdin);
    string t,s;
    cin >> t >> s;
    int cnt = 0;
    int mx_cnt = 0;
    int index = s.find(t);
    //cout << index << endl;
    if(index == -1){
        cout << 0 << endl;
        return 0;
    }
    while(index <= s.size() - t.size() and index != -1){
        if(s.substr(index, t.size()) == t ){
            cnt++;
            if(mx_cnt < cnt) mx_cnt = cnt;
            index += t.size();
        }else{
            cnt = 0;
            index++;
        }
    }

    cout << mx_cnt;

}