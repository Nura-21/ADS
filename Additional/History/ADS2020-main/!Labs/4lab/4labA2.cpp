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

    void inOrder(Node *node)
    {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    int heightOfTree(Node *node)
    {
        if (node == NULL)
            return 0;
        return max(heightOfTree(node->left), heightOfTree(node->right)) + 1;
    }

    Node *findMin(Node *node)
    {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node *findMax(Node *node)
    {
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    Node *deleteNode(Node *node, int data)
    {
        if (node == NULL)
            return NULL;
        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else
        {
            if (node->left == NULL && node->right == NULL)
                return NULL;
            else if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            else
            {
                Node *tmp = findMax(node->left);
                node->data = tmp->data;
                node->left = deleteNode(node->left, tmp->data);
            }
        }
        return node;
    }
};

int main()
{
    BST *bst = new BST();
    int n;
    freopen("main.txt", "r", stdin);
    cin >> n;
    while (n != 0)
    {
        bst->root = bst->insert(bst->root, n);
        cin >> n;
    }
    cout << bst->heightOfTree(bst->root);

    return 0;
}