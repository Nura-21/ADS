#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    vector<deque<string>> v(3, deque<string>());
    int n;
    string s;
    while (cin >> n)
    {
        cin >> s;
        v[11 - n].push_back(s);
    }
    for (int i = 2; i >= 0; i--)
    {
        while (!v[i].empty())
        {
            cout << 11 - i << sep << v[i].front() << endl;
            v[i].pop_front();
        }
    }

    return 0;
}