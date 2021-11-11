#include<iostream>
using namespace std;


 //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
int findLength(ListNode *t) {
    if (t == NULL) return 0;
    int l = 0;
    while(t -> next != NULL) {
        t = t -> next;
        l++;
    }

    return l;
}

ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
    int a = findLength(A);
    int b = findLength(B);
    int d = b-a;
    if(a > b){
        //swap the 2 lists 
        ListNode *temp = A;
        A = B;
        B = temp;
        d = a-b;
    }
    
    for(int i = 0; i<d; i++){
        B = B->next;
    }
    //both A and B are now equidistant from merge point
    while(A != NULL && B != NULL){
        if(A == B) return A;
        A = A->next;
        B = B->next;
    }
    return NULL;
}
