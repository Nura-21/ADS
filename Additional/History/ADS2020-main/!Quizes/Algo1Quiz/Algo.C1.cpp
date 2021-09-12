#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int r1, l1, r2, l2;
    int cnt = 0;
    while (q--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        for (int i = 0; i < n; i++)
            if ((l1 <= a[i] and a[i] <= r1) or (l2 <= a[i] and a[i] <= r2))
                cnt++;
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}