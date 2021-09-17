#include <iostream>
using namespace std;

struct node{
    string val;
    int cnt;
    node * prev;
    node * next;
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

    bool is_empty(){
        return val_size == 0;
    }

    bool in_list(string s){
        return find(s)->val != "0";
    }

    void add(string s){
        node * item = new node();
        item->val = s;
        item->cnt = 1;
        val_size++;
        if(front == NULL){
            front = cur = item;
        }
        else{
            cur->next = item;
            item->prev = cur;
            cur = item;
        }
    }

    void show(){
        if(not is_empty()){
            node * temp = front;
            while(temp != NULL){
                cout << temp->val << " " << temp->cnt << endl;
                temp = temp->next;
            }
        }
    }

    node * find(string s){
        node * null = new node();
        null->val = "0";
        if(not is_empty()){
            node * temp = front;
            while(temp != NULL){
                if(temp->val == s){
                    return temp;
                }else{
                    temp = temp->next;
                }
            }
            return null;
        }
        return null;
    }

    void del(string s){
        node * item = find(s);
        if(item->val != "0"){
            if(item->prev == NULL and item->next != NULL){
                node * temp = front;
                front = item->next;
                front->prev = NULL;
                delete(temp);
            }
            else if(item->prev != NULL and item->next == NULL){
                node * temp = cur;
                cur = cur->prev;
                cur->next = NULL;
                delete(temp);
            }
            else if(val_size == 1){
                delete(item);
                front = cur = NULL;
            }
            else{
                item->prev->next = item->next;
                item->next->prev = item->prev;
                delete(item);
            }
            val_size--;
        }
    }

    void swap(node* current, node* index){
        string temp = current->val;
        current->val = index->val;
        index->val = temp;
        int temp2 = current->cnt;
        current->cnt = index->cnt;
        index->cnt = temp2;
    }

    void sort_by_cnt(){
        node* current = front, *index = NULL;
        if(front == NULL){
            return;
        }else{
            while(current != NULL){
                index = current->next;
                while(index != NULL){
                    if (current->cnt < index->cnt){
                        swap(current, index);
                    } else if (current->cnt == index->cnt && current->val > index->val){
                        swap(current, index);
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
}; 

int main(){
    list l;
    string s;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    while(cin >> s){
        string temp = "";
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != '.' and s[i] != '!' and s[i] != ',' and s[i] != ':' and s[i] != ';' and s[i] != '!' and s[i] != '?'){
                temp += tolower(s[i]);
            }
        }
        if(l.find(temp)->val == "0"){
            l.add(temp);
        }else{
            l.find(temp)->cnt++;
        }
        temp = "";
    }

    l.sort_by_cnt();
    l.show();
}