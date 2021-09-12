#include <iostream>
using namespace std;

struct node{
    long long val;
    node * next;
    node * prev;
    node(long long x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

struct my_deq{
    private:
        node * cur;
        node * front;
    public:
    long long val_size = 0;

    my_deq(){
        cur = NULL;
        front = NULL;
    }

    long long size(){
        return val_size;
    }

    void exit(){
        cout << "bye" << endl;
    }

    void show_front(){
        if(front != NULL){
            cout << front->val << endl;
        }
        else{cout << "error" << endl;}
    }

    void show_back(){
        if(cur != NULL){
            cout << cur -> val << endl;
        }
        else{cout << "error" << endl;}
    }

    void push_front(long long x){
        node * item = new node(x);
        if(front == NULL and val_size == 0){
            cur = front = item; 
        }
        else{
            item->next = front; 
            front->prev = item; 
            front = item;
        }
        val_size++;
        cout << "ok" << endl;
    }

    void push_back(long long x){
        node * item = new node(x);
        if(cur == NULL and val_size == 0){
            cur = front = item;
        }
        else{
            item->prev = cur;
            cur->next = item;
            cur = item;
        }
        val_size++;
        cout << "ok" << endl;
    }

    void pop_front(){
        if(front != NULL){
            cout << front->val << endl;
            front = front->next;
            if(front == NULL){
                cur = NULL;
            }
            else{front->prev = NULL;}
            val_size--;
        }
        else{
            cur = NULL;
            cout << "error" << endl;
        }
    }

    void pop_back(){
        if(cur != NULL){
            cout << cur->val << endl;
            cur = cur->prev;
            if(cur == NULL){
                front = NULL;
            }
            else{cur->next = NULL;}
            val_size--;
        }
        else{
            front = NULL;
            cout << "error" << endl;	
        }
        
    }

    bool empty(){
        return front == NULL;
    }

    void clear(){
        while(front != NULL and cur != NULL){
            cur = cur->prev;
            if(cur == NULL){
                front = NULL;
            }
            val_size--;
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
        else if(command == "exit") {deq.exit(); break;}
        else if(command == "pop_front") {deq.pop_front();}
        else if(command == "pop_back") {deq.pop_back();}
        else if(command == "push_back"){ long long n; cin >> n; deq.push_back(n);}
        else if(command == "push_front"){ long long n; cin >> n; deq.push_front(n);}
        else if(command == "back") {deq.show_back();}
        else if(command == "front") {deq.show_front();}
    }
}