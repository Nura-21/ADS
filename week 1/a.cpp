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
    int val_size = 0;

    my_stack(){
       tail = NULL;
    }

    void back(){
        if(tail != NULL){
            cout << tail->val << endl;
        }
        else{cout << "error" << endl;}
    }

    void push(int x){
        node * item = new node(x);
        if(tail == NULL){tail = item;}
        else{
            tail->next = item;
            item->prev = tail;
            tail = item;
        }
        val_size++;
        cout << "ok" << endl;
    }

    void pop(bool clear){
        if(tail != NULL){
            if(not clear){cout << tail->val << endl;}
            tail = tail->prev;
            if(tail != NULL){
                tail->next = NULL;
            }
            val_size--;
        }
        else{cout << "error" << endl;}
        
    }
    
    bool empty(){
        return tail == NULL;
    }

    int size(){
        return val_size;
    }

    void clear(){
        while(not empty()){
        pop(true);
        }
        cout << "ok" << endl;
        
    }

};

int main(){

    my_stack stack;

    string command;

    while(cin >> command){    
        if(command == "size"){cout << stack.size() << endl;}
        else if(command == "clear") {stack.clear();} 
        else if(command == "exit") {cout << "bye"; return 0;}
        else if(command == "pop") {stack.pop(false);}
        else if(command == "push"){ int n; cin >> n; stack.push(n);}
        else if(command == "back") {stack.back();}
    }
}