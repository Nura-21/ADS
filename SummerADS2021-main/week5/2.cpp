#include <iostream>
#include <vector>

using namespace std;


int main(){

    int n;
    cin >> n;
    
    int arr[n][n];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int a, b;
    cin >> a >> b;

    if(arr[a-1][b-1] == 1){
        cout << "YES";
    }else{
        cout << "NO";       
    }


    return 0;
}