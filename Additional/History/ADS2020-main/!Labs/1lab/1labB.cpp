#include <bits/stdc++.h>
using namespace std;
int q[100000];
int start, tail;
void q_push(int x)
{
    q[tail++] = x;
    cout << "ok" << endl;
}
bool q_empty()
{
    return start == tail;
}
void q_pop()
{
    if (q_empty())
        cout << "error" << endl;
    else
        cout << q[start++] << endl;
}

void q_front()
{
    if (q_empty())
        cout << "error" << endl;
    else
        cout << q[start] << endl;
}

int q_size()
{
    return tail - start;
}

void q_clear()
{
    tail = 0;
    start = 0;
    cout << "ok" << endl;
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "size")
            cout << q_size() << endl;
        else if (s == "push")
        {
            int n;
            cin >> n;
            q_push(n);
        }
        else if (s == "clear")
            q_clear();
        else if (s == "front")
            q_front();
        else if (s == "exit")
        {
            cout << "bye" << endl;
            return 0;
        }
        else if (s == "pop")
            q_pop();
    }

    return 0;
}