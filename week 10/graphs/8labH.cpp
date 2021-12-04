#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
int n, m, x, y;
const int MAX_V = 1000;
vector<int> g[MAX_V];
vector<int> ans;
vector<int> already(MAX_V, 0);
void dfs(int v)
{
    already[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        int y = g[v][i];
        if (already[y] == 1)
        {
            cout << "No";
            exit(0);
        }
        else if (already[y] == 0)
            dfs(y);
    }
    ans.push_back(v);
    already[v] = 2;
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
    dfs(0);
    for (int i = 1; i < n; i++)
        if (already[i] == 0)
            dfs(i);

    cout << "Yes" << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[ans.size() - 1 - i] + 1 << " ";
    return 0;
}