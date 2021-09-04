#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
    node * prev;
    node(int x){
        val = x;
        prev = NULL;
        next = NULL;
    }

};

struct my_stack{
    //1 capacity = 100
    //2 Now client can not use array or make changes in array
    //3 We do not write size of stack
    //4 We use addresses and struct node with links to prev and next tails
    private:
        node * tail;
    public:

    my_stack(){
       tail = NULL;
    }

    int top(){
        if(tail != NULL){
            return tail->val;
        }
            return -1;
    }

    void push(int x){
        node * item = new node(x);
        if(tail == NULL){tail = item;}
        else{
            tail->next = item;
            item->prev = tail;
            tail = item;
        }
    }

    void pop(){
        if(tail != NULL){
            tail = tail->prev;
            if(tail != NULL){
                tail->next = NULL;
            }
        }
    }

    bool empty(){
        return tail == NULL;
    }

};

int main(){
    

    int d[] = {1,10,2,3,5,4};
    int n = sizeof(d) / sizeof(int);
    
    my_stack stack;

    for(int i = 0 ; i < n; ++i){
        stack.push(d[i]);
    }
    for(int i = 0 ; i < n; ++i){
        cout << stack.top() << endl;
        stack.pop();
    }

}