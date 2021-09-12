#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int pattern[n][m];

    for (int i = 0; i < n; i++) // fill pattern
        for (int j = 0; j < m; j++)
            pattern[i][j] = 0;

    for (int i = 0; i < n; i++) // add data
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int mx = -10000;
    int mn = 10000;
    for (int i = 0; i < n; i++) // check min in rows and do pattern
    {
        for (int j = 0; j < m; j++)
            mn = min(mn, a[i][j]);
        for (int j = 0; j < m; j++)
            if (a[i][j] == mn)
                pattern[i][j]++;
        mn = 10000;
    }

    // for (int i = 0; i < n; i++) // output pattern
    // {
    //     for (int j = 0; j < m; j++)
    //         cout << pattern[i][j] << " ";
    //     cout << endl;
    // }

    for (int i = 0; i < m; i++) // check max in columns and do pattern
    {
        for (int j = 0; j < n; j++)
            mx = max(mx, a[j][i]);
        for (int j = 0; j < n; j++)
            if (a[j][i] == mx)
                pattern[j][i]++;
        mx = -10000;
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) // count pattern
    {
        for (int j = 0; j < m; j++)
            if (pattern[i][j] == 2)
                cnt++;
    }
    cout << cnt << endl;
    return 0;
}