#include <iostream>

using namespace std;

class Node {
 public:
    int data;
    Node *next;
};

void printLinkedList(Node *pNode);

int main() {

    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printLinkedList(head);

    return 1;
}

void printLinkedList(Node *node) {

    while(node != NULL) {
        cout<<node->data<<" ";
        node = node->next;
    }
}

