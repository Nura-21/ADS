#include <iostream>

using namespace std;

void linear_seacrh(int a[], int x, int size){
    for(int i = 0; i < size; ++i){
        if(a[i] == x){
            cout << i + 1 << " ";
        }
    }
}

int main(){
    int n; cin >> n; 
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int k; cin >> k;
    linear_seacrh(a,k,n);
}