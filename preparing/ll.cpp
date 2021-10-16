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
    long long l_size = 0;

    list(){
        cur = front = NULL;
    };

    long long size(){
        return l_size;
    }

    bool empty(){
        return l_size == 0;
    }

    void push(string s){
        node * item = new node();
        item->val = s;
        item->cnt = 1;
        if(cur == NULL){
            front = cur = item;
        }else{
            cur->next = item;
            item->prev = cur;
            cur = item;
        }
        l_size++;
    }

    void print(){
        if(not empty()){
            node * temp = cur;
            while(temp != NULL){
                cout << temp->val << " " << temp->cnt << endl;
                temp = temp->prev;
            }
        }
    }

    node * find(string s){
        node * not_find = new node();
        not_find->val = "NOT";
        if(not empty()){
            node * temp = cur;
            while(temp != NULL){
                if(temp->val == s){
                    return temp;
                }else{
                    temp = temp->prev;
                }
            }
            return not_find;
        }
        return not_find;
    }

    bool exist(string s){
        return find(s)->val != "NOT";
    }

    void del(string s){
        node * item = find(s);
        if(item->val != "NOT"){
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
            else if(l_size == 1){
                delete(item);
                front = cur = NULL;
            }
            else{
                item->prev->next = item->next;
                item->next->prev = item->prev;
                delete(item);
            }
            l_size--;
        }
    }

    void swap(node * cur, node * prev){
        string val = cur->val;
        cur->val = prev->val;
        prev->val = val;
        int cnt = cur->cnt;
        cur->cnt = prev->cnt;
        prev->cnt = cnt; 
    }

    void sort_by_val(){
        node * temp = cur, * index = NULL;
        if(cur == NULL){
            return;
        }else{
            while(temp != NULL){
                index = temp->prev;
                while(index != NULL){
                    if (temp->val > index->val){
                        swap(temp,index);
                    }
                    index = index->prev;
                }
                temp = temp->prev;
            }
        }
    }

    void sort_by_cnt(){
        node * temp = cur, * index = NULL;
        if(cur == NULL){
            return;
        }else{
            while(temp != NULL){
                index = temp->prev;
                while(index != NULL){
                    if (temp->cnt < index->cnt){
                        swap(temp, index);
                    } else if (temp->cnt == index->cnt && temp->val > index->val){
                        swap(temp, index);
                    }
                    index = index->prev;
                }
                temp = temp->prev;
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
        if(l.find(temp)->val == "NOT"){
            l.push(temp);
        }else{
            l.find(temp)->cnt++;
        }
        temp = "";
    }

    l.sort_by_cnt();
    l.print();
}