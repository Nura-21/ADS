#include <iostream>
#include <cmath>
using namespace std;

void check(long long a, long long b){
    for(int i = -60; i <= 60; ++i){
        if(a * pow(2,i) == b){
            cout << "YES " << i;
            return;
        }
    }

    cout << "NO" << endl;
}

int main(){
    long long a,b;
    cin >> a >> b;
    check(a,b);
}