#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int p = 31;
int main(){
    vector<long long> p_pow(1000);
    p_pow[0] = 1;
    for (size_t i=1; i<p_pow.size(); ++i)
        p_pow[i] = p_pow[i-1] * p;
    int n;
    while(cin>>n){
        if(n==0)
            break;
        vector<string> patterns(n);
        map<string,int> freq;
        for(int i=0;i<n;i++)
            cin>>patterns[i];
        string text;cin>>text;
        vector<long long> h(text.length());
        for (size_t i=0; i<text.length(); ++i){
            h[i] = (text[i] - 'a' + 1) * p_pow[i];
            if (i)  h[i] += h[i-1];
        }
        int mx_freq = 0;
        for(auto pattern:patterns){
            long long h_s = 0;
            for (size_t i=0; i<pattern.length(); ++i)
                h_s += (pattern[i] - 'a' + 1) * p_pow[i];
            for(size_t i=0;i+pattern.length()-1<text.length();++i){
                long long cur_h = h[i+pattern.length()-1];
                if(i) cur_h -= h[i-1];
                if(cur_h==h_s*p_pow[i]){
                    freq[pattern]++;
                    mx_freq = max(freq[pattern],mx_freq);
                }
            }
        }
        cout<<mx_freq<<'\n';
        for(auto pattern:freq)
            if(pattern.second==mx_freq) cout<<pattern.first<<'\n';
    }
    return 0;
}