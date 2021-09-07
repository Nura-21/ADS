#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
    node * prev;
    node(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

struct my_deq{
    private:
        node * tail;
        node * front;
    public:
    int val_size = 0;
    my_deq(){
        tail = NULL;
        front = NULL;
    }

    void show_front(){
        if(not empty()){
            cout << front->val << endl; 
        }
        else{cout << "error" << endl;}
    }

    void show_back(){
        if(not empty()){
            cout << tail->val << endl;
        }
        else{cout << "error" << endl;}
    }

    void push_front(int x){
        node * item = new node(x);
        if(front == NULL){
            tail = item;
            front = item;
        }
        else{item->next = front;
        front->prev = item;
        front = item;
        }
        val_size++;
        cout << "ok" << endl;
    }

    void push_back(int x){
        node * item = new node(x);
        if (front == NULL){
            tail = item;
            front = item;
        }
        else{
            item->prev = tail;
            tail->next = item;
            tail = item;
        }
        val_size++;
        cout << "ok" << endl;
    }

    void pop_front(bool clear){
        if(tail != NULL){
            if(not clear){cout << front->val << endl;}
            front = front->next;
            if(front == NULL){
                tail = NULL;
            }
            else{front->prev = NULL;}
            val_size--;
        }
        else{front = NULL;}
    }

    void pop_back(bool clear){
        if(tail != NULL){
            if(not clear){cout << tail->val << endl;}
            tail = tail->prev;
            if(tail== NULL){
                front = NULL;
            }
            else{tail->next = NULL;}
            val_size--;
        }
        else{front = NULL;}
    }

    bool empty(){
        return front == NULL;
    }

    int size(){
        return val_size;
    }

    void clear(){
        while(not empty()){
            pop_back(true);
        }
        cout << "ok" << endl;
    }

};

int main(){
    my_deq deq;

    string command;
    while(cin >> command){    
        if(command == "size"){cout << deq.size() << endl;}
        else if(command == "clear") {deq.clear();} 
        else if(command == "exit") {cout << "bye"; return 0;}
        else if(command == "pop_front") {deq.pop_front(false);}
        else if(command == "pop_back") {deq.pop_back(false);}
        else if(command == "push_back"){ int n; cin >> n; deq.push_back(n);}
        else if(command == "push_front"){ int n; cin >> n; deq.push_front(n);}
        else if(command == "back") {deq.show_back();}
        else if(command == "front") {deq.show_front();}
    }
}