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
    // freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    vector<int> p = prefix_function(s);
    int n = s.size();
    int occurences[n];
    for (int i = 0; i < n; i++)
        occurences[i] = 0;
    for (int i = 0; i < n; i++)
        occurences[p[i]]++;
    // for (int i = 0; i < s.size(); i++)
    //     cout << s[i] << " ";
    // cout << endl;
    // for (int i = 0; i < s.size(); i++)
    //     cout << p[i] << " ";
    // cout << endl;
    // for (int i = 0; i < n; i++)
    //     cout << occurences[i] << " ";
    int j = p[n - 1];
    cout << ((j > 0 and occurences[j] >= 2) ? s.substr(0, j) : "Just a legend");
    return 0;
}