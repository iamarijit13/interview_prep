#include<iostream>
using namespace std;

class ListNode {
    int val;
    ListNode *next;

    public: 
    ListNode(int va) {
        this -> val = va;
        this -> next = NULL;
    }

    ListNode* reverse(ListNode*);
    ListNode* merge(ListNode*);
    ListNode* reverse_even(ListNode*);
};

ListNode* ListNode :: reverse(ListNode *t) {
    ListNode *p, *q, *r;
    p = NULL;
    q = t;

    while (q) {
        r = q -> next;
        q -> next = p;
        p = q;
        q = r;
    }
    return p;
}

ListNode* ListNode :: merge(ListNode *t) {

}

ListNode* ListNode :: reverse_even(ListNode* t) {

}

int main () {

    return 0;
}

/*
ListNode *reverse(ListNode *head){

ListNode *q;

q=NULL;

while(head!=NULL){

ListNode *on=head->next;

head->next=q;

q=head;

head=on;

}

return q;

}


ListNode* Solution::solve(ListNode* h){

ListNode *p, *q;

vector<int> v;

int len=0;


p=h;
while(p!=NULL){
    if(len%2==1){
        v.push_back(p->val);
    }
    len++;
    p=p->next;
}
int idx=0;
q=reverse(h);
p=q;

if(len%2==1){
    q=q->next;
}
while(q!=NULL){
    q->val=v[idx];
    idx++;
    q=q->next->next;
}
p=reverse(p);
return p;

}
*/