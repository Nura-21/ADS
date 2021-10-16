#include <iostream>
using namespace std;

struct node{
    long long val;
    node * next;
    node * prev;
};

struct list{
    private:
        node * cur;
        node * front;
    public:
    long long l_size = 0;

    list(){
        cur = front = NULL;
    }

    long long size(){
        return l_size;
    }

    bool empty(){
        return l_size == 0;
    }

    void exit(){
        cout << "bye" << endl;
    }

    void show_front(){
        if(front != NULL){
            cout << front->val << endl;
        }else{
            cout << "error" << endl;
        }
    }

    void show_back(){
        if(cur != NULL){
            cout << cur->val << endl;
        }else{
            cout << "error" << endl;
        }
    }

    void push_front(long long n){
        node * item = new node();
        item->val = n;
        item->prev = item->next = NULL;
        if(front == NULL and l_size == 0){
            cur = front = item;
        }else{
            item->next = front;
            front->prev = item;
            front = item;
        }
        l_size++;
        cout << "ok" << endl;
    }

    void push_back(long long n){
        node * item = new node();
        item->val = n;
        item->prev = item->next = NULL;
        if(cur == NULL and l_size == 0){
            cur = front = item;
        }else{
            item->prev = cur;
            cur->next = item;
            cur = item;
        }
        l_size++;
        cout << "ok" << endl;
    }

    void pop_front(){
        if(front != NULL){
            cout << front->val << endl;
            front = front->next;
            if(front == NULL){
                cur = NULL;
            }else{
                front->prev = NULL;
            }
            l_size--;
        }else{
            cout << "error" << endl;
        }
    }
    
    void pop_back(){
        if(cur != NULL){
            cout << cur->val << endl;
            cur = cur->prev;
            if(cur == NULL){
                front = NULL;
            }else{
                cur->next = NULL;
            }
            l_size--;
        }else{
            cout << "error" << endl;
        }
    }

    void clear(){
        while(front != NULL and cur != NULL){
            cur = cur->prev;
            if(cur == NULL){
                front = NULL;
            }
            l_size--;
        }
        cout << "ok" << endl;
    }
};

int main(){
    list l;
    string command;
    while(cin >> command){    
        if(command == "size"){cout << l.size() << endl;}
        else if(command == "clear") {l.clear();} 
        else if(command == "exit") {l.exit(); break;}
        else if(command == "pop_front") {l.pop_front();}
        else if(command == "pop_back") {l.pop_back();}
        else if(command == "push_back"){ long long n; cin >> n; l.push_back(n);}
        else if(command == "push_front"){ long long n; cin >> n; l.push_front(n);}
        else if(command == "back") {l.show_back();}
        else if(command == "front") {l.show_front();}
    }
}