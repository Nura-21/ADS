#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
const int N = 10;

class Node
{
public:
    char value;
    Node *ch[N];
    string city;
    int cnt;
    Node(char value, string city)
    {
        this->city = city;
        this->value = value;
        for (int i = 0; i < N; i++)
            ch[i] = NULL;
        cnt = 1;
    }
};

class Trie
{
public:
    Node *root;
    int m;
    Trie(int m)
    {
        this->m = m;
        root = new Node(' ', " ");
    }

    void insert(string s, string city)
    {
        Node *cur = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (cur->ch[s[i] - '0'] != NULL)
            {
                cur = cur->ch[s[i] - '0'];
                cur->cnt++;
            }
            else
            {
                Node *node = new Node(s[i], (i == s.size() - 1 ? city : " "));
                cur->ch[s[i] - '0'] = node;
                cur = node;
            }
        }
    }

    int search(Node *node, string s, int cnt = 0)
    {
        if (node->city == " ")
        {
            for (int i = 0; i < N; i++)
                if (node->ch[i] != NULL)
                    cnt += search(node->ch[i], s + node->ch[i]->value);
            return cnt;
        }
        else
        {
            cnt = pow(10, m - s.size());
            for (int i = 0; i < N; i++)
                if (node->ch[i] != NULL)
                    cnt -= search(node->ch[i], s + node->ch[i]->value);
            cout << node->city << " " << cnt << endl;
            return pow(10, m - s.size());
        }
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    Trie *trie = new Trie(m);
    while (n--)
    {
        string numb, city;
        cin >> numb >> city;
        trie->insert(numb, city);
    }
    trie->search(trie->root, "");
    return 0;
}

// 4 9
// 831 NizhnyNovgorod
// 8313 Dzerzhinsk
// 83130 Sarov
// 83144 Balakhna

// Sarov 10000
// Dzerzhinsk 90000
// Balakhna 10000
// NizhnyNovgorod 890000