#include <iostream>
#include <vector>
using namespace std;

//array must be sorted
bool find(vector<int> & a, int n){
    int left = 0;
    int right = (int)a.size() - 1;
    while (right >= left) {
        int mid = (left + right) / 2;
        if (a[mid] == n)
            return true;
        if (a[mid] < n)
            left = mid + 1;
        if (a[mid] > n)
            right = mid - 1;
    }
    return false;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    while (k--){
        int x;
        cin >> x;
        if (find(v,x)){cout << "YES" << endl;}     
        else{cout << "NO" << endl;}
    }
}