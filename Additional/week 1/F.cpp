#include <bits/stdc++.h>

using namespace std;

using ll = long long;
stack<char> st;
int main()
{
    string s;
    cin >> s;
    for(size_t i=0;i<s.size();i++)
    {
        if(s[i] == '(' or s[i] == '[' or s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if(!st.empty())
            {   
                if((s[i]==')' and st.top() == '(') or (s[i]==']' and st.top() == '[') or (s[i]=='}' and st.top() == '{'))
                {
                    st.pop();
                }
                else
                {
                    cout << "no";
                    return 0;
                }
            }
            else
            {
                cout << "no";
                return 0;
            }
        }
    }
    if(st.empty())
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}    