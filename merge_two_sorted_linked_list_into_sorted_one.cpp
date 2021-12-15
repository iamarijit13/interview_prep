/* I have two sorted linked list, output merged sorted linked list */

#include<iostream>
#define null 0
using namespace std;

class list {
    public: 
    int data;
    list *next;

    list (int dt) {
        this -> data = dt;
        this -> next = null;
    }

    list * merge_list(list*, list*);
    void print(list*);
};

list* list ::  merge_list (list* root1, list* root2) { 
    list *final = new list(-1);
    list* tm = final;

    while (root1 && root2) {
        if (root1 -> data < root2 -> data) {
            tm -> next = new list(root1 -> data);
            root1 = root1 -> next;
            tm = tm -> next;
        } else if (root2 -> data < root1 -> data) {
            tm -> next = new list(root2 -> data);
            root2 = root2 -> next;
            tm = tm -> next;
        } else {
            tm -> next = new list(root1 -> data);
            root1 = root1 -> next;
            tm = tm -> next;
            tm -> next = new list(root2 -> data);
            root2 = root2 -> next;
            tm = tm -> next;
        }
    }
    if (root1) {
        tm -> next = root1;
    }
    if (root2) {
        tm -> next = root2;
    }

    return final -> next;
}

void list :: print (list* root) {
    cout << "\nMerged List: ";
    while (root) {
        cout << root -> data << " ";
        root = root -> next;
    }
    cout << "\n\n";
}

int main () {
    list object(0);
    list* re;
    list *root1 = new list(2);
    root1 -> next = new list(3);
    root1 -> next -> next = new list(7);
    root1 -> next -> next -> next = new list(9);

    list *root2 = new list(0);
    root2 -> next = new list(1);
    root2 -> next -> next = new list(9);
    root2 -> next -> next -> next = new list(11);

    re = object.merge_list(root1, root2);
    object.print(re);

    return 0;
}