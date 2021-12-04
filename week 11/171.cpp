#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n][n];
    int inf = INT_MAX/2;
    for(int i = 0;i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int k = 0; k < n; ++k){  
        for(int i = 0;i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][k] < inf && a[k][j] < inf)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }

    for(int i = 0;i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}