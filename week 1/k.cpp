#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(int n) {
    if (n == 1) {
        return false;
    }

    int i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }
    return true;
}
int main(){
    long long n;
    cin >> n;
    if(is_prime(n)){cout<<"prime";}
    else{cout<<"composite";}
}