/*
You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. The task is to delete the node. Pointer/ reference to head node is not given. 
Note: No head reference is given to you. It is guaranteed that the node to be deleted is not a tail node in the linked list.
*/

#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;

int main () {
    int t, k, n, value;

    scanf("%d", &t);

    while (t--)
    {
        /* code */
    }
    
}

class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        Node *temp = del -> next;
        del -> data = del -> next -> data;
        del -> next = del -> next -> next;
        delete temp;
    }

};