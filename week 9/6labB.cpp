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
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    vector<ll> p = prefix_function(s);
    // for (int i = 0; i < s.size(); i++)
    //     cout << p[i] << " ";
    // cout << endl;
    ll tmp = s.size() - p[s.size() - 1];
    cout << (s.size() % tmp == 0 ? s.size() / tmp : 1);
    return 0;
}