#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
const int MAX_V = 1500;
queue<pair<int, int>> q;
vector<pair<int, int>> mar;
int x[4] = {1, -1, 0, 0},
    y[4] = {0, 0, -1, 1};
int d[MAX_V][MAX_V];
int a[MAX_V][MAX_V];
int main()
{
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < MAX_V; i++)
        for (int j = 0; j < MAX_V; j++)
        {
            d[i][j] = 228228;
            a[i][j] = 0;
        }
    bool ok = false;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                ok = true;
            }
            if (a[i][j] == 2)
            {
                mar.push_back(make_pair(i, j));
            }
        }
    }
    if (!ok)
    {
        cout << 0;
        return 0;
    }
    for (auto it : mar)
    {
        q.push(make_pair(it.first, it.second));
        d[it.first][it.second] = 0;
    }
    int i, j, u, v;
    while (!q.empty())
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            u = i + x[k];
            v = j + y[k];
            if (a[u][v] == 1 && d[i][j] + 1 < d[u][v])
            {
                a[u][v] = 2;
                d[u][v] = d[i][j] + 1;
                q.push(make_pair(u, v));
            }
        }
    }
    int mx = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (a[i][j] == 1)
            {
                cout << -1;
                return 0;
            }
            if (a[i][j] == 2 and (d[i][j] > mx))
            {
                mx = d[i][j];
            }
        }
    }
    cout << mx;

    return 0;
}