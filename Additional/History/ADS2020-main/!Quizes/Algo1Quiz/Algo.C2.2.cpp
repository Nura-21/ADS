#include <bits/stdc++.h>
using namespace std;
int a[1000000];

int left_bin_search(int *a, int n, int x)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (x <= a[mid])
            r = mid;
        else
            l = mid + 1;
    }
    if (a[l] == x)
        return l + 1;
    return 0;
}

int right_bin_search(int *a, int n, int x)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    if (a[l] == x)
        return l + 1;
    return 0;
}

int get(int l, int r, int a[], int n)
{
    if (l > r)
        return 0;
    int L = left_bin_search(a, n, l) - 1;
    int R = right_bin_search(a, n, r);
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