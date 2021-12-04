#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int K = 26;
const int N = 1e6;
struct vertex{
    int next[K],cnt;
    bool leaf;
};
vertex t[N];
int sz;
void init(){
    for(int j = 0; j < K; ++j)
        t[0].next[j] = -1;  
    sz = 1;
    t[0].cnt = 0;
}
void add_string(string s){
    int v = 0;
    for(size_t i=0;i<s.length();i++){
        int c = s[i] - 'a';//Depend on alphabet
        if(t[v].next[c]==-1){
            for(int j = 0; j < K; ++j){
                t[sz].next[j] = -1;
                if(v!=0)
                    t[sz].cnt = 0;
            }
            t[v].next[c] = sz++;
        }
        if(v!=0)
            t[v].cnt++;
        v = t[v].next[c];
    }
    t[v].cnt++;
    t[v].leaf = true;
}
int search(string s){
    int v = 0;
    for(int i = 0; i < s.size(); ++i){
        int c = s[i] - 'a';
        if(t[v].next[c] == -1) return 0;
        v = t[v].next[c];
    }
    return t[v].cnt;
}
int main(){
    int n,m;
    cin>>n>>m;
    init();
    for(int i=0;i<n;i++){
        string s;cin>>s;
        reverse(s.begin(),s.end());
        add_string(s);
    }
    for(int i=0;i<m;i++){
        string suf;cin>>suf;
        reverse(suf.begin(),suf.end());
        cout<<search(suf)<<'\n';
    }
    return 0;
}