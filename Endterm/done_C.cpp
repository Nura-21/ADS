#include <bits/stdc++.h>
#define MX 100000
using namespace std ;
int n, m;
vector<bool> used(MX);
vector<int> g[MX];
vector<int> ans;
bool ok = false;

void dfs(int v){
    used[v] = 1;
    for(int i = 0; i < g[v].size(); ++i){
        int to = g[v][i];
        if(used[to] == 0){
            ans.push_back(to);
            dfs(to);
            if(ok == true){
                return;
            }    
        }
        else if(used[to] == 1){
            ok = true;
            return;
        }
    }
    ans.pop_back();
    used[v] = 2;
}
void dfs(int v, int l, int r){
    used[v] = 1;
    for(int i = 0; i < g[v].size(); ++i){
        int to = g[v][i];
        if(v == l && to == r)
            continue;
        if(used[to] == 0){
            dfs(to, l, r);
            if(ok == true){
                return;
            }
        }
        else if(used[to] == 1){
            ok = true;
            return;
        }
    }
    used[v] = 2;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        if(x == y){
            ans.push_back(x);
            ans.push_back(y);
            ok = true;
        }
    }
    if(!ok) {
        for(int i = 0; i < n; ++i) {
            if(!used[i]) {
                ans.push_back(i);
                dfs(i);
                if(ok == true) {
                    break;
                }
            }
        }
    }
    if(!ok){
        cout << "YES";
        return 0;
    }
    for(int j = 1; j <= ans.size(); ++j){
        int l = ans[j - 1], r = ans[j];
        ok = false;
        for(int i = 0; i < n; ++i){ 
            used[i] = 0;
        }
        for( int i = 0; i < n; ++i){
            if(!used[i]){
                dfs(i, l, r);
                if(ok){
                    break;
                }
            }
        }
        if(!ok){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}