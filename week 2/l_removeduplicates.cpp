#include <iostream>
using namespace std;

struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
         if( head == NULL) {
            return NULL;
        }
        ListNode *unique = head ; //Pointer that points to most recent unique value node
        ListNode *curr = head ;    // Iterator Pointer
        while(curr != NULL){
            if(unique->val != curr->val){        //If both are not equal
              swap(unique->next->val, curr->val);   
			  //Swap the value of the unique node's next  node with current unique value node
              unique = unique->next;    //Increment window of unique element
            }
            curr = curr->next ;
        }
        unique->next = NULL;  
		//When curr becomes null we reached the end and we have    
		//traversed all the elements and the last unique element is pointer by the unique pointer 
		//rest of elements after that are duplicates so we make unique next to null
        return head;
    }
};