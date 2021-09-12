#include <bits/stdc++.h>
using namespace std;

bool bin_srch(int a[], int n, int x)
{
    int l = 0;
    int r = n - 1;
    while (r >= l)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return true;
        if (a[m] < x)
            l = m + 1;
        if (a[m] > x)
            r = m - 1;
    }
    return false;
}

int main()
{
    int n, k, x;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (k--)
    {
        cin >> x;
        cout << (bin_srch(a, n, x) ? "YES" : "NO");
        cout << endl;
    }

    return 0;
}