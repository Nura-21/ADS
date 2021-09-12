#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mx = -1000000;
    int mn = 1000000;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mx)
            cout << mn << " ";
        else
            cout << a[i] << " ";
    }
    return 0;
}