#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
const int MAX_V = 10000;
queue<int> q;
vector<int> from(2 * MAX_V, -1);
vector<int> used(2 * MAX_V, 0);
int n, final_n;

int mp_it(int y)
{
    return (y * 2);
}
int decr_it(int y)
{
    return (y - 1);
}

void bfs(int v)
{
    q.push(v);
    used[v] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < 2; i++)
        {
            int y;
            if (i == 0)
                y = mp_it(x);
            else
                y = decr_it(x);
            if (y >= 0 && y < MAX_V + 100 && used[y] == 0)
            {
                q.push(y);
                used[y] = 1;
                from[y] = x;
            }
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> n >> final_n;
    bfs(n);
    vector<int> way;
    for (int i = final_n; i != -1; i = from[i])
        way.push_back(i);
    cout << way.size() - 1 << endl;
    for (int i = 1; i < way.size(); i++)
        cout << way[way.size() - 1 - i] << " ";
    return 0;
}