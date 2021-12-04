#include <bits/stdc++.h>
using namespace std;

int main(){
    string t;
    string s = "abc";
    while(cin >> t){
        if(t == "."){
            break;
        }else{
            
            int mx = -1;
            for(int i = 0; i < t.size(); ++i){
                string part = t.substr(0, i + 1);
                //cout << part << " ";
                if(part.size() < s.size()){
                    int cnt = 0;
                    int index = 0;
                    if(s.find(part, index) != -1){
                        while(index <= s.size() or index != -1){
                            if(s.find(part, index)){
                                cnt++;
                                index = s.find(part, index + 1);
                            }
                        }
                    }
                    if(mx < cnt){
                        mx = cnt;
                    }
                }
                //cout << endl;
            }
            cout << mx << endl;
        }
    }
}