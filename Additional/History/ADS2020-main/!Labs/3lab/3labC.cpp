#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    cin >> n;
    int mx = INT_MIN;
    int mx_i = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t > mx)
        {
            mx = t;
            mx_i = i;
        }
    }
    cout << mx_i + 1 << endl;

    return 0;
}