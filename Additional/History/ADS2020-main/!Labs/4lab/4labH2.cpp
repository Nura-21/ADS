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
        cout << node->data << endl;
        inOrder(node->right);
    }

    void printLeaves(Node *node)
    {
        if (node == NULL)
            return;
        printLeaves(node->left);
        if (node->left == NULL && node->right == NULL)
            cout << node->data << endl;
        printLeaves(node->right);
    }

    void printForks(Node *node)
    {
        if (node == NULL)
            return;
        printForks(node->left);
        if (node->left != NULL && node->right != NULL)
            cout << node->data << endl;
        printForks(node->right);
    }

    void printMonoForks(Node *node)
    {
        if (node == NULL)
            return;
        printMonoForks(node->left);
        if (node->left == NULL ^ node->right == NULL)
            cout << node->data << endl;
        printMonoForks(node->right);
    }

    int heightOfTree(Node *node)
    {
        if (node == NULL)
            return 0;
        return max(heightOfTree(node->left), heightOfTree(node->right)) + 1;
    }
    bool isBalanced(Node *node)
    {
        if (node == NULL)
            return true;
        int l_height = heightOfTree(node->left);
        int r_height = heightOfTree(node->right);
        if (abs(l_height - r_height) <= 1 and isBalanced(node->left) and isBalanced(node->right))
            return true;
        return false;
    }

    int countNodes(Node *node)
    {
        if (node->left == NULL && node->right == NULL)
            return 1;
        int left, right;
        if (node->left != NULL)
            left = countNodes(node->left);
        else
            left = 0;
        if (node->right != NULL)
            right = countNodes(node->right);
        else
            right = 0;
        return left + right + 1;
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

    Node *findSecondMax(Node *node)
    {
        Node *maxNode = findMax(node);
        if (maxNode->left != NULL)
            return findMax(maxNode->left);
        else
        {
            while (node->right != maxNode)
                node = node->right;
            return node;
        }
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
    cout << (bst->isBalanced(bst->root) ? "YES" : "NO");
    return 0;
}