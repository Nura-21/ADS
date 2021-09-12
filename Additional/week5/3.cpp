#include <iostream>
#include <vector>

using namespace std;

int arr[100][100];

int color[100];
//0-white
//1-gray
//2-black
int n;

void dfs(int v){
    if(color[v] == 0){
        cout << v + 1 << " ";
        color[v] = 1;
        for(int i = 0; i < n; ++i){
             if(arr[v][i] == 1 && color[i] == 0){
                 dfs(i);
             }
        }
        color[v] = 2;
    }
}

int main(){

    cin >> n;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> arr[i][j];
        }
        color[i] = 0;
    }

    dfs(0);
    

    return 0;
}