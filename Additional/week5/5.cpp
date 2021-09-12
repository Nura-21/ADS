#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n][n];

    bool used[n];
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> arr[i][j];
        }
        used[i] = false;
    }

    queue<int> q;

    for(int i = 0; i < n; ++i){
        if(!used[i]){
            q.push(i);
            used[i] = true;
            while(!q.empty()){
                int cur = q.front();
                cout << cur + 1 << " ";
                q.pop();
                for(int i = 0; i < n; ++i){
                    if(arr[cur][i] == 1 && !used[i]){
                        used[i] = true;
                        q.push(i);
                    }
                }
            }
        }
    }
    

    return 0;
}