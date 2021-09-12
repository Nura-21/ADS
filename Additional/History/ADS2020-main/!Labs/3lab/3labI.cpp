#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
    {
        int t;
        cin >> t;
        if (left_bin_search(a, n, t))
            cout << left_bin_search(a, n, t) << " " << right_bin_search(a, n, t) << endl;
        else
            cout << left_bin_search(a, n, t) << endl;
    }
    return 0;
}