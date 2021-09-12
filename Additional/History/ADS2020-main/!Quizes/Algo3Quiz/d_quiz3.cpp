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

bool isKTimes(string paper, string pass, int k)
{
    string common = pass + '#' + paper;
    vector<int> p = prefix_function(common);
    int n = paper.size();
    int m = pass.size();
    int cnt = 0;
    for (int i = 0; i < common.size(); i++)
    {
        if (p[i] == pass.size())
            cnt++;
        if (cnt >= k)
            return true;
    }

    return false;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    string pass, paper;
    int k;
    cin >> pass >> k >> paper;
    cout << (isKTimes(paper, pass, k) ? "YES" : "NO");
    return 0;
}