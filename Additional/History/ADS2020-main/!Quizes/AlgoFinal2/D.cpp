#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
int cnt = 0;

bool isTop(string s)
{
    stack<char> st;
    for (auto it : s)
    {
        if (!st.empty())
        {
            if (st.top() == it)
                st.pop();
            else
                st.push(it);
        }
        else
            st.push(it);
    }
    return st.empty();
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (isTop(s))
            cnt++;
    }
    cout << cnt;

    return 0;
}