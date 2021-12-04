#include <bits/stdc++.h>
using namespace std;
const int N = 10;

int pow(int x, int a){
    int ans = 1;
    while (a--){
        ans *= x;
    }
    return ans;
}

class Node{
public:
    char value;
    Node *ch[N];
    int cnt, height;
    string city = "";
    Node(char value)
    {
        this->value = value;
        for (int i = 0; i < N; i++)
            ch[i] = NULL;
        cnt = 0;
    }
};

class Trie{
public:
    Node *root;
    Trie(){
        root = new Node(' ');
    }

    void insert(string s, string gorod){
        Node *cur = root;

        for (int i = 0; i < s.size(); i++){
            if (cur->ch[s[i] - '0'] != NULL){
                cur = cur->ch[s[i] - '0'];
            }else{
                Node *node = new Node(s[i]);
                cur->ch[s[i] - '0'] = node;
                cur = node;
                node->height = i + 1;
            }
        }
        cur->city = gorod;
    }

    int ans(Node *node, int m){
        int answer = 0;
        if (node->city == ""){
            for (int i = 0; i < N; i++){
                if (node->ch[i] != NULL){
                    node->cnt += ans(node->ch[i], m);
                }
            }
        }else{
            node->cnt = pow(10, m - node->height);
            for (int i = 0; i < N; i++){
                if (node->ch[i] != NULL){
                    answer += ans(node->ch[i], m);
                }
            }
            cout << node->city << " " << node->cnt - answer << endl;
        }
        return node->cnt;
    }
};
int main(){
    Trie *trie = new Trie();
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++){
        string city, num;
        cin >> num >> city;
        trie->insert(num, city);
    }
    trie->ans(trie->root, m);
    return 0;
}