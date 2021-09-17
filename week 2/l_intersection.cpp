#include <iostream>
using namespace std;

struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0,m=0;
        ListNode *temp1=headA,*temp2=headB;
        ListNode * val=NULL;
        if(headA==NULL || headB==NULL) return val;
        while(temp1){
            n++;
            temp1=temp1->next;
        }
        while(temp2){
            m++;
            temp2=temp2->next;
        }
        temp1=headA;
        temp2=headB;
        if(n>=m){
            n=n-m;
            while(n){
                n--;
                temp1=temp1->next;
            }
            while(temp1 && temp2){
                if(temp1==temp2) return temp1;
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }else if(n<m){
            m=m-n;
            while(m){
                m--;
                temp2=temp2->next;
            }
            while(temp1 && temp2){
                if(temp1==temp2) return temp1;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            
        }
        
            return val;
    }