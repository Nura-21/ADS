#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int adj[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    int col[n];
    for (int i = 0; i < n; i++)
        cin >> col[i];

    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (adj[i][j] == 1 and col[i] != col[j])
                cnt++;

    cout << cnt;
    return 0;
}