#include <iostream>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n,m,k;
        if(n == 1){
            if(m == 0){
                cout << "YES" << endl;
                break;
                
            }else{
                cout << "NO" << endl;
                break;
            }
        }else{
            int min_m = n;
            int max_m = n * (n - 1) / 2;
            if(m < min_m or m > max_m){
                cout << "NO" << endl;
                break;
            }else{
                
            }
        }
    }
}