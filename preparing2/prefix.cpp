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
    string s;
    cin >> s;
    vector<ll> p = prefix_function(s);
    for (auto &i : p)
        cout << i << " ";
    return 0;
}