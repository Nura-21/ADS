#include <iostream>
using namespace std;
int flag,n;

int dfs(int i, int l1[], int l2[]){
    l2[i] += 1;
    if(l2[i] == 2){
        cout << i + 1 << " ";
        flag = 0;
    }
    if(i > n){
        return -100;
    }
    while(flag == 1){
        dfs(l1[i] - 1, l1,l2);
    }
}

int main(){
    cin >> n; 
    int l1[1005],l2[1005];

    for(int i = 0; i < n; i++){
        cin >> l1[i];
    }

    for(int i = 0; i < n; i++){
        flag = 1;
        dfs(i,l1,l2);
    }
} 
