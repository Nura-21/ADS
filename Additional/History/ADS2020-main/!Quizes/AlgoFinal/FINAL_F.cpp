#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

vector<int> find_prefixes(vector<int> &v)
{
    int n = v.size();
    vector<int> buffer(n + 1);
    buffer[0] = 0;
    for (int i = 1; i < n + 1; i++)
        buffer[i] = buffer[i - 1] + v[i - 1];
    for (auto it : buffer)
    {
        cout << it << " ";
    }
    sort(buffer.begin(), buffer.end());
    cout << endl;
    return buffer;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> prefixes = find_prefixes(v);
    int mn = 1000000;
    for (int i = 1; i < prefixes.size(); i++)
    {
        sum = prefixes[i] - prefixes[i - 1];
        mn = min(mn, sum);
    }
    cout << mn;

    return 0;
}