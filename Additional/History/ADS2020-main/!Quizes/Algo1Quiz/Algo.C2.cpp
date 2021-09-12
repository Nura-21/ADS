#include <bits/stdc++.h>
using namespace std;
int a[1000000];

int get(int l, int r, int a[], int n)
{
    if (l > r)
        return 0;
    int L = lower_bound(a, a + n, l) - a;
    int R = upper_bound(a, a + n, r) - a;
    return R - L;
}

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int l1, r1, l2, r2;
    while (q--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        int lc = max(l1, l2);
        int rc = min(r1, r2);

        int ans = get(l1, r1, a, n) + get(l2, r2, a, n) - get(lc, rc, a, n);
        cout << ans << endl;
    }
    return 0;
}