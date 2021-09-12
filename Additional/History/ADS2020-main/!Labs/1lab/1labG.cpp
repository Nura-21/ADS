#include <bits/stdc++.h>
using namespace std;
int st[1000000];
int h = 0;

void st_push(int n)
{
    st[h++] = n;
}
int st_back()
{
    return st[h - 1];
}
void st_pop()
{
    if (h != 0)
        h--;
}
void plus_it()
{
    int s1 = st_back();
    st_pop();
    int s2 = st_back();
    st_pop();
    st_push(s1 + s2);
}
void minus_it()
{
    int s1 = st_back();
    st_pop();
    int s2 = st_back();
    st_pop();
    st_push(s2 - s1);
}
void mp_it()
{
    int s1 = st_back();
    st_pop();
    int s2 = st_back();
    st_pop();
    st_push(s1 * s2);
}
int main()
{
    char s;
    while (cin >> s)
    {
        if (s == '+')
            plus_it();
        else if (s == '-')
            minus_it();
        else if (s == '*')
            mp_it();
        else
            st_push(s - '0');
    }
    cout << st[0];

    return 0;
}