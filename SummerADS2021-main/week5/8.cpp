#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

int main(){

    int n;
    cin >> n;
    
    int arr[n][n];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> arr[i][j];
            if(arr[i][j] == 0){
                arr[i][j] = INF;
            }
        }
    }

    int s, t;
    cin >> s >> t;
    s--;
    t--;


    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }

    cout << a[s][t] << endl;

   

    return 0;
}