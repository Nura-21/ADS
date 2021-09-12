#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

bool sz_cmp(string &f, string &s)
{
    return f.size() > s.size();
}

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
bool kmp_find(string main_str, string sub_str)
{
    string common = sub_str + '#' + main_str;
    vector<int> p = prefix_function(common);
    for (int i = 0; i < common.size(); i++)
        if (p[i] == sub_str.size())
            return true;
    return false;
}

string commonString(vector<string> strings)
{
    string ans = "";
    int n = strings.size();
    sort(strings.begin(), strings.end(), sz_cmp);
    // for (auto s : strings)
    //     cout << s << endl;
    string s = strings.back();
    int s_sz = s.size();

    for (int i = 0; i < s_sz; i++)
    {
        for (int j = i; j < s_sz; j++)
        {
            string sub = s.substr(i, j - i + 1);
            int occur = 0;
            for (int k = 0; k < n - 1; k++)
            {
                if (kmp_find(strings[k], sub))
                    occur++;
                else
                    break;
            }
            if (++occur == n && ans.size() < sub.size())
                ans = sub;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> strings;
    while (n--)
    {
        string s;
        cin >> s;
        strings.push_back(s);
    }
    cout << commonString(strings);
}