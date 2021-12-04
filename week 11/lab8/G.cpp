#include <bits/stdc++.h>
#define ll long long
using namespace std;
int used[1000][1000];
int cnt = 0;

void dfs(int i, int j){
    if(used[i][j] == 0){
        return;
    }
    used[i][j] = 0;
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

int main(){
    int n, m; 
    cin >> n >> m;
    for(int i = 0; i < n + 2; ++i){
        for(int j = 0; j < m + 2; ++j){
            used[i][j] = 0;
        }
    }

    for(int i = 1 ; i <= n; ++i){
        for(int j = 1 ; j <= m; ++j){
            char c; cin >> c;
            used[i][j] = (c == '.' ? false : true);
        }
    }

    for(int i = 1 ; i <= n; ++i){
        for(int j = 1 ; j <= m; ++j){
            if(used[i][j] != 0){
                cnt++;
                dfs(i,j);
            }
        }
    }

    cout << cnt;
}