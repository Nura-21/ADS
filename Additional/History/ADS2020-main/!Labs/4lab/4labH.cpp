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

    void analyze(Node *node)
    {
        if (node == NULL)
            return;
        bool check = balanced(node);
        if (!check)
        {
            cout << "NO";
            exit(0);
        }
        analyze(node->left);
        analyze(node->right);
    }
    bool balanced(Node *node)
    {
        int l_deep = 0;
        int r_deep = 0;
        if (node->left != NULL)
            l_deep = heightOfTree(node->left) + 1;
        if (node->right != NULL)
            r_deep = heightOfTree(node->right) + 1;
        return abs(l_deep - r_deep) <= 1;
    }
    int heightOfTree(Node *node)
    {
        int left, right;
        if (node == 0)
            return 0;
        if (node->left != NULL)
            left = heightOfTree(node->left);
        else
            left = -1;

        if (node->right != NULL)
            right = heightOfTree(node->right);
        else
            right = -1;
        int mx = max(left, right);
        return mx + 1;
    }
};

int main()
{
    BST *bst = new BST();
    int n;
    // freopen("test1.txt", "r", stdin);
    cin >> n;
    while (n != 0)
    {
        bst->root = bst->insert(bst->root, n);
        cin >> n;
    }
    bst->analyze(bst->root);
    cout << "YES";
    return 0;
}