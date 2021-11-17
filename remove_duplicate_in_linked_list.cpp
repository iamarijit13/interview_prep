#include<iostream>
#define null 0
using namespace std;

class List {
    public:
        int data;
        List *next;

        List(int x) {
            this -> data = x;
            this -> next = null;
        } 
        List* remove_duplicate(List*);
        void print(List*);
};

List* List :: remove_duplicate(List* head) {
    if (!head) return NULL;
    if (!head -> next) return head; 
    List *te = head, *tex = te -> next;
    
    while (te && tex && tex -> next) {
        int flag = 0;
        while (te -> data == tex -> data) {
            tex = tex -> next;
            flag = 1;
        }
        if (flag == 1) {
            te -> next = tex;
        }
        te = te -> next;
        if (tex){
            tex = tex -> next;
        }
    }
    return head;
}

void List :: print(List *head) {
    List *te = head;
    while (te) {
        cout << te -> data << " ";
        te = te -> next;
    }
}

int main () {
    List *head = new List(1), object(1);
    head -> next = new List(2);
    head -> next -> next = new List(3);
    head -> next -> next -> next = new List(3);
    head -> next -> next -> next -> next = new List(3);
    head -> next -> next -> next -> next -> next = new List(3);
    // head -> next -> next -> next -> next -> next -> next = new List(4);
    // head -> next -> next -> next -> next -> next -> next -> next = new List(4);
    // head -> next -> next -> next -> next -> next -> next -> next -> next = new List(5);
    // head -> next -> next -> next -> next -> next -> next -> next -> next -> next = new List(5);

    object.remove_duplicate(head);
    object.print(head);

    return 0;

}