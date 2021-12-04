#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

const int MAX_V = 200;
vector<int> g[MAX_V];
vector<bool> used(MAX_V, false);
int cnt = 0;
void dfs(int v)
{
    used[v] = true;
    cnt++;
    for (int i = 0; i < g[v].size(); i++)
    {
        int y = g[v][i];
        if (!used[y])
            dfs(y);
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            if (t != 0)
                g[i].push_back(j);
        }
    }
    dfs(--m);
    cout << cnt;

    return 0;
}