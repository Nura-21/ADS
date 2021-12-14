#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    long long left = 0, right = 1e15, mid, cnt, sum;
    while(right > left){
        cnt = 1, sum = 0, mid = (left + right) / 2;
        for (int i = 0; i < v.size(); i++){
            if(mid < sum + v[i]){
                cnt++; sum = 0;
            }
            if(mid < v[i]){
                cnt = k + 1;
            }
            sum += v[i];
        }
        if (cnt > k){
            left = mid + 1;
        }else{
            right = mid;
        }  
    }
    cout << left << endl;
}