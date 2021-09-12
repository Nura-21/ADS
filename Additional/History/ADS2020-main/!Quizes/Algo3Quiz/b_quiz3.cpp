#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

const int MX_SIZE = 3000;
ll p = 31;
ll powers[MX_SIZE];

void getPowers()
{
    powers[0] = 1;
    for (int i = 1; i < MX_SIZE; i++)
        powers[i] = powers[i - 1] * p;
}

ll getSubHash(string s, int l, int r)
{
    ll sum = 0;
    for (int i = l; i <= r; i++)
        sum += s[i] * powers[i - l];
    return sum;
}

vector<ll> getHashes(string s)
{
    vector<ll> hashes(s.size());
    hashes[0] = s[0];
    for (int i = 1; i < s.size(); i++)
        hashes[i] = hashes[i - 1] + s[i] * powers[i];
    return hashes;
}

int countSubstr(vector<ll> hashes, string s, int l, int r)
{
    ll subhash = getSubHash(s, l, r);
    int n = s.size();
    int m = r - l + 1;
    int cnt = 0;
    for (int i = 0; i <= n - m; i++)
    {
        int j = i + m - 1;
        ll hash_i_j = hashes[j];
        if (i)
            hash_i_j -= hashes[i - 1];
        if (subhash * powers[i] == hash_i_j)
            cnt++;
    }
    return cnt;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    getPowers();
    vector<ll> hashes = getHashes(s);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << countSubstr(hashes, s, l - 1, r - 1) << endl;
    }
    return 0;
}