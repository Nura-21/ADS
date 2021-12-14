#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    int h = 0;
    int cnt = 0;
    vector<int> leaves;
    vector<int> full_nodes;
    vector<int> half_nodes;
    node * _root;
    
    node * add(node * current, int x){
        if(current == NULL) return new node(x);

        if(current->val < x){
            current->right = add(current->right, x);
        }

        if(current->val > x){
            current->left = add(current->left, x);
        }

        return current;
    }

    bool find(node * current, int x){
        if(current == NULL) return false;
        if(current->val == x) return true;
        if(current->val > x) return find(current->left, x);
        return find(current->right, x);
    }

    void print(node * current, int level){
        if(current != NULL){
            if(h < level){h = level;}
            print(current->left, level + 1);
            cout << current->val << " "<< level << endl;
            print(current->right, level + 1);
        }
    }

    int count_nodes(node * current){
        if (current != NULL){
            count_nodes(current->left);
            cnt++;
            count_nodes(current->right);
        }   
        return cnt;
    }

    void count_leaves(node * current){
        if (current != NULL){
            count_leaves(current->left);
            if(current->right == NULL and current->left == NULL){leaves.push_back(current->val);}
            count_leaves(current->right);
        }   
    }

    int rightmost(node * current){
        if(current == NULL) return -1;
        if(current->right == NULL) return current->val;
        return rightmost(current->right);
    }

    node * del(node * current, int x){
        if(current == NULL) return NULL;
        if(current->val == x){
            if(current->right == NULL && current->left == NULL){
                delete current;
                return NULL;
            }else if(current->left != NULL && current->right == NULL){
                node * temp = current->left;
                delete current;
                return temp;
            }else if(current->right != NULL && current->left == NULL){
                node * temp = current->right;
                delete current;
                return temp;
            }else if(current->right != NULL && current->left != NULL){
               current->val = rightmost(current->left);
               current->left = del(current->left, current->val);
            }
        }else if(current->val < x){
            current->right = del(current->right, x);
            return current;
        }else if(current->val > x){
            current->left = del(current->left, x);
            return current;
        }
        return current;
    }


    bst(){
        _root = NULL;
    }

    void add(int x){
        if(find(x) == false){
            node * res = add(_root, x);
            if(_root == NULL){
                _root = res;
            }
        }
    }

    void del(int x){
        del(_root, x);
    }

    bool find(int x){
        return find(_root, x);
    }

    void print(){
        print(_root, 0);
    }

    vector<int> leaf(){
        count_leaves(_root);
        leaves.push_back(_root->val);
        sort(leaves.begin(), leaves.end());
        return leaves;
    }

    int findLevel(node *root, int k, int level){
        if (root == NULL)
            return -1;
        if (root->val == k)
            return level;
    
        int l = findLevel(root->left, k, level+1);
        return (l != -1)? l : findLevel(root->right, k, level+1);
    }

    node *findDistUtil(node* root, int n1, int n2, int &d1, int &d2, int &dist, int lvl){
        if (root == NULL) return NULL;
        if (root->val == n1){
            d1 = lvl;
            return root;
        }
        if (root->val == n2){
            d2 = lvl;
            return root;
        }
        node *left_lca  = findDistUtil(root->left, n1, n2, d1, d2, dist, lvl+1);
        node *right_lca = findDistUtil(root->right, n1, n2, d1, d2, dist, lvl+1);
        if (left_lca && right_lca){
            dist = d1 + d2 - 2*lvl;
            return root;
        }
        return (left_lca != NULL)? left_lca: right_lca;
    }
    
    int findDistance(node *root, int n1, int n2){
        int d1 = -1, d2 = -1, dist;
        node *lca = findDistUtil(root, n1, n2, d1, d2, dist, 1);
        if (d1 != -1 && d2 != -1)
            return dist;
        if (d1 != -1){
            dist = findLevel(lca, n2, 0);
            return dist;
        }
        if (d2 != -1){
            dist = findLevel(lca, n1, 0);
            return dist;
        }
    
        return -1;
    }

    int find(int n1, int n2){
        return findDistance(_root, n1, n2);
    }
};

int main(){

    bst * tree = new bst();
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        tree->add(x);
    }

    vector<int> ans = tree->leaf();
    int mx = -1;
    for(int i = 0; i < ans.size(); ++i){
        for(int j = i + 1; j < ans.size(); ++j){
            if(mx <  tree->find(ans[i],ans[j])){
                mx = tree->find(ans[i],ans[j]);
            }
        }
    }
    cout << mx + 1 << endl;
}