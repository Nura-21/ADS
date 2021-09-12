#include <iostream>
#include <algorithm>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;


struct node{
    int val;
    node * left;
    node * right;
    node(int x):left(NULL),right(NULL),val(x){}
};

struct bst{
private:
    node * root;
    void _print(node * _root, int level){
        if(_root != NULL){
            _print(_root->left, level + 1);
            cout << _root->val <<  " " << level << endl;
            _print(_root->right, level + 1);
        }
    }
    node * _add(node * _root, int x){
        if(_root == NULL){
            _root = new node(x);
        }else if(x < _root->val){
            if(_root->left == NULL){
                _root->left = new node(x);
            }else{
                _add(_root->left, x);
            }
        }else if(x > _root->val){
            if(_root->right == NULL){
                _root->right = new node(x);
            }else{
                _add(_root->right, x);
            }
        }
        return _root;
    }


public:
    bst(){
        root = NULL;
    }

    void add(int x){
        root = _add(this->root, x);
    }

    void find(int x){

    }
    void del(int x){

    }
    void print(){
       _print(this->root, 1);
    }
};


int myrandom (int i) { return std::rand()%i;}

int main(){

    std::srand ( unsigned ( std::time(0) ) );

    bst * tree = new bst();

    int b[] = {2, 5, 8, 7, 3, 9, 10};
    //int b[] = {7, 3, 5, 2, 9, 8, 10};
    int n = sizeof(b) / sizeof(int);

    random_shuffle(b, b + n, myrandom);

    for(int i = 0; i < n; ++i){
        cout << b[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < n; ++i){
        tree->add(b[i]);
    }

    tree->print();

    return 0;
}