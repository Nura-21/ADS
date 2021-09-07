#include <bits/stdc++.h>

using namespace std;

using ll = long long;
deque<int> dq, dq1;

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        char c;
        int n;
        cin >> c;
        if(c == '+')
        {
            cin >> n;
            dq1.push_back(n);
        }
        if(c == '-')
        {
            cout << dq.front() << "\n";
            dq.pop_front();
        }
        if(c == '*')
        {
            cin >> n;
            dq1.push_front(n);
        }
        if(dq1.size()>dq.size())
        {
            dq.push_back(dq1.front());
            dq1.pop_front();
        }
    }
}