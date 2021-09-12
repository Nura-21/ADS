#include <iostream>
#include <string>
using namespace std;



struct node{
    string val;
    int cnt;
    node * next;
    node * prev;
    node(){
        next = NULL;
        prev = NULL;
    }
};

struct my_deq{
    node * cur;
    node * front;
    
    long long val_size = 0;

    my_deq(){
        cur = NULL;
        front = NULL;
    }

    long long size(){
        return val_size;
    }

    void show_back(){
        while(cur != NULL){
            cout << cur->val << " "<<cur->cnt << endl;
            cur = cur->prev;
        }
        
    }


    void push_back(string x){
        node * item = new node();
        item->val = x;
        item->cnt = 1;
        if(cur == NULL and val_size == 0){
            cur = front = item;
        }
        else{
            item->prev = cur;
            cur->next = item;
            cur = item;
        }
        val_size++;
    }

    node * find(string s){
        node * null = new node();
        null->val = "0";
        if(!empty()){
            node * temp = cur;
            while(temp != NULL){
                if(temp->val == s){
                    return temp;
                }else{
                    temp = temp->prev;
                }
            }
            return null;
        }
        return null;
    }

    bool empty(){
        return front == NULL;
    }
    void sort_by_cnt(){
        node * current = cur, *index = NULL;
        if(cur == NULL){
            return;
        }else{
            while(current != NULL){
                index = current->prev;
                while(index != NULL){
                    if (current->cnt < index->cnt){
                        int temp = current->cnt;
                        current->cnt = index->cnt;
                        index->cnt = temp;
                        string temp2 = current->val;
                        current->val = index->val;
                        index->val = temp2;
                    }
                    index = index->prev;
                }
                current = current->prev;
            }
        }
    }
    void sort_by_val(){
        node * current = cur, *index = NULL;
        if(cur == NULL){
            return;
        }else{
            while(current != NULL){
                index = current->prev;
                while(index != NULL){
                    if (current->val > index->val and current->cnt == index->cnt){
                        string temp = current->val;
                        current->val = index->val;
                        index->val = temp;
                        int temp2 = current->cnt;
                        current->cnt = index->cnt;
                        index->cnt = temp2;
                    }
                    index = index->prev;
                }
                current = current->prev;
            }
        }
    }

};

int main(){
    my_deq deq;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string command;
    while(cin >> command){
       if(deq.find(command)->val == "0"){
           deq.push_back(command);
       }else{
           deq.find(command)->cnt++;
       }
       command = "";
    }
    deq.sort_by_cnt();
    deq.sort_by_val();
    deq.show_back();
}