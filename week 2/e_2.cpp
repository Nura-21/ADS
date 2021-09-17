#include <bits/stdc++.h>
using namespace std;


struct Node{
    int value;
    int counter;
    Node *next, *prev;
};


struct linkedList{
    Node *head, *tail;
    int sz;

    linkedList(){
        head = tail = NULL;
        sz = 0;
    }

    int size(){
        return sz;
    }

    bool isEmpty(){
        return sz == 0;
    }

    void add(int x){
        Node *newNode = new Node();
        newNode->value = x;
        newNode->counter = 1;
        if (head == NULL){
            head = tail = newNode;
        } else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        sz++;
    }

    bool inList(int s){
        return find(s)->value != -228;
    }

    Node* find(int x){
        Node *null = new Node();
        null->value = -228;
        if (!isEmpty()){
            Node *temp = head;
            while (temp != NULL){
                if (temp->value == x){
                    return temp;
                } else {
                    temp = temp->next;
                }
            }
            return null;
        }
        return null;
    }

    void del(int x){
        Node *myNode = find(x);
        if (myNode->value != -228){
            if (myNode->prev == NULL && myNode->next != NULL){
                Node* temp = head;
                head = myNode->next;
                head->prev = NULL;
                delete(temp);
            } else if (myNode->prev != NULL && myNode->next == NULL){
                Node* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete(temp);
            } else if (sz == 1){
                delete(myNode);
                head = tail = NULL;
            } else {
                myNode->prev->next = myNode->next;
                myNode->next->prev = myNode->prev;
                delete(myNode);
            }
            sz--;
        }
    }

    void print(){
        if (!isEmpty()){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->value << " ";
                temp = temp->next;
            }
        }
    }

    void sort_by_value(){
        Node* current = head, *index = NULL;
        if(head == NULL){
            return;
        }else{
            while(current != NULL){
                index = current->next;
                while(index != NULL){
                    if (current->value > index->value){
                        int temp = current->value;
                        current->value = index->value;
                        index->value = temp;
                        int temp2 = current->counter;
                        current->counter = index->counter;
                        index->counter = temp2;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }

    void swap(Node* current, Node* index){
        int temp = current->value;
        current->value = index->value;
        index->value = temp;
        int temp2 = current->counter;
        current->counter = index->counter;
        index->counter = temp2;
    }

    void sort_by_freq(){
        Node* current = head, *index = NULL;
        if(head == NULL){
            return;
        }else{
            while(current != NULL){
                index = current->next;
                while(index != NULL){
                    // if (current->counter < index->counter){
                    //     swap(current, index);
                    // } else if (current->counter == index->counter && current->value > index->value){
                    //     swap(current, index);
                    // }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
};


int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    linkedList myList;
    string s;
    while(cin >> s){
        if (s[0] == '+'){
            int temp = stoi(s.erase(0, 1));
            myList.add(temp);
        } else if (s[0] == '-'){
            int temp = stoi(s.erase(0, 1));
            if (myList.inList(temp)){
                myList.del(temp);
            } else {
                cout << "ERROR";
                return 0;
            }
        }
    }

    if (myList.isEmpty()) cout << "EMPTY";
    else{
        myList.sort_by_value();
        myList.print();
    }
    return 0;
}