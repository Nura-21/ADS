#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    struct Node* left, *right;
    int key;
};
 
struct Node* newNode(int key)
{
    struct Node* ptr = new Node;
    ptr->key = key;
    ptr->left = ptr->right = NULL;
    return ptr;
}
 
// Standard BST insert function
struct Node* insert(struct Node* root, int key)
{
    if (!root)
        root = newNode(key);
    else if (root->key > key)
        root->left = insert(root->left, key);
    else if (root->key < key)
        root->right = insert(root->right, key);
    return root;
}
 
// This function returns distance of x from
// root. This function assumes that x exists
// in BST and BST is not NULL.
int distanceFromRoot(struct Node* root, int x)
{
    if (root->key == x)
        return 0;
    else if (root->key > x)
        return 1 + distanceFromRoot(root->left, x);
    return 1 + distanceFromRoot(root->right, x);
}
 
// Returns minimum distance between a and b.
// This function assumes that a and b exist
// in BST.
int distanceBetween2(struct Node* root, int a, int b)
{
    if (!root)
        return 0;
 
    // Both keys lie in left
    if (root->key > a && root->key > b)
        return distanceBetween2(root->left, a, b);
 
    // Both keys lie in right
    if (root->key < a && root->key < b) // same path
        return distanceBetween2(root->right, a, b);
 
    // Lie in opposite directions (Root is
    // LCA of two nodes)
    if (root->key >= a && root->key <= b)
        return distanceFromRoot(root, a) +
               distanceFromRoot(root, b);
}
 
int rightmost(Node * cur){
    if(cur == NULL){return -1;}
    if(cur->right == NULL){
        return cur->right->key;
    }
    return rightmost(cur->right);
}

int leftmost(Node * cur){
    if(cur == NULL){return -1;}
    if(cur->left == NULL){
        return cur->left->key;
    }
    return leftmost(cur->left);
}
int findDistWrapper(Node *root, int a, int b)
{
   if (a > b)
     swap(a, b);
   return distanceBetween2(root, a, b);  
}
 
// Driver code
int main()
{   int n; cin >> n;
    struct Node* root = NULL;
    int x; cin >> x;
    root = insert(root, x);
    int mx = -1, mn = 1000000000;
    for(int i = 0; i < n - 1; i++){
        cin >> x;
        insert(root, x);
    }
    cout << root->key << " ";
    cout << leftmost(root) << " " << rightmost(root) << endl;
    cout << findDistWrapper(root, leftmost(root), rightmost(root));
    return 0;
}