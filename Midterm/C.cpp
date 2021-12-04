#include <bits/stdc++.h>
using namespace std;
 
struct Node {
  int value;
  int ans;
  Node *prev;
  Node(int x) {
    value = x;
    prev = nullptr;
    ans = -1;
  }
};
 
struct Stack {
  private:
    Node *head = nullptr;
    int sz = 0;
  public:
 
    int top() { 
      return head->value; 
    }
   
    void pop() {
      head = head->prev;
      sz--;
    }
 
    int size() { 
      return sz;
    }
 
    bool empty() { 
      return sz == 0; 
    }
 
    int push(int x) {
        Node * node = new Node(x);
        if(head == NULL){
            head = node;
        }else{
            Node * temp = head;
            node->prev = head;
            head = node;
            while(temp != nullptr){
                if (temp->value <= node->value){
                    node->ans = temp->value;
                    break;
                }
                if(temp->prev != nullptr){
                    temp = temp->prev;
                }else{
                    break;
                }
            }
        }
        sz++;
        return node->ans;         
    }
 
}st;
 
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    cout << st.push(x) << " ";
  }
}