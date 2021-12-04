#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 26;

class node{
    public:
    char value;
    node * ch[N];
    node (char value){
        this->value = value;
        for(int i = 0; i < N; i++){
            ch[i] = NULL;
        }
    }
};

class Trie{
    public:
    int cnt;
    node * root;
    Trie(){
        root = new node(' ');
        cnt = 0;
    }

    void insert(string s){
        node * cur = root;
        for(int i = 0; i < s.length(); i++){
            if(cur->ch[s[i] - 'a'] != NULL){
                cur = cur->ch[s[i] - 'a'];
            }else{
                node * temp = new node(s[i]);
                cur->ch[s[i] - 'a'] = temp;
                cur = temp;
                cnt++;
            }
        }
    }
};

int main(){
    string s;
    cin >> s;
    Trie * trie = new Trie();
    for(int i = 0; i < s.length(); i++){
        trie->insert(s.substr(i));
    }
    cout << trie->cnt;
}