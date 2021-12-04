#include <bits/stdc++.h>
using namespace std;
const int MX_SIZE = 100;
int adj[1000][1000];

queue<int> q;
vector<int> from(MX_SIZE, -1);
vector<int> d(MX_SIZE);
vector<int> used(MX_SIZE, 0);

void bfs(int v, int n){
    q.push(v);
    d[v] = 0;
    used[v] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < n; ++i){
            if(adj[x][i] and !used[i]){
                q.push(i);
                used[i] = 1;
            }
        }
    }
}


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }

    int x, y; cin >> x >> y;
    x--; y--;
    bfs(x, n);
    if(used[y]){
        if(!d[y]){
            cout << d[y] << endl;
        }else{
            cout << d[y] << endl;
            vector<int> path;
            for(int i = y; i != -1; i = from[i]){
                path.push_back(i);
            }
            for(int i = 0; i < path.size(); ++i){
                cout << path[path.size() - 1 - i] + 1 << " ";
            }
        }
    }else{
        cout << -1 << endl;
    }
}