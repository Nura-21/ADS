#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

vector<int> prefix_function(string s)
{
    int n = s.size();
    vector<int> p(n);
    for (int i = 1; i < n; i++)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}
// a b a b a b a b c x
// 0 0 1 2 3 4 5 6 0 0

// a a c
// 0 1 0

// a b a a b a f
// 0 0 1 1 2 3 0

// a b d a b d f
// 0 0 0 1 2 3 0
int main()
{
    // freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    vector<int> p = prefix_function(s);
    // for (int i = 0; i < s.size(); i++)
    //     cout << s[i] << " ";
    // cout << endl;
    // for (int i = 0; i < s.size(); i++)
    //     cout << p[i] << " ";
    int cnt = 0;
    for (int i = 1; i < s.size() - 1; i += 2)
    {
        int pos = i + 1;
        int div = pos - p[i];
        if (pos % div == 0 and pos / 2 % div == 0)
            cnt++;
    }
    cout << cnt;

    return 0;
}