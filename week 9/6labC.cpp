#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        cnt = i;
        if (s1 == s2)
            break;
        char tmp = s1.back();
        s1.pop_back();
        s1 = tmp + s1;
    }
    if (s1 != s2)
        cout << -1;
    else
        cout << cnt;

    return 0;
}