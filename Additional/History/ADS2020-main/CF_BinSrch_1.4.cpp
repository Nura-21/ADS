#include <bits/stdc++.h>
#define ll long long
#define sep " "

using namespace std;
int main()
{
    int n, q, l, r;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        int lb = lower_bound(a, a + n, l) - a;
        int rb = upper_bound(a, a + n, r) - a;
        cout << rb - lb << sep;
    }

    return 0;
}