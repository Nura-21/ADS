#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[100];
int used[100];
int d[100];

int n, m, x, y;

void bfs(int v){
    queue<int> q;
    used[v] = true;
    d[v] = 0;
    q.push(v);
    while(!q.empty()){
        int x = q.front();
        for(int i = 0; i < adj[x].size(); ++i){
            int y = adj[x][i];
            if(used[y] == 0){
                q.push(y);
                used[y] = true;
                d[y] = d[x] + 1;
            }
        }
        q.pop();
    }
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(0);
    for(int i = 0; i < n; ++i){
        cout << i + 1<< " " << d[i] << endl;
    }
}