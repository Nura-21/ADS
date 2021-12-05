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
    int used[n][n];
    Graph g(n);
    Graph g2(n);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i != j){
                used[i][j] = -1;
            }else{
                used[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++){
        int U, V;
        cin >> U >> V;
        --U; --V;
        g.add(U, V, 1);
        g.add(V , U, 1);
        used[V][U] = 1;
        used[U][V] = 1;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(used[i][j] == -1){
                g2.add(i, j, 1);
            }
        }
    }

    vector<int> shortest = g.shortest(0);
    vector<int> shortest_2 = g2.shortest(0);
    int m1 = -1;
    int m2 = -1;
    for(auto i : shortest){
        if (m1 < i and i != inf) m1 = i;
        //cout << i << " ";
    }
    //cout << endl;
    for(auto i : shortest_2){
        if (m2 < i and i != inf) m2 = i;
        //cout << i << ' ';
    }

    cout << max(m1, m2);
    
    // if (shortest[shortest.size() - 1] < inf){
    //     cout << shortest[shortest.size() - 1] << endl;
    // }else{
    //     cout << -1 << endl;
    // }
}