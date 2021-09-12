#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    int adj[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        cout << (adj[a][b] and adj[a][c] and adj[c][b] ? "YES" : "NO") << endl;
    }
    return 0;
}