#include <bits/stdc++.h>
  
using namespace std;
long long binarySearchFirst(long long arr[], long long l, long long r, long long x){
    if (r >= l) {
        long long mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearchFirst(arr, l, mid - 1, x);
        return binarySearchFirst(arr, mid + 1, r, x);
    }
    return -1;
}

long long binarySearchSecond(long long arr[], long long l, long long r, long long x){
    if (r >= l) {
        long long mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearchSecond(arr, mid + 1, r, x);
        return binarySearchSecond(arr, l, mid - 1, x);
    }
    return -1;
}

int main()
{
    long long t; cin >> t; 
    long long a[t];
    for(long long i = 0; i < t; ++i){
        cin >> a[i];
    }
    long long n,m; cin >> n >> m;
    long long b[n][m];
    for(long long i = 0 ; i < n; ++i){
        for(long long j = 0; j < m; ++j){
            cin >> b[i][j];
        }
    }
    /*
    for(int i = 0; i < n; ++i){
        if(i % 2 == 0){
            for(int j = m - 1; j >= 0; --j){
                cin >> b[i][j];
            }
        }else{
            for(int j = 0; j < m; ++j){
                cin >> b[i][j];
            }
        }
    }*/

    for(long long k = 0; k < t; ++k){
        for(long long i = 0; i < n; ++i){
                if(i % 2 == 0){
                    if(binarySearchSecond(b[i], 0 , m - 1, a[k]) != -1){
                        cout << i << " " << binarySearchSecond(b[i], 0 , m - 1, a[k]) << endl;
                        break;
                    }else if( i + 1 == n){
                        cout << -1 << endl;
                        break;
                    }
                }else{
                    if(binarySearchFirst(b[i], 0 , m - 1, a[k]) != -1){
                        cout << i << " " << binarySearchFirst(b[i], 0 , m - 1, a[k]) << endl;
                        break;
                    }else if( i + 1 == n){
                        cout << -1 << endl;
                        break;
                    }
                }

        }
    }
}