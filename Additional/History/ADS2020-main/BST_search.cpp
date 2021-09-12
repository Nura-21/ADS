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
    int maxSize;
    BST(int maxSize)
    {
        root = NULL;
        this->maxSize = maxSize;
    }

    Node *insert(Node *node, int data)
    {
        if (node == NULL)
        {
            node = new Node(data);
            return node;
        }
        if (node->data == data)
        {
            return node;
        }
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

    void printTree(Node *node, int level)
    {
        if (node == NULL)
        {
            level--;
            return;
        }
        printTree(node->left, level + 1);
        for (int i = 0; i < level; i++)
            cout << ".";
        cout << node->data << endl;
        printTree(node->right, level + 1);
        level--;
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
    bool searchNode(Node *node, int data)
    {
        {
            if (node == NULL)
                return false;
            else if (node->data == data)
            {
                return true;
            }

            if (data <= node->data)
                searchNode(node->left, data);
            else if (data > node->data)
                searchNode(node->right, data);
        }
    }
    Node *deleteNode(Node *node, int data)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                return NULL;
            }
            else if (node->left == NULL)
            {
                node = node->right;
            }
            else if (node->right == NULL)
            {
                node = node->left;
            }
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
    BST bst(10000);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        bst.insert(bst.root, t);
    }
    bst.inOrder(bst.root);

    // freopen("test1.txt", "r", stdin);
    // while (cin >> s)
    // {
    //     if (s == "ADD")
    //     {
    //         cin >> t;
    //         if (bst.searchNode(bst.root, t))
    //             cout << "ALREADY" << endl;
    //         else
    //         {
    //             bst.root = bst.insert(bst.root, t);
    //             cout << "DONE" << endl;
    //         }
    //     }
    //     else if (s == "DELETE")
    //     {
    //         cin >> t;
    //         if (bst.searchNode(bst.root, t))
    //         {
    //             bst.root = bst.deleteNode(bst.root, t);
    //             cout << "DONE" << endl;
    //         }
    //         else
    //             cout << "CANNOT" << endl;
    //     }
    //     else if (s == "SEARCH")
    //     {
    //         cin >> t;
    //         cout << (bst.searchNode(bst.root, t) ? "YES" : "NO") << endl;
    //     }
    //     else if (s == "PRINTTREE")
    //         bst.printTree(bst.root, 0);
    // }
    return 0;
}