#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int dist[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];
    int mn, k1, k2, k3;
    k1 = k2 = k3 = 0;
    mn = 1000000;
    for (int i1 = 0; i1 < n; i1++)
        for (int i2 = 0; i2 < n; i2++)
            for (int i3 = 0; i3 < n; i3++)
            {
                int t = dist[i1][i2] + dist[i2][i3] + dist[i3][i1];
                if (t < mn and dist[i1][i2] and dist[i2][i3] and dist[i3][i1])
                {
                    mn = t;
                    k1 = i1;
                    k2 = i2;
                    k3 = i3;
                }
            }

    cout << k1 + 1 << sep << k2 + 1 << sep << k3 + 1;

    return 0;
}