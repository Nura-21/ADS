#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int, string>> v;
    int g;
    string name;
    while (cin >> g >> name)
    {
        v.push_back(make_pair(g, name));
    }
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        pair<int, string> val = v[i];
        if (val.first == 9)
            cout << val.first << " " << val.second << endl;
    }
    for (int i = 0; i < n; i++)
    {
        pair<int, string> val = v[i];
        if (val.first == 10)
            cout << val.first << " " << val.second << endl;
    }
    for (int i = 0; i < n; i++)
    {
        pair<int, string> val = v[i];
        if (val.first == 11)
            cout << val.first << " " << val.second << endl;
    }
    return 0;
}