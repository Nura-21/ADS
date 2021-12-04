#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n][n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }

    int v1 = 0, v2 = 0, v3 = 0;
    int mn = INT_MAX;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                int total = a[i][j] + a[j][k] + a[k][i];
                if(total < mn and a[i][j] and a[j][k] and a[k][i]){
                    mn = total;
                    v1 = i;
                    v2 = j;
                    v3 = k;
                }
            }
        }
    }

    cout << v1 + 1 << " " << v2 + 1 << " " << v3 + 1;
}