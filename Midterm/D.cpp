#include <iostream>
using namespace std;

bool is(int arr[], int n, int x){
    int l = 0;
    int r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (x == arr[mid]){return true;}
        else if (x < arr[mid]){l = mid - 1;}
        else{r = mid + 1;}
    }
    return false;
}

int is_r(int arr[], int n, int x){
    int l = 0;
    int r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (x == arr[mid]){return true;}
        else if (x < arr[mid]){l = mid + 1;}
        else{r = mid - 1;}
    }
    return false;
}

int find(int arr[], int n, int x){
    int l = 0;
    int r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (x == arr[mid]){return mid;}
        else if (x < arr[mid]){l = mid - 1;}
        else{r = mid + 1;}
    }
    return -1;
}

int find_reverse(int arr[], int n, int x){
    int l = 0;
    int r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (x == arr[mid]){return mid;}
        else if (x < arr[mid]){l = mid + 1;}
        else{r = mid - 1;}
    }
    return -1;
}

int main(){
    int t; cin >> t;
    int a[t];
    for(int i = 0; i < t; ++i){
        cin >> a[i];
    }
    int n,m; cin >> n >> m;
    int b[n][m];
    for(int i = 0; i < n; ++i){
            for(int j = 0 ; j < m; ++j){
                cin >> b[i][j];
            }
            
    }

    cout << is_r(b[0],m,25);

}