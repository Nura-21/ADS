#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
bool check(int x)
{
    int cnt = 0;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            cnt++;
        if (cnt > 1)
            return true;
    }
    if (cnt == 1)
        return false;
    return true;
}

int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        if (!check(i))
            cnt++;
    cout << cnt;
    return 0;
}