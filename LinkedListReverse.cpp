#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

void pushAtFront(Node **head, int data);

void printNodes(Node *head);

void reverseLinkedList(Node **pNode);

int main() {
    Node *head = nullptr;
    pushAtFront(&head, 5);
    pushAtFront(&head, 10);
    pushAtFront(&head, 3);
    pushAtFront(&head, 4);
    // 6->4->3->10->5
    pushAtFront(&head, 6);

    printNodes(head);

    reverseLinkedList(&head);
    cout<<"Printing after reverse\n";
    printNodes(head);
    return 0;
}

void reverseLinkedList(Node **head) {

    Node *prev = nullptr, *next = nullptr, *current = (*head);
    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    (*head) = prev;

}

void printNodes(Node *head) {
    Node *temp = head;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

void pushAtFront(Node **head, int data) {
    if ((*head) == nullptr) {
        *head = new Node();
        (*head)->next = nullptr;
        (*head)->data = data;
        return;
    }
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;

}

