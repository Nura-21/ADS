#include<bits/stdc++.h>
using namespace std;
const int MX = 10000;
vector<int> g[MX];
vector<bool> used(MX, 0);
vector<int> ans;
void dfs(int v){
    used[v]=1;
    for(int i=0; i<g[v].size(); i++){
        int u = g[v][i];
        if(used[u]==0)
            dfs(u);
    }
    ans.push_back(v);
}
int main()
{
    int nodes, edges;
    while(cin >> nodes >> edges, nodes!=0 || edges!=0){
        for (int i = 0; i < edges; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        for(int i=1; i<=nodes; i++){
            if(used[i]==0)
                dfs(i);
        }
        for(int i=nodes-1; i>=0; i--){
            cout<<ans[i] << " ";
        }
        cout<<endl;
    }
    return 0;
}
