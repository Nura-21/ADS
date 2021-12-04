#include <iostream>
#include <vector>
using namespace std;

int mini = 0;

const int SIZE = 26;
struct Node{
    Node * children[SIZE];
    int cnt;
    Node(){
        for(int i=0;i<SIZE;i++){
            children[i] = NULL;
        }
        cnt = 0;
    }
};


struct Trie {
    Node * root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * cur = root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if(cur->children[index]==NULL){
                cur->children[index] = new Node();
            }
            cur = cur->children[index];
            cur->cnt += 1;
            /* cout << char(index+97) << ' ' << cur->cnt << endl; */
        }
    }
    void startsWith(string prefix) {
        Node * cur = root;
        for(int i=0;i<prefix.size();i++){
            int index = prefix[i] - 'a';
            if(cur->children[index] == NULL){
                mini = 0;
                break;
            }
            
            cur = cur->children[index];
            /* cout << cur->cnt << ' ' << mini << ' ' << index << endl; */
            mini = min(cur->cnt, mini);
        }
    }
};



int main(){
    Trie trie;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        string k ="";
        for(int i=s.size()-1;i>=0;i--){
            k += s[i];
        }
        /* cout << k << endl; */
        trie.insert(k);
    }
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        string k ="";
        for(int i=s.size()-1;i>=0;i--){
            k += s[i];
        }
        /* cout << k << endl; */
        mini = 2147483647;
        trie.startsWith(k);
        if(mini == 2147483647) cout << 0 << endl;
        else cout << mini << endl;
    }
    return 0;
}