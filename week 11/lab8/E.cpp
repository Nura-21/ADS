#include <bits/stdc++.h>
using namespace std;
#define mx 101
vector<int> gr[mx];
vector<bool> used(mx, false);

void dfs(int v, int parent){
    used[v] = true;
    for(int i = 0; i < gr[v].size(); i++){
        int y = gr[v][i];
        if(used[y] and y != parent){
            cout << "NO";
            exit(0);
        }else if(!used[y]){
            dfs(y,v);
        }
    }
}

int main(){
    int n; cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x; cin >> x;
            if(x != 0){
                gr[i].push_back(j);
            }
        }
    }

    dfs(0, -1);
    for(int i =0; i < n; i++){
        if(!used[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    


}
