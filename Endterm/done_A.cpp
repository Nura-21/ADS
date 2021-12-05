#include <bits/stdc++.h>
#define inf 1e9

using namespace std;

struct Graph{
    int v;
    vector<pair<int, int>> * adj;

    Graph(int v){
        this->v = v;
        adj = new vector<pair<int, int>>[v];
    };

    void add(int u, int v, int w){
        adj[v].push_back(make_pair(u, w));
        adj[u].push_back(make_pair(v, w));
    }

    vector<int> shortest(int s){
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
        
        vector<int> distance(v, inf);

        pq.push(make_pair(0, s));
        distance[s] = 0;

        while (!pq.empty()){
            int U = pq.top().second;
            pq.pop();
            for (auto i = adj[U].begin(); i != adj[U].end(); ++i){
                int V = i->first;
                int w = i->second;

                if (distance[V] > distance[U] + w){
                    distance[V] = distance[U] + w;
                    pq.push(make_pair(distance[V], V));
                }
            }
        }
        return distance;
    }
};


int main(){

    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++){
        int U, V, W;
        cin >> U >> V >> W;
        g.add(U - 1, V - 1, W);
    }
    int s, a, b, f;
    cin >> s >> a >> b >> f;
    vector<int> shortest;

    shortest = g.shortest(s - 1);
    int left = shortest[a - 1], right = shortest[b - 1];

    shortest = g.shortest(f - 1);
    left += shortest[b - 1];
    right += shortest[a - 1];

    shortest = g.shortest(a - 1);
    left += shortest[b - 1];
    right += shortest[b - 1];

    int dist;
    dist = min(left, right);
    if (dist < inf){
        cout << dist << endl;
    }else{
        cout << -1 << endl;
    }
}