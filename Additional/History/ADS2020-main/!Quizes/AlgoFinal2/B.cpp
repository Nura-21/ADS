#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
vector<ll> v;

bool data_fill(ll n)
{
    while (n--)
    {
        ll t;
        cin >> t;
        v.push_back(t);
    }
    return true;
}

ll get_max()
{
    ll mx = -1;
    for (auto it : v)
        mx = max(mx, it);
    return mx;
}

ll get_time(ll mid)
{
    ll time = 0;
    for (auto it : v)
        time += ceil(it * 1.0 / mid);
    // cout << time << endl;
    return time;
}

ll bin_left_search(ll h)
{
    ll l = 0;
    ll r = get_max();
    while (l < r)
    {
        ll mid = (l + r) / 2;
        // cout << mid << endl;
        // cout << "time: " << time << endl;
        if (h >= get_time(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    freopen("input.txt", "r", stdin);
    ll n, h;
    cin >> n >> h;
    data_fill(n);
    cout << bin_left_search(h);

    return 0;
}