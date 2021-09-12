#include <bits/stdc++.h>
using namespace std;

int find_lower(int a[], int n, int x)
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

int find_upper(int a[], int n, int x)
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
    return r;
}

bool find(int a[], int n, int x)
{
    int i = find_lower(a, n, x);
    return i >= 0 && a[i] == x;
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
        cout << find_upper(a, n, x) + 1 << endl;
    }

    return 0;
}