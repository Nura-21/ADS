#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll cnt;
queue <int> q1,q2;
int main()
{
    int n;
    for(int i = 1;i<=5;i++)
    {
        cin >> n;
        q1.push(n);
    }
    for(int i = 1;i<=5;i++)
    {
        cin >> n;
        q2.push(n);
    }
    while(cnt<=100000 and !q1.empty() and !q2.empty())
    {   
        cnt++;
        if(q1.front() == 9 and q2.front() == 0)
        {
            q2.push(q1.front());
            q2.push(q2.front());
            q1.pop();
            q2.pop();
            continue;
        }
        if(q1.front() == 0 and q2.front() == 9)
        {
            q1.push(q1.front());
            q1.push(q2.front());
            q1.pop();
            q2.pop();
            continue;
        }
        if(q1.front() > q2.front())
        {
            q1.push(q1.front());
            q1.push(q2.front());
            q1.pop();
            q2.pop();
        }
        else
        {
            q2.push(q1.front());
            q2.push(q2.front());
            q1.pop();
            q2.pop();
        }
    }
    if(cnt>100000)
    {
        cout << "botva";
    }
    else if(q1.empty())
    {
        cout << "second " << cnt;
    }
    else
    {
        cout << "first " << cnt;
    }
}