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
private:
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
            cout << current->val << endl;
            print(current->right, level + 1);
        }
    }

    void find_full_nodes(node * current, int x){
        if (current != NULL){
            find_full_nodes(current->left,x);
            if(current->val == x){
                cout << current->val << " ";
                if(current->left != NULL){
                    cout << current->left->val << " ";
                } 
                if(current->right != NULL){
                    cout << current->right->val << endl;
                }
            }
            find_full_nodes(current->right,x);
        }   
    }

    bool find_full(node * current, int x){
        if(current->val == x){
            cout << current->val << " ";
            if(current->left != NULL){
                cout << current->left->val << " ";
            }else if(current->right != NULL){
                cout << current->right->val << endl;
            }
        }
        if(current->val > x) return find(current->left, x);
        return find(current->right, x);
    }


public:

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

    bool find(int x){
        return find(_root, x);
    }

    bool find_full(int x){
        return find(_root, x);
    }

    void print(){
        print(_root, 0);
    }

    void find_full_nodes(int x){
        find_full_nodes(_root,x);
    }

};

int main(){

    bst * tree = new bst();
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        tree->add(x);
    }
    int k; cin >> k;
    tree->find_full_nodes(k);;

}