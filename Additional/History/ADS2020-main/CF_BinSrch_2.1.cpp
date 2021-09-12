#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

bool good(ll w, ll h, ll n, ll m)
{
    return (m / w) * (m / h) >= n;
}

int main()
{
    ll w, h, n;
    cin >> w >> h >> n;
    ll l = 0; // not include
    ll r = 1; // will include
    while (!good(w, h, n, r))
        r *= 2;
    while (r > l + 1)
    {
        ll m = (l + r) / 2;
        if (good(w, h, n, m))
            r = m;
        else
            l = m;
    }
    cout << r;

    return 0;
}