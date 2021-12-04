#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

const int MX_SIZE = 50500;

ll p = 31;
ll p_pow[MX_SIZE];

void find_pow()
{
    p_pow[0] = 1;
    for (int i = 1; i < MX_SIZE; i++)
        p_pow[i] = p_pow[i - 1] * p;
}

ll find_hash(string s)
{
    ll sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += s[i] * p_pow[i];
    return sum;
}

vector<ll> find_hash_prefix(string s)
{
    vector<ll> h(s.size());
    h[0] = s[0];
    for (int i = 1; i < s.size(); i++)
        h[i] = h[i - 1] + s[i] * p_pow[i];
    return h;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m; cin >> n >> m;
    
    vector<string> v1(n);
    vector<string> v2(m);
    find_pow();

    for(int i = 0; i < n; i++){
        cin >> v1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> v2[i];
    }

    for(int i = 0; i < m; i++){
        int cnt = 0;
        ll hash_t = find_hash(v2[i]);
        for(int j = 0; j < n; j++){
            vector<ll> h = find_hash_prefix(v1[j]);
            int ssize = v1[j].size();
            int tsize = v2[i].size();
            for (int k = 0; k <= ssize - tsize; k++){
                int j = k + tsize - 1;
                ll hash_i_j = h[j];
                if (k)
                    hash_i_j -= h[k - 1];
                if (hash_t * p_pow[k] == hash_i_j)
                    cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}