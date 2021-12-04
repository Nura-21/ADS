#include <iostream>
using namespace std;

int binarySearchFirst(int arr[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearchFirst(arr, l, mid - 1, x);
        return binarySearchFirst(arr, mid + 1, r, x);
    }
    return -1;
}

int binarySearchSecond(int arr[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearchSecond(arr, mid + 1, r, x);
        return binarySearchSecond(arr, l, mid - 1, x);
    }
    return -1;
}


int main(){

    int a;
    cin >> a;
    int ar[a];
    for (int i = 0; i < a; ++i){
        cin >> ar[i];
    }

    int n, m, k = 0;
    cin >> n >> m;

    int mas[n][m];

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> mas[i][j];
        }
    }
    
    for (int x = 0; x < a; ++x){
        for (int i = 0; i < n; i++){
            if (i % 2 == 1){
                if (binarySearchFirst(mas[i], 0, m - 1, ar[x]) != -1){
                    cout << i << " " << binarySearchFirst(mas[i], 0, m - 1, ar[x]) << endl;
                    break;
                } else if (i + 1 == n){
                    cout << -1 << endl;
                    break;
                }

            } else{
                if (binarySearchSecond(mas[i], 0, m - 1, ar[x]) != -1){
                    cout << i << " " << binarySearchSecond(mas[i], 0, m - 1, ar[x]) << endl;
                    break;
                } else if (i + 1 == n){
                    cout << -1 << endl;
                    break;
                }
            }
        }
    }

    return 0;
}