#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 26;

class node{
    public:
    char value;
    node * ch[N];
    int cnt;
    node (char value){
        cnt = 1;
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
                cur->cnt++;
            }else{
                node * temp = new node(s[i]);
                cur->ch[s[i] - 'a'] = temp;
                cur = temp;
            }
        }
    }

    void search(node * temp,string s){
        if(s != ""){
            cout << s << " - " << temp->cnt << endl;
        }
        for(int i = 0; i < N; ++i){
            if(temp->ch[i] != NULL){
                search(temp->ch[i], s + temp->ch[i]->value);
            }
        }
    }

};

int main(){
    Trie * trie = new Trie();

    int n; cin >> n;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        trie->insert(s);
    }
    trie->search(trie->root, "");
}