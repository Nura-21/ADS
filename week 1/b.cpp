#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
    node(int x){
        val = x;
        next = NULL;
    }
};

struct my_que{
    private:
        node * tail;
        node * front;
    public:
    int val_size = 0;

    my_que(){
       tail = NULL;
       front = NULL;
    }

    void fron(){
        if(front != NULL){
            cout << front->val << endl;
        }
        else{cout << "error" << endl;}
    }

    void push(int x){
        node * item = new node(x);
        if(tail == NULL){
            tail = item;
            front = item;
        }else{
            tail->next = item;
            tail = item;
        }
        val_size++;
        cout << "ok" << endl;
    }

    void pop(bool clear){
        if(tail != NULL){
            if(not clear){cout << front->val << endl;}
            node * item = front;
            front = front->next;
            if(front == NULL){
                tail = NULL;
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

    my_que que;

    string command;

    while(cin >> command){    
        if(command == "size"){cout << que.size() << endl;}
        else if(command == "clear") {que.clear();} 
        else if(command == "exit") {cout << "bye"; return 0;}
        else if(command == "pop") {que.pop(false);}
        else if(command == "push"){ int n; cin >> n; que.push(n);}
        else if(command == "front") { que.fron(); }
    }
}