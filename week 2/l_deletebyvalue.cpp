#include <iostream>
using namespace std;

struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            ListNode *oldHead = head;
            head = head->next;
            delete(oldHead);
        }
        if (!head) return nullptr;
        ListNode *tmp = head;
        while(tmp) {
            while (tmp->next && tmp->next->val == val) { //loop while contigous values are found.
                ListNode *toDelete = tmp->next;
                tmp->next = toDelete->next;
                delete(toDelete);
            }
            tmp = tmp->next;
        }
        return head;
    }