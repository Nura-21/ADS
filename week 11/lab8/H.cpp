#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
const int MX_SIZE = 1000;
vector<int> g[MX_SIZE];
vector<int> ans;
vector<int> used(MX_SIZE, 0);

void dfs(int v){
    used[v] = 1;
    for(int i = 0; i < g[v].size(); ++i){
        int y = g[v][i];
        if(used[y] == 1){
            cout << "No";
            exit(0);
        }else{
            dfs(y);
        }
    }
    ans.push_back(v);
    used[v] = 2;
}

int main(){

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0);
    for(int i = 1; i < n; ++i){
        if(!used[i]){
            dfs(i);
        }
    }

    cout << "Yes" << endl;
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[ans.size() - 1 - i] + 1 << " ";
    }
}