#include <iostream>
#include <vector>

using namespace std;


vector<long long> p_pow;

void f(string s, string t){
    long long p = 31;
    p_pow.push_back(1);
    long long n = s.size();
    for(int i = 1; i <= n; ++i){
        p_pow.push_back(p_pow[i-1] * p);
    }

    long long hash[n];
    for(int i = 0; i < n; ++i){
        hash[i] = (s[i] - 'a' + 1) * p_pow[i];
        if(i != 0){
            hash[i] += hash[i-1];
        }
    }

    long long hash2 = 0;
    long long m = t.size();
    for(int i = 0; i < m; ++i){
        hash2 += (t[i] - 'a' + 1) * p_pow[i];
    }

    for(int i = 0; i <= n - m; ++i){
        int j = i + m - 1;
        long long temp = hash[j];
        
        if(i != 0){
            temp -= hash[i-1];
        }
        if(temp == hash2 * p_pow[i]){
            cout << i << " ";
        }
        
    }
}


int main(){

    string s,t;
    getline(cin, s);
    getline(cin, t);

    f(s,t);

    return 0;
}