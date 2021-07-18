#include <iostream>

using namespace std;


class Node {
  public:
    int data;
    Node *next;
};

void pushFront(Node **pNode, int i);

void printNodes(Node *pNode);

void deleteNode(Node **pNode, int i);

int main() {

    // Start with empty list
    Node *head = nullptr;

    pushFront(&head, 7);
    pushFront(&head, 2);
    pushFront(&head, 1);
    pushFront(&head, 6);

    printNodes(head);

    cout<<"\nDeleting Node with key = 1\n";

    deleteNode(&head, 1);

    cout<<"Print Nodes list after deletion\n";
    printNodes(head);

    return 0;
}

void deleteNode(Node **head, int key) {

    if(*head == nullptr) {
        cout<<"\nNo nodes to delete\n";
        return;
    }
    Node *temp = (*head);
    Node *prev = nullptr;
    // First Node itself holds the key
    if(temp != nullptr && temp->data == key) {
        (*head) = temp->next;
        delete temp;
        return;
    }

    // check and break loop when we find the node with given key
    while(temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    // if given key is not found after end of above while loop, print NOT_FOUND
    if(temp == nullptr) {
        cout<<"\nNo node with key = "<<key<<" could be found\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
}

void printNodes(Node *node) {
    Node *temp = node;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
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

