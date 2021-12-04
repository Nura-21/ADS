#include <bits/stdc++.h>
using namespace std;
#define mx 101
vector<int> g[mx];
vector<int> color(mx, 0); 
int cnt = 0;
bool ans = true;

void dfs(int v, int clr){
    color[v] = clr;
    for(int i = 0; i < g[v].size(); i++){
        int y = g[v][i];
        if(!color[y]){
            dfs(y,3 - clr);
        }else{
            if(color[y] == clr){
                ans = false;
            }
        }
    }
}


int main(){
    int n, m; cin >> n >> m;
    for(int i=0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, 1);

    for(int i = 0; i < n; i++){
        if(!color[i]){
            dfs(i, 1);
        }
    }

    if(ans){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            if(color[i] == 1){
                cout << i + 1 << " ";
            }
        }
    }else{
        cout << "NO";
    }
}