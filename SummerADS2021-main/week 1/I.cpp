#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n,m,k,cnt;
stack <int> st[511];
vector <pair<int,int>> v;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> m;
        for(int j=1;j<=m;j++)
        {
            cin >> k;
            st[i].push(k);
        }
        if(i!=1)
        {
            while(!st[i].empty())
            {
                st[1].push(st[i].top());
                st[i].pop();
                v.push_back(make_pair(i,1));
            }
        }
    }
    if(n == 1)
        return 0;
    if(n == 2)
    {
        while(!st[1].empty() && st[1].top()==2)
        {
            st[2].push(st[1].top());
            st[1].pop();
            cnt++;
        }
        while(!st[1].empty())
        {
            if(st[1].top()==2)
            {
                cout << "0\n";
                return 0;
            }
            st[1].pop();
        }
        for(int i = 0;i<cnt;i++)
        {
            v.push_back(make_pair(1,2));
        }
    }
    else
    {
        while(!st[1].empty())
        {
            if(st[1].top() == 1 or st[1].top() == 2)
            {
                st[2].push(st[1].top());
                v.push_back(make_pair(1,2)); 
            }
            else
            {
                st[st[1].top()].push(st[1].top());
                v.push_back(make_pair(1,st[1].top())); 
            }
            st[1].pop();
        }
        while(!st[2].empty())
        {
            if(st[2].top()==1)
            {
                st[1].push(st[2].top());
                v.push_back(make_pair(2,1)); 
            }
            else
            {
                v.push_back(make_pair(2,3)); 
                st[3].push(st[2].top());
            }
            st[2].pop();
        }
        while(!st[3].empty()&&st[3].top()==2)
        {
            st[2].push(st[3].top());
            v.push_back(make_pair(3,2)); 
            st[3].pop();
        }
    }
    for(auto i : v)
    {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}