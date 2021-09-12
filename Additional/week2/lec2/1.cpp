#include <iostream>

using namespace std;


struct node{
    int val;
    node * left;
    node * right;
    int level;
    node(int x, int l):left(NULL),right(NULL),val(x),level(l){}
};

struct bst{
private:
    node * root;
    int height;
    void _print(node * _root){
        if(_root != NULL){
            _print(_root->left);
            cout << _root->val <<  " " << _root->level << endl;
            _print(_root->right);
        }
    }
    node * _add(node * _root, int x){
        if(_root == NULL){
            height = 1;
            _root = new node(x, 1);
        }else if(x < _root->val){
            if(_root->left == NULL){
                int _level = _root->level + 1;
                height = max(height, _level);
                _root->left = new node(x, _level);
            }else{
                _add(_root->left, x);
            }
        }else if(x > _root->val){
            if(_root->right == NULL){
                int _level = _root->level + 1;
                height = max(height, _level);
                _root->right = new node(x,_level);
            }else{
                _add(_root->right, x);
            }
        }
        return _root;
    }

    int _rightmost(node * _root){
        node * temp = _root;
        while(temp != NULL && temp->right != NULL){
            temp = temp->right;
        }
        if(temp == NULL) return -1;
        return temp->val;
    }

    node * _del(node * _root, int x){
        if(_root == NULL) return NULL;
        if(x == _root->val){
            if(_root->left == NULL && _root->right == NULL){
                delete _root;
                return NULL;
            }
            else if(_root->left != NULL && _root->right == NULL){
                node * temp = _root->left;
                delete _root;
                return temp;
            }
            else if(_root->right != NULL && _root->left == NULL){
                node * temp = _root->right;
                delete _root;
                return temp;
            }
            else if(_root->right != NULL && _root->left != NULL){
                _root->val = _rightmost(_root->left);
                _root->left = _del(_root->left, _root->val);
            }
        }else if(x < _root->val){
            _root->left = _del(_root->left, x);
            return _root;
        }else if(x > _root->val){
            _root->right = _del(_root->right, x);
            return _root;
        }
        return _root;
    }

    int _get2ndMax(node * root, node * prev){
        if(root != NULL){
            if(root->right != NULL){
                return _get2ndMax(root->right, root);
            }else if(root->left != NULL){
                return _rightmost(root->left);
            }else if(prev != NULL){
                return prev->val;
            }else{
                return -2;
            }
        }else{
            return -1;
        }
    }


public:
    bst(){
        root = NULL;
        height = 0;
    }

    void add(int x){
        this->root = _add(this->root, x);
    }

    void find(int x){

    }

    int getMax(){
        return _rightmost(this->root);
    }

    int get2ndMax(){
        return _get2ndMax(root, NULL);
    }

    void del(int x){
        this->root = _del(this->root, x);
    }
    void print(){
       _print(this->root);
    }

    int getHeight(){
        return this->height;
    }
};

int main(){

    int x;

    bst * tree = new bst();

    while(cin >> x){
        if(x == 0) break;
        tree->add(x);
    }

    //tree->print();

    cout << tree->get2ndMax() << endl;


    return 0;
}