#include <bits/stdc++.h>
using namespace std;
bool bin_search(int *a, int n, int x)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2; // middle point
        if (a[mid] == x)       // base case
            return true;
        if (x < a[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        cout << (bin_search(a, n, t) ? "YES\n" : "NO\n");
    }
    return 0;
}