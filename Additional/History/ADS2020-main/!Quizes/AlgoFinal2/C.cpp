#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
const int MAX = 100;

vector<int> g[MAX];
int used[MAX];

bool input_data()
{
    int u, v;
    while (true)
    {
        cin >> u;
        if (u == 0)
            break;
        cin >> v;
        --u;
        --v;
        g[u].push_back(v);
    }
    return true;
}

void dfs(int v)
{
    used[v] = 1;
    for (auto it : g[v])
    {
        if (used[it] == 0)
            dfs(it);
    }
}

bool check(int n)
{
    for (int i = 0; i < n; i++)
        if (used[i] != 1)
            return false;
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, x;
    cin >> n >> x;
    input_data();
    dfs(--x);
    cout << (check(n) ? "Yes" : "No");
    return 0;
}