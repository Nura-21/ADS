#include <iostream>
#include <vector>

using namespace std;


vector<long long> p_pow;

long long f(string s){
    long long p = 31;
    p_pow.push_back(1);
    long long n = s.size();
    for(int i = 1; i <= n; ++i){
        p_pow.push_back(p_pow[i-1] * p);
    }

    long long hash = 0;
    for(int i = 0; i < n; ++i){
        hash += (s[i] - 'a' + 1) * p_pow[i];
    }

    return hash;
}


int main(){

    string s;
    getline(cin, s);

    cout << f(s) << endl;

    return 0;
}