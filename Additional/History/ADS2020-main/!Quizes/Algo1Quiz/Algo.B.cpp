#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int start = 500000, tail = 500001;
bool reversed = false;

void push_back(int x)
{
    if (reversed == false)
        a[tail++] = x;
    else
        a[start--] = x;
}
void reverse_easy()
{
    if (reversed == false)
        reversed = true;
    else
        reversed = false;
}
void pop_front()
{
    ++start;
}
void pop_back()
{
    --tail;
}
int front()
{
    return a[start + 1];
}
int back()
{
    return a[tail - 1];
}
bool a_empty()
{
    return (start + 1) == tail;
}

int main()
{
    int n, t, x;
    cin >> n;
    while (n--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x;
            push_back(x);
        }
        if (t == 2)
        {
            reverse_easy(); // or reverse_easy;
        }
    }
    while (!a_empty())
    {
        if (reversed == false)
        {
            cout << front() << " ";
            pop_front();
        }
        else
        {
            cout << back() << " ";
            pop_back();
        }
    }
    return 0;
}