#include <bits/stdc++.h>

using namespace std;

vector<int> graph[100000];
bool used[100000];
int n;
vector<int> ans;
void check(int v, int p = -1) {    //p - прямой предок
    used[v] = true;

    for (int u: graph[v]) {
        if (!used[u]) {
            dfs(u, v);
        } else if (u != p) {
            cout << "Graph has cycles.";
            exit(0);    //Полностью выйти из программы.
        }
    }
    ans.push_back(v);
}

void dfs(int v){
    used[v] = true;
    for(int i = 0; i < n; ++i){
        if(!used[i]){
            dfs(i);
        }
    }
    ans.push_back(v + 1);
}

int main() {
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);
    }

    //Проверяем отдельно каждую вершину, так как
    //граф может быть несвязным, но всё равно иметь циклы
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            check(i);
        }
    }

    for(auto i : ans){
        cout << i << " ";
    }
    //Если мы ещё не вышли не вышли из программы, в графе нет циклов.
    cout << "Graph has no cycles.";
}