#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    double l = 0;   // can
    double r = 1e8; // cannot

    for (int i = 0; i < 100; i++)
    {
        double m = (l + r) * .5;
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            s += (int)(a[j] / m);
        }
        if (s >= k)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << setprecision(20) << l;

    return 0;
}