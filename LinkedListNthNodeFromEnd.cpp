#include <iostream>

using namespace std;


class Node {
public:
    int data;
    Node *next;
};

void pushFront(Node **pNode, int i);

void printNthNodeFromEnd(Node *pNode, int n);

void printNodes(Node *pNode);

int main() {
    Node *head = nullptr;

    pushFront(&head, 7);
    pushFront(&head, 2);
    pushFront(&head, 1);
    pushFront(&head, 6);
    pushFront(&head, 15);
    pushFront(&head, 10);

    printNodes(head);

    int n = 6; // Find nth node from end of linked list

    printNthNodeFromEnd(head, n);
}

void printNodes(Node *node) {
    Node *temp = node;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

/*
 * Maintain two pointers – reference pointer and main pointer. Initialize both reference and main pointers to head.
 * First, move the reference pointer to n nodes from head. Now move both pointers one by one until the reference pointer
 * reaches the end. Now the main pointer will point to nth node from the end. Return the main pointer.
 */
void printNthNodeFromEnd(Node *head, int n) {
    Node *referencePtr = head, *mainPtr = head;
    int count = 0;
    while(count < n) {
        if(referencePtr == nullptr) {
            cout<<"\nPlease provide correct index\n";
            return;
        }
        referencePtr = referencePtr->next;
        count++;
    }

    while(referencePtr != nullptr) {
        referencePtr = referencePtr->next;
        mainPtr = mainPtr->next;
    }
    printf("\nNode number %d from end is : %d", n, mainPtr->data);
}

void pushFront(Node **node, int data) {
    if(*node == nullptr) {
        *node = new Node();
        (*node)->data = data;
        (*node)->next = nullptr;
        return;
    }
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*node);
    (*node) = new_node;
}

