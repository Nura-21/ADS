#include <bits/stdc++.h>
using namespace std;
#define mx 100000
vector<bool> used(mx, false);
vector<int> g[mx];
vector<int> comp[mx];
int comp_cnt = 0;

void dfs(int v){
    used[v] = true;
    comp[comp_cnt].push_back(v);
    for(int i = 0; i < g[v].size(); ++i){
        int y = g[v][i];
        if (!used[y])
            dfs(y);
    }
}

int main(){
    int n, m, x, y; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i = 0; i < n; ++i){
        if(used[i] == 0){
            dfs(i);
            comp_cnt++;
        }
    }

    cout << comp_cnt << endl;
    for(int i = 0; i < comp_cnt; ++i){
        cout << comp[i].size() << endl;
        for(int j = 0; j < comp[i].size(); ++j){
            cout << comp[i][j] + 1 << " ";
        }
        cout << endl;
    }

    
}
