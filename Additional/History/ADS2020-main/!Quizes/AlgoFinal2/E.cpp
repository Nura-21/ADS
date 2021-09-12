#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
priority_queue<int> pq;

bool input_data(int n)
{
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        pq.push(t);
    }
}

int analyze()
{
    while (pq.size() != 1)
    {
        int e1 = pq.top();
        pq.pop();
        int e2 = pq.top();
        pq.pop();
        if (e1 != e2)
            pq.push(e1 - e2);
        if (pq.empty())
            return 0;
    }
    return pq.top();
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    input_data(n);
    cout << analyze();

    return 0;
}