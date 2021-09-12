#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

char st[100001];
int h;
void push(char x)
{
    st[h++] = x;
}
void pop()
{
    h--;
}
char top()
{
    if (h == 0)
    {
        cerr << "Stack error\n";
        exit(0);
    }
    return st[h - 1];
}

bool empty()
{
    return h == 0;
}

bool isOpening(char ch)
{
    return ch == '{' || ch == '[' || ch == '(';
}

char paired(char r)
{
    if (r == ')')
        return '(';
    if (r == ']')
        return '[';
    return '{';
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (isOpening(s[i]))
            push(s[i]);
        else
        {
            if (!empty() && top() == paired(s[i]))
                pop();
            else
            {
                cout << "no\n";
                return 0;
            }
        }
    }
    if (!empty())
        cout << "no\n";
    else
        cout << "yes\n";

    return 0;
}