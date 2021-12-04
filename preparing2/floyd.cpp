#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    int a[n][n];
    int inf = INT_MAX/2;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
            if(a[i][j] == 0){
                a[i][j] = inf;
            }
        }
    }

    for(int k = 0; k < n; ++k){
         for(int i = 0; i < n; ++i){
             for(int j = 0; j < n; ++j){
                 if(a[i][k] < inf && a[k][j] < inf)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
             }
         }
    }
    cout << endl;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] == inf){
                cout << 0 << " ";
            }else{
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}