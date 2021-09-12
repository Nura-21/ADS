#include <bits/stdc++.h>

using namespace std;
int main()
{
    int mx = -1000000;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int mx2 = -1000000;
    for (int i = 0; i < n; i++)
        if (a[i] > mx2 and a[i] < mx)
            mx2 = a[i];

    cout << mx2 << endl;
}