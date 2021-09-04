#include <iostream>

using  namespace  std;


struct node{
    char val;
    node * next;
    node(char x):val(x),next(NULL){}
};

struct my_stack{
private:
    node * head;
    int sz;

public:
    my_stack(){
        head = NULL;
        sz = 0;
    }

    void push(char x) {
        node *newNode = new node(x);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        sz++;
    }

    char top(){
        if(head == NULL) return '!';
        return head->val;
    }

    void pop(){
        if(head != NULL){
            sz--;
            head = head->next;
        }
    }

    int size() {
        return sz;
    }

    bool isEmpty(){
        return sz == 0;
    }
};


int main() {

    my_stack *  st = new my_stack();

    string str;
    cin >> str;
    bool ok = true;

    for(int i = 0; i < str.size(); ++i){
       if(str[i] == '('){
           st->push('(');
       }else if(str[i] == ')'){
           if(!st->isEmpty()){
               st->pop();
           }else{
               ok = false;
               break;
           }
       }
    }

    if(ok && st->isEmpty()){
        cout << "OK";
    }else{
        cout << "NO";
    }

    return 0;
}
