#include <bits/stdc++.h>

using namespace std;

using ll = long long;

queue<string> q2,q3;
int main()
{
    int n;
    string s;
    while(cin >> n)
    {
        cin >> s;
        if(n == 9)
        {
            cout << n << " "<< s << "\n";
        }
        if(n == 10)
        {
            q2.push(s);
        }
        if(n == 11)
        {
            q3.push(s);
        }
    }
    while(!q2.empty() or !q3.empty())
    {
        if(!q2.empty())
        {
            cout << "10 " << q2.front() << "\n";
            q2.pop();
        }
        else if(!q3.empty())
        {
            cout << "11 "<< q3.front() << "\n";
            q3.pop();
        }
    }
}