#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPrime(ll n) {
    if (n == 1)
        return false;
    for (ll i=2; i*i <= n; i++)
        if (n%i == 0)
            return false;
    return true;
}
int main()
{
    ll a;
    cin >> a;
    if(isPrime(a))
    {
        cout << "prime";
    }
    else
    {
        cout << "composite";
    }
}