#include <bits/stdc++.h>

#define INFTY 0x3ddddddd

using namespace std;

class G
{
    int v;
    vector<pair<int, int>> *adjacent;

public:
    G(int v);
    vector<int> pathshortestortest(int s);
    void add(int u, int v, int w);
};

G::G(int v)
{
    this->v = v;
    adjacent = new vector<pair<int, int>>[v];
}

void G::add(int u, int v, int w)
{
    adjacent[v].push_back(make_pair(u, w));
    adjacent[u].push_back(make_pair(v, w));
}

vector<int> G::pathshortestortest(int src)
{
    priority_queue<pair<int, int>> maxpq;

    vector<int> distance(v, INFTY);

    maxpq.push(make_pair(0, src));
    distance[src] = 0;

    while (!maxpq.empty())
    {
        int U = maxpq.top().second;
        maxpq.pop();

        for (auto i = adjacent[U].begin(); i != adjacent[U].end(); ++i)
        {
            int V = (*i).first;
            int w = (*i).second;

            if (distance[V] > distance[U] + w)
            {
                distance[V] = distance[U] + w;
                maxpq.push(make_pair(distance[V], V));
            }
        }
    }

    return distance;
}

int main()
{

    int n, m;
    cin >> n >> m;
    G g(n);
    for (int i = 0; i < m; i++)
    {
        int U, V, W;
        cin >> U >> V >> W;
        g.add(U - 1, V - 1, W);
    }
    int s; cin >> s;
    vector<int> shortest = g.pathshortestortest(s - 1);
    int dist = shortest[shortest.size() - 1];
    if (dist < INFTY)
        cout << dist;
    else
        cout << -1;
    return 0;
}