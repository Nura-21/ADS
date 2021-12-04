#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

const int MAX_V = 200;
vector<int> g[MAX_V];
vector<int> already(MAX_V, 0);

void dfs(int v, int prev_v)
{
    already[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        int y = g[v][i];
        if (already[y] == 1 and y != prev_v)
        {
            cout << "NO";
            exit(0);
        }
        else if (already[y] == 0)
            dfs(y, v);
    }
    already[v] = 2;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            if (t != 0)
                g[i].push_back(j);
        }
    dfs(0, -1);
    for (int i = 0; i < n; i++)
        if (already[i] == 0)
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";

    return 0;
}