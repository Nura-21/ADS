#include <bits/stdc++.h>
using namespace std;
#define MX 200

vector<int> g[MX];
vector<bool> used(MX, false);
int cnt = 0;

void dfs(int v){
    used[v] = true;
    cnt++;
    for (int i = 0; i < g[v].size(); i++){
        int y = g[v][i];
        if (!used[y])
            dfs(y);
    }
}

int main(){
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int t;
            cin >> t;
            if (t != 0)
                g[i].push_back(j);
        }
    }
    dfs(m - 1);
    cout << cnt;
}