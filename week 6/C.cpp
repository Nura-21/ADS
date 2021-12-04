#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
vector<ll> prefix_function(string s)
{
    ll n = s.size();
    vector<ll> p(n);
    for (ll i = 1; i < n; i++)
    {
        ll j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    s = t + "#" + s;
    vector<ll> p = prefix_function(s);

    // cout << s << endl;
    //  for (int i = 0; i < s.size(); i++)
    //      cout << p[i];
    //  cout << endl;
    if (p[s.size() - 1] == t.size())
        cout << 0;
    else if (p[s.size() - 1] != 0)
        cout << p[s.size() - 1];
    else
        cout << -1;
    return 0;
}