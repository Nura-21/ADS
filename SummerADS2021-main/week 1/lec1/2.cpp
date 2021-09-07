#include <iostream>

using  namespace  std;


struct node{
    int val;
    node * next;
    /*node (int val){
        this->val = val;
        next = NULL;
    }*/
    node(int x):val(x),next(NULL){}
};

struct ll{
private:
    node * head;
    node * tail;
    void _print(node * current) {
        if (current != NULL) {
            cout << current->val << " ";
            _print(current->next);
        }
    }

public:
    ll(){
        head = NULL;
        tail = NULL;
    }

    void add(int x) {
        node *newNode = new node(x);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        _print(head);
    }
};


int main() {

    ll * l = new ll();

    for(int i = 0; i < 10; ++i){
        l->add(i + 1);
    }

    l->print();

    return 0;
}
