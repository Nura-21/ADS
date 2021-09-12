#include <iostream>
using namespace std;

struct node{
    pair<string,int> val;
    node * next;
    node * prev;
    node(pair<string,int> x){
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
            cout << front->val.first << endl;
        }
        else{cout << "error" << endl;}
    }

    void show_back(){
        if(cur != NULL){
            cout << cur->val.first << endl;
        }
        else{cout << "error" << endl;}
    }

    void push_back(pair<string,int> x){
        node * item = new node(x);
        if(cur == NULL){
            cur = front = item;
        }
        else if(!find(x.first).first){
            item->prev = cur;
            cur->next = item;
            cur = item;
        }
        else if(find(x.first).first){
            
        }
        val_size++;
        cout << "ok" << endl;
    }


    void pop_back(){
        if(cur != NULL){
            cout << cur->val.first << endl;
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

    void show_cnt(){
        node * temp = cur;
        while(temp != NULL){
            cout << temp->val.first << " "<<temp->val.second << endl;
            temp = temp->prev;
        }
        
    }

    bool empty(){
        return front == NULL;
    }

    pair<bool, int> find(string s){
        node * temp = cur;
        while(temp != NULL){
            if(temp->val.first == s){
                return make_pair(true, temp->val.second + 1);
            }
            temp = temp->prev;
        }
        return make_pair(false, 0);
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
        else if(command == "pop_back") {deq.pop_back();}

        else if(command == "push"){ 
            string n; cin >> n; 
            pair<bool, int> res = deq.find(n);
            if(res.first){
                deq.push_back(make_pair(n,res.second));
            }
            else{deq.push_back(make_pair(n,1));
            }
        }

        else if(command == "back") {deq.show_back();}

        else if(command == "cnt"){
            deq.show_cnt();
        }
    }
}