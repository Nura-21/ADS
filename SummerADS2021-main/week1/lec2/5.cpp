#include <iostream>

using  namespace  std;

int bp(int a, int n){
    if(n == 0) return 1;
    if(n % 2 == 1) return a * bp(a, n - 1);
    else {
        int b = bp(a, n / 2);
        return b * b;
    }
}

int main() {

    int a, n;
    cin >> a >> n;

    cout << bp(a, n) << endl;

    return 0;
}
