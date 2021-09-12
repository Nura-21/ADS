#include <bits/stdc++.h>
using namespace std;

bool find_lower(int a[], int n, int x)
{
    int l = -1; // a[l]<=x
    int r = n;  // a[r]>x
    while (r > l + 1)
    {
        int m = (l + r) / 2;
        if (a[m] <= x)
            l = m;
        else
            r = m;
    }
    return l;
}

bool find_upper(int a[], int n, int x)
{
    int l = -1; // a[l]<x
    int r = n;  // a[r]>=x
    while (r > l + 1)
    {
        int m = (l + r) / 2;
        if (a[m] < x)
            l = m;
        else
            r = m;
    }
    return l;
}

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << find_lower(a, n, x) << endl;

    return 0;
}