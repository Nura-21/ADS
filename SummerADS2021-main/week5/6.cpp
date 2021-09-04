#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int used[100][100];
int n;
queue<pair<int, int> > q;

void tryStep(int x, int y, int p){
    if(x >= 0 && y >= 0){
        if(x < n && y < n){
            if(used[x][y] == -1){
                used[x][y] = p + 1;
                q.push(make_pair(x, y));
            }
        }
    }
}

int main(){
    int x, y, s, t;
    cin >> n;
    cin >> x >> y >> s >> t;
    x--;
    y--;
    s--;
    t--;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            used[i][j] = -1;
        }
    }

    used[x][y] = 0;
    q.push(make_pair(x, y));

    while(!q.empty()){
        pair<int, int>  cur = q.front();
        q.pop();
        tryStep(cur.first + 1, cur.second, used[cur.first][cur.second]);
        tryStep(cur.first - 1, cur.second, used[cur.first][cur.second]);
        tryStep(cur.first, cur.second + 1, used[cur.first][cur.second]);
        tryStep(cur.first, cur.second - 1, used[cur.first][cur.second]);
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << used[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}