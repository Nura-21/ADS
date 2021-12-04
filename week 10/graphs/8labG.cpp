#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
bool area[1000][1000];
int cnt = 0;

void dfs(int i, int j)
{
    if (area[i][j] == false)
        return;
    area[i][j] = false;
    dfs(i - 1, j);
    dfs(i, j - 1);
    dfs(i + 1, j);
    dfs(i, j + 1);
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + 2; i++)
        for (int j = 0; j < m + 2; j++)
            area[i][j] = false;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char t;
            cin >> t;
            area[i][j] = (t == '.' ? false : true);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (area[i][j] != false)
            {
                cnt++;
                dfs(i, j);
            }
    cout << cnt;
    return 0;
}

// 4 5
// 1 2
// 2 3
// 3 4
// 1 4
// 4 1