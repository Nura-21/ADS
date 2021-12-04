#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int n, i, j, k, x1, y1, x2, y2, u, v;
    queue<pair<int, int>> q;
    int x[8] = {-2, -2, -1, -1, 1, 1, 2, 2},
        y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    cin >> n;
    int d[n + 1][n + 1];
    for (i = 0; i <= n; ++i)
        for (j = 0; j <= n; ++j)
            d[i][j] = 10000;
    cin >> x1 >> y1 >> x2 >> y2;
    d[x1][y1] = 0;
    q.push(make_pair(x1, y1));
    while (!q.empty())
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for (k = 0; k < 8; ++k)
        {
            u = i + x[k];
            v = j + y[k];
            if (u > 0 && u <= n && v > 0 && v <= n && d[i][j] + 1 < d[u][v])
            {
                d[u][v] = d[i][j] + 1;
                q.push(make_pair(u, v));
            }
        }
    }
    // for (i = 0; i <= n; ++i)
    // {
    //     for (j = 0; j <= n; ++j)
    //         cout << d[i][j] << " ";
    //     cout << endl;
    // }

    cout << d[x2][y2] << endl;
    vector<pair<int, int>> way;
    int w = d[x2][y2];
    while (true)
    {
        int w = d[x2][y2];
        way.push_back(make_pair(x2, y2));
        if (w == 0)
            break;
        for (int k = 0; k < 8; k++)
        {
            u = x2 + x[k];
            v = y2 + y[k];
            if (u > 0 && u <= n && v > 0 && v <= n && d[u][v] == w - 1)
            {
                x2 = u;
                y2 = v;
                break;
            }
        }
    }
    for (int i = 0; i < way.size(); i++)
        cout << way[way.size() - 1 - i].first << " " << way[way.size() - 1 - i].second << endl;

    return 0;
}