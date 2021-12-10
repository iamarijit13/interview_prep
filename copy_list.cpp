#include<iostream>
#include<map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode* deep_copy_list(RandomListNode*);
void print(RandomListNode*);

int main () {
    RandomListNode *root = new RandomListNode(1);
    root -> next = new RandomListNode(2);
    root -> next -> next = new RandomListNode(3);

    root -> random = root -> next -> next;
    root -> next -> random = root;
    root -> next -> next -> random = root;

    RandomListNode *result = deep_copy_list(root);
    print(result);

    return 0;
}

RandomListNode* deep_copy_list(RandomListNode* A) {
    RandomListNode *head = new RandomListNode(0), *te = head, *re = head, *se = A;
    map<RandomListNode*, RandomListNode*> track;

    while (A) {
        te -> next = new RandomListNode(A -> label);
        track.insert(make_pair(A, te -> next));
        A = A -> next;
        te = te -> next;
    }

    while (se) {
        re -> next -> random = track[se -> random];
        re = re -> next;
        se = se -> next;
    }
    return head -> next;
}

void print(RandomListNode *root) {
    while (root) {
        cout << root -> label << " " << root -> random -> label << "\n";
        root = root -> next;
    }
}