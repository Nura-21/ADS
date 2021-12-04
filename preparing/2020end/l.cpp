#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("input.txt", "r",stdin);
    //freopen("output.txt", "w",stdout);

    string s; cin >> s; 
    vector<bool> v; 
    for(int i = 0; i < s.size() ; ++i){
        v.push_back(false);
    }
    
    int n; cin >> n;

    for(int i=0; i < n ; ++i){
        string t; cin >> t;
        int index = s.find(t,0);
        while(index <= s.size() or index != -1){
            for(int j = index; j < index + t.size(); ++j){
                v[j] = true;
            }
            index = s.find(t,index + 1);
        }
    }

    
    vector<bool> :: iterator it = find(v.begin(), v.end(), 0);
    if(it != v.end()){
        cout << "NO";
    }else{
        cout << "YES";
    }
}