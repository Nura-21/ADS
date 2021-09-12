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

int main()
{
    freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    s = t + '#' + s;
    vector<int> p = prefix_function(s);
    for (int i = 0; i < s.size(); i++)
        cout << p[i] << " ";
    cout << endl;
    for (int i = 0; i < s.size(); i++)
        if (p[i] == t.size())
            cout << i - 2 * t.size() << " ";
    return 0;
}