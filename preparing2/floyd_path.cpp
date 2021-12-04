#include <bits/stdc++.h>
typedef long long ll;
#define MAXN 1e9

using namespace std;

int a[100][100]; 
int d[100][100];
int c[100][100];

void rec(int i, int j) {
    if (c[i][j] == -1) {
        cout << i + 1 << " " << j + 1 << endl;
        return;
    }
    rec(i, c[i][j]);
    rec(c[i][j], j);
}

int main() {
    int n, x, y, l;
    cin >> n;
    cin >> x >> y;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> l;
            // if(l == -1){
            //     a[j][i] = MAXN;
            // }else{
            //     a[i][j] = l;
            // }
            a[i][j] = l;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > 0) {
                d[i][j] = a[i][j];
            } else {
                d[i][j] = MAXN;
            }
            c[i][j] = -1;
        }
        d[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    c[i][j] = k;
                }
            }
        }
    }

    
    if(d[x - 1][y - 1] < MAXN){cout << d[x - 1][y - 1] << endl;}
    else{cout << -1 << endl;}

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    */
    return 0;
}