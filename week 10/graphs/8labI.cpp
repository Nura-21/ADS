#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
const int MAX_V = 100;
queue<int> q;
vector<int> from(MAX_V, -1);
vector<int> dist(MAX_V);
vector<int> used(MAX_V, 0);
int adj[1000][1000];

void bfs(int v, int n)
{
    q.push(v);
    dist[v] = 0;
    used[v] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (adj[x][i] && !used[i])
            {
                dist[i] = dist[x] + 1;
                from[i] = x;
                q.push(i);
                used[i] = 1;
            }
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];
    cin >> x >> y;
    --x;
    --y;
    bfs(x, n);

    if (used[y])
    {
        if (dist[y] == 0)
            cout << dist[y] << endl;
        else
        {
            cout << dist[y] << endl;
            vector<int> way;
            for (int i = y; i != -1; i = from[i])
                way.push_back(i);
            for (int i = 0; i < way.size(); i++)
                cout << way[way.size() - 1 - i] + 1 << " ";
        }
    }
    else
        cout << -1 << endl;

    return 0;
}