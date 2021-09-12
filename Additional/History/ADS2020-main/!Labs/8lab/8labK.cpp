#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
const int MAX_V = 10000;
queue<int> q;
vector<int> from(MAX_V, -1);
vector<int> used(MAX_V, 0);
int n, final_n, y;

int increaseFirst(int y)
{
    if (y / 1000 != 9)
        return y + 1000;
    return y;
}
int decreaseLast(int y)
{
    if (y % 10 != 1)
        return y - 1;
    return y;
}
int shiftRight(int y)
{
    return y % 10 * 1000 + y / 10;
}
int shiftLeft(int y)
{
    return y % 1000 * 10 + y / 1000;
}

void bfs(int v)
{
    q.push(v);
    used[v] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
                y = increaseFirst(x);
            else if (i == 1)
                y = decreaseLast(x);
            else if (i == 2)
                y = shiftLeft(x);
            else if (i == 3)
                y = shiftRight(x);
            if (used[y] == 0)
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
    cin >> n;
    cin >> final_n;
    bfs(n);
    vector<int> way;
    for (int i = final_n; i != -1; i = from[i])
        way.push_back(i);
    for (int i = 0; i < way.size(); i++)
        cout << way[way.size() - 1 - i] << endl;
    return 0;
}