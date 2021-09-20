#include <iostream>

using namespace std;

int main(){
    int n; cin >> n; 
    int a[n]; 
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int min = 1000;
    int max = -1;
    for(int i=0; i<n; i++){
        if(min > a[i] ){
            min = a[i];
        }
        if(max < a[i]){
            max = a[i];
        }
    }
    for(int i=0; i<n; i++){
        if(a[i] == max){
            a[i] = min;
        }
    }

    for(int i=0; i<n; i++) cout << a[i] << " ";

}