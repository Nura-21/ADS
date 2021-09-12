#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    cin >> n;
    int mx = INT_MIN;
    while (n--)
    {
        cin >> t;
        mx = max(mx, t);
    }
    cout << mx;
    return 0;
}