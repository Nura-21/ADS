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

struct my_queue2{
private:
    node * head;
    node * tail;

public:
    my_queue2(){
        head = NULL;
        tail = NULL;
    }

    void enqueue(int x) {
        node *newNode = new node(x);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int front(){
        if(head == NULL) return INT_MIN;
        return head->val;
    }

    void pop() {
        if(head != NULL) {
            head = head->next;
        }
    }
};


int main() {

    my_queue2 * q = new my_queue2();

    for(int i = 0; i < 10; ++i){
        q->enqueue(i + 1);
    }

    cout << q->front() << endl;


    q->pop();
    q->pop();
    q->pop();
    q->pop();


    cout << q->front() << endl;


    return 0;
}
