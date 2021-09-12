#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
int n, m, x, y;
const int MAX_V = 1000;
vector<int> g[MAX_V];
vector<int> color(MAX_V, 0);
bool okay = true;
void dfs(int v, int c)
{
    color[v] = c;
    for (int i = 0; i < g[v].size(); i++)
    {
        int y = g[v][i];
        if (color[y] == 0)
            dfs(y, 3 - c);
        else
        {
            if (color[y] == c)
                okay = false;
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, 1);
    for (int i = 0; i < n; i++)
        if (color[i] == 0)
            dfs(i, 1);

    if (okay)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            if (color[i] == 1)
                cout << i + 1 << " ";
    }
    else
        cout << "NO";

    return 0;
}