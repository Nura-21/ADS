#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    Node *insert(Node *node, int data)
    {
        if (node == NULL)
        {
            node = new Node(data);
            return node;
        }
        if (node->data == data)
            return node;
        if (data <= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        return node;
    }

    void findForks(Node *node, int &cnt)
    {
        if (node == NULL)
            return;
        findForks(node->left, cnt);
        if (node->left != NULL && node->right != NULL)
            cnt++;
        findForks(node->right, cnt);
    }
};

int main()
{
    // freopen("test1.txt", "r", stdin);
    BST *bst = new BST();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        bst->root = bst->insert(bst->root, t);
    }
    int cnt = 0;
    bst->findForks(bst->root, cnt);
    cout << cnt;
    return 0;
}