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

    void find_full_nodes(node * current){
        if (current != NULL){
            find_full_nodes(current->left);
            if(current->right != NULL and current->left != NULL){full_nodes.push_back(current->val);}
            find_full_nodes(current->right);
        }   
    }

    void find_half_nodes(node * current){
        if (current != NULL){
            find_half_nodes(current->left);
            if((current->right != NULL and current->left == NULL) or (current->right == NULL and current->left != NULL)){half_nodes.push_back(current->val);}
            find_half_nodes(current->right);
        }   
    }

    int rightmost(node * current){
        if(current == NULL) return -1;
        if(current->right == NULL) return current->val;
        return rightmost(current->right);
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
    void count_height(){
        cout << height(_root);
    }
    void count_nodes(){
        cout << count_nodes(_root);
    }

    void second_max(){
        cout << second_max(_root);
    }

    void count_leaves(){
        count_leaves(_root);
        sort(leaves.begin(), leaves.end());
        for(int i = 0; i < leaves.size(); ++i){
            cout << leaves[i] << endl;
        }
    }

    void find_full_nodes(){
        find_full_nodes(_root);
        sort(full_nodes.begin(), full_nodes.end());
        for(int i = 0; i < full_nodes.size(); ++i){
            cout << full_nodes[i] << endl;
        }
    }
    void find_half_nodes(){
        find_half_nodes(_root);
        sort(half_nodes.begin(), half_nodes.end());
        for(int i = 0; i < half_nodes.size(); ++i){
            cout << half_nodes[i] << endl;
        }
    }
    bool is_balanced(){
        return is_balanced(_root);
    }
};

int main(){

    bst * tree = new bst();
    int n;
    while(cin >> n){
        if(n == 0) break;
        else tree->add(n);
    }

    if(tree->is_balanced()) {cout << "YES";}
    else{cout << "NO";}

}