#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

bool isPossible(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (!st.empty())
            if (st.top() == s[i])
            {
                st.pop();
                continue;
            }
        st.push(s[i]);
    }
    return st.empty();
}

int main()
{
    // freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    cout << (isPossible(s) ? "YES" : "NO");
    return 0;
}