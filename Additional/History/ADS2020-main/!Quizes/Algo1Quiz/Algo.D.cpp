#include <bits/stdc++.h>
#define ll long long
#define sep " "

using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = max(x2, y2);
    }
    sort(a, a + n);
    cout << a[k - 1];
    return 0;
}