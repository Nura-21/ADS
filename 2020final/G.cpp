#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
vector<string> v;

bool add_operation()
{
    string s;
    cin >> s;
    v.push_back(s);
    return true;
}
bool remove_operation()
{
    string s;
    cin >> s;
    auto it = remove(v.begin(), v.end(), s);
    v.erase(it, v.end());
    return true;
}
bool find_operation()
{
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
        if (v[i].rfind(s, 0) != string::npos)
            cnt++;
    cout << cnt << endl;
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    while (n--)
    {
        char c;
        cin >> c;
        if (c == '+')
            add_operation();
        else if (c == '-')
            remove_operation();
        else if (c == '?')
            find_operation();
    }
    return 0;
}