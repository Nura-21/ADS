#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string restore(vector<ll> v){
    string ans = "";
    for(int i = v.size() - 1 ; i >= 0; i--){
        if(i == 0){
            ans = char(v[0] + 97) + ans;
        }else{
            ll sum = v[i];
            sum -= v[i - 1];
            //cout << sum << " ";
            ans = char((sum / pow(2,i)) + 97) + ans;
        }
    } 
    //cout << endl;   
    return ans;
}

int main()
{   
    int n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << restore(v) << endl;
}