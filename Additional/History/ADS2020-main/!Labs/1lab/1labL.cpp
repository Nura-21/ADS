#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    long long np = n;
    long long kp = k;
    long long cnt = 0;
    do
    {
        cnt++;
        n++;
        k++;
    } while ((n % np != 0) or (k % kp != 0));
    cout << cnt;
    return 0;
}