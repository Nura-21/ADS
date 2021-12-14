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

ll check(string s, string t)
{
    vector<ll> p = prefix_function(s);
    if (p[s.size() - 1] == t.size())
        return 0;
    else if (p[s.size() - 1] != 0)
        return p[s.size() - 1];
    return -1;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = t + "#" + s + s;
    cout << check(s, t);
    return 0;
}
