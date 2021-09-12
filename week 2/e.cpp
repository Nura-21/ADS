#include <iostream>
using namespace std;
bool error = false;
struct node{
    string val;
    node * next;
    node * prev;
    node(string s){
        val = s;
        next = NULL;
        prev = NULL;
    }
};
struct list{
    node * cur;
    node * front;
    long long val_size = 0;
    list(){
        cur = NULL;
        front = NULL;
    }


    long long size(){
        return val_size;
    }

    void add(string x){
        node * item = new node(x);
        val_size++;
        if(front == NULL){
            front = cur = item;
        }else{
            cur->next = item;
            item->prev = cur;
            cur = item;   
        }
    }

    void show(){
        node * temp = front;
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

    node * find(string s){
        node * temp = front;
        node * result = NULL;
        while(temp != NULL){
            if(temp->val == s){
                result = temp;
                break;
            }
            temp = temp->next;
        }   
        return result;
    }

    void del(node * n){
        if(n != NULL){
            val_size--;
            if(n->prev == NULL && n->next == NULL){
                front = cur = NULL;
            }else if(n->prev != NULL && n->next != NULL){
                n->prev->next = n->next;
                n->next->prev = n->prev;
            }else if(n->prev == NULL && n->next != NULL){
                front = n->next;
                n->next->prev = NULL;
            }else if(n->next == NULL && n->prev != NULL){
                cur = n->prev;
                n->prev->next = NULL;  
            }
            delete n;
        }
        else{error = true;}
    }
    
    void dl(string s){
        node * temp = find(s);
        del(temp);
    }

    bool empty(){
        return front == NULL;
    }

};

int main(){
    list l;
    string s;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    while(cin >> s){
        string mem = s.substr(1,s.size());
        if(s[0] == '+'){
            if(l.find(mem) == NULL){
                l.add(mem);
            }
        }
        else{
            if(l.find(mem)->val == mem){
                l.dl(mem);
            }
        }
    }
    if(l.size() == 0 and error == false){
            cout << "EMPTY" << endl;
            return 0;
        }
    else if(error == true){
        cout << "ERROR" << endl;
        return 0;
    }
    else if(l.size()!= 0 and error == false){l.show();} 
    
}