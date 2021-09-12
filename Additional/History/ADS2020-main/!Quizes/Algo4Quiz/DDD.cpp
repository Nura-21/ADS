#include <iostream>
#include <vector>

using namespace std;
int n, m, x, y;
const int MAX_V = 110000;
vector<int> g[MAX_V];
vector<int> used(MAX_V, 0);
vector<int> result;

void dfs(int v)
{
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (used[g[v][i]] == 0)
            dfs(g[v][i]);
    result.push_back(v);
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
    }
    for (int i = 0; i < n; i++)
        if (used[i] == 0)
            dfs(i);

    for (int i = 0; i < n; i++)
        cout << result[result.size() - 1 - i] + 1 << " ";

    return 0;
}