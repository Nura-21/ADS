#include <iostream>

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
            cout << current->val << " " << level << endl;
            print(current->right, level + 1);
        }
    }

    int height(node * current){
        if(current == NULL){
            return 0;
        }
        int right_h = height(current->right);
        int left_h = height(current->left);
        return max(left_h,right_h) + 1;
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
        cout << endl;
    }
    void count_height(){
        cout << height(_root);
    }
};

int main(){

    bst * tree = new bst();
    int n;
    while(cin >> n){
        if(n == 0) break;
        else tree->add(n);
    }
    tree->count_height();
}