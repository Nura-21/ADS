#include <iostream>

using  namespace  std;


struct node{
    int val;
    node * next;
    node(int x):val(x),next(NULL){}
};

struct my_stack{
private:
    node * head;
    int sz;

public:
    my_stack(){
        head = NULL;
        sz = 0;
    }

    void push(int x) {
        node *newNode = new node(x);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        sz++;
    }

    int top(){
        if(head == NULL) return INT_MIN;
        return head->val;
    }

    void pop(){
        if(head != NULL){
            sz--;
            head = head->next;
        }
    }

    int size() {
        return sz;
    }

    bool isEmpty(){
        return sz == 0;
    }
};


int main() {

    my_stack *  st = new my_stack();

    for(int i = 0; i < 10; ++i){
        st->push(i + 1);
    }

    while(!st->isEmpty()){
        cout << st->top() << " ";
        st->pop();
    }

    return 0;
}
