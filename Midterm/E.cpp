#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sum = 0;

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
    node * _root;
    int s;
    int a[];
    
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

    void find_full_nodes(node * current){
        if (current != NULL){
            find_full_nodes(current->left);
            if(current->right != NULL and current->left != NULL){cnt++;}
            find_full_nodes(current->right);
        }   
    }

    int rightmost(node * current){
        if(current == NULL) return -1;
        if(current->right == NULL) return current->val;
        return rightmost(current->right);
    }

    int leftmost(node * current){
        if(current == NULL) return -1;
        if(current->left == NULL) return current->val;
        return leftmost(current->left);
    }

    int height(node *node){
        if (node == NULL)
            return 0;
        return max(height(node->right), height(node->left)) + 1;
    }

    bool is_balanced(node *node){
        if (node == NULL)
            return true;
        if (std::abs(height(node->right) -  height(node->left)) <= 1 and
            is_balanced(node->right) and is_balanced(node->left))
            return true;
        return false;
    }

    int second_max(node * current){
        del(_root,rightmost(_root)); 
        return rightmost(_root);
    }

    int solve(node * current, int n){
        cout << cnt <<" ";
        for(int i = 1; i < n; ++i){
                
        }
        
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


    bst(int n){
        _root = NULL;
        s = n;
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

};

int main(){
    int n;
    cin >> n;
    bst * tree = new bst(n);
    
    while(n--){
        int x; cin >> x;
        tree->add(x);
    }

    cout << sum ;
}