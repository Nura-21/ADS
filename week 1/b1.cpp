#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *prev;
    Node *next;
    Node(int number){
        value = number;
        prev = NULL;
        next = NULL;
    }
};

struct Queue{
    private:
        Node *tail;
        Node *head;
        int size;
    public:
        Queue(){
            tail = NULL;
            head = NULL;
            size = 0;
        }

        void push(int number){
            Node *inputItem = new Node(number);

            if(tail == NULL){
                tail = inputItem;
                head = tail;
                size = 1;
            }else{
                tail -> next = inputItem;
                //inputItem -> prev = tail;
                tail = inputItem;
                size++;
            }
            cout << "ok" << endl;
        }

        void pop(){
            if(head != NULL){
                cout << head -> value << endl;
                head =  head -> next;
                size--;
                if(head == NULL){
                    tail = NULL;
                }
            }else{
                cout << "error" << endl;
            }
        }

        void front(){
            if(head != NULL){
                cout << head -> value << endl;
            }else{
                cout << "error" << endl;
            }
        }

        void Showsize(){
            cout << size << endl;
        }

        void clear(){
            head = NULL;
            tail = NULL;
            size = 0;
            cout << "ok" << endl;
        }

};

int main(){
    Queue q;

    bool run = true;

    while(run){
        string instruction;
        cin >> instruction;

        if(instruction == "push"){
            int number;
            cin >> number;
            q.push(number);
        }

        if(instruction == "pop"){
            q.pop();
        }

        if(instruction == "front"){
            q.front();
        }

        if(instruction == "size"){
            q.Showsize();
        }

        if(instruction == "clear"){
            q.clear();
        }
        
        if(instruction == "exit"){
            cout << "bye" << endl;
            run = false;
        }
    }
    return 0;
}