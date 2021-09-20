#include <iostream>

using namespace std;

int get_max(int a[], int n){
    int max = -100000;
    int index = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= max){
            max = a[i];
            index = i;
        }
    }
    return index + 1;
}
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << get_max(a, n);
}