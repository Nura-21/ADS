#include <iostream>
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node * insert(Node * head, Node * node, int p){
	if(p == 0){
		return new Node(node->val, head);
	}
    if(head == nullptr){
    	return new Node(node->val);
    }
	Node * cur = head;
	for (int i = 0; i < p - 1; i++){
		cur = cur->next;
	}
	Node * tmp = cur->next;
	cur->next = new Node(node->val, tmp);
    return head;
}
 
Node * remove(Node * head, int p){
	if(p == 0){
		if(head != nullptr){
			Node * tmp = head->next;
			delete head;
			head = tmp;
		}
		return head;
	}
	Node * cur = head;
	for(int i = 0; i < p - 1; i++){
		cur = cur->next;
	}
	Node * tmp = cur->next->next;
	delete cur->next;
	cur->next = tmp;
	return head;
}
 
Node * replace(Node * head, int p1, int p2){
	Node * cur = head;
	for(int i = 0; i < p1; i++)
		cur = cur->next;
	Node node = Node(cur->val);
	head = remove(head, p1);
	head = insert(head, & node, p2);
	return head;
}
 
Node * reverse(Node * head){
	Node * newhead = nullptr;
	Node * cur = head;
	while(cur != nullptr){
		newhead = new Node(cur->val, newhead);
		cur = cur->next;
	}
	return newhead;
}
 
void print(Node * head){
	if (head == nullptr){
		cout << -1 << endl;
		return;
	}
	Node * cur = head;
	while(cur != nullptr){
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}
 
Node * cyclic_left(Node * head, int x){
	if (head == nullptr or head->next == nullptr){
		return head;
	}
	Node * last = head;
	while (last->next != nullptr){
		last = last->next;
	}
	for (int i = 0; i < x; i++){
		last->next = head;
		last = last->next;
		Node * tmp = head->next;
		head->next = nullptr;
		head = tmp;
	}
	return head;
}
 
Node * cyclic_right(Node * head, int x){
	if (head == nullptr or head->next == nullptr){
		return head;
	}
	head = reverse(head);
	head = cyclic_left(head, x);
	head = reverse(head);
	return head;
}
 
int main(){
    //freopen("output.txt", "w",stdout);
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            Node tmp = Node(x);
            head = insert(head, &tmp, p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}