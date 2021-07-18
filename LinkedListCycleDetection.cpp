#include <iostream>
#include <unordered_set>

using namespace std;


class Node {
public:
    int data;
    int flag;
    Node *next;
};

void pushFront(Node **node, int data);

void printNodes(Node *node);

bool detectLoopUsingSet(Node *head);

bool detectLoopUsingFlag(Node *head);

bool detectLoopUsingFloyd(Node *head);

int main() {
    Node *head = nullptr;

    pushFront(&head, 7);
    pushFront(&head, 2);
    pushFront(&head, 1);
    pushFront(&head, 6);

    /* Create a loop for testing */
    head->next->next->next->next = head;

    cout<<"Printing the linked list: ";
    printNodes(head);

    // Detect loop: method 1 using auxillary space unordered_set
    cout<<"\nContains a loop using Unordered set: "<<detectLoopUsingSet(head);

    // Detect loop using extra variable in Node class named flag
    cout<<"\nContains a loop using flag variable: "<<detectLoopUsingFlag(head);

    // Detect loop using Floyd Cycle Detection algorithm
    cout<<"\nContains loop using Floyd's algo: "<<detectLoopUsingFloyd(head);
}

bool detectLoopUsingFlag(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        // If this node is already traverse
        // it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (temp->flag == 1) {
            return true;
        }
        // If we are seeing the node for
        // the first time, mark its flag as 1
        temp->flag = 1;
        temp = temp->next;
    }
    return false;
}

bool detectLoopUsingSet(Node *head) {
    unordered_set<Node *> nodeSet;
    Node *temp = head;
    while (temp != nullptr) {
        // If this node is already present
        // in hashmap it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (nodeSet.find(temp) != nodeSet.end()) {
            return true;
        }
        // If we are seeing the node for
        // the first time, insert it in hash
        nodeSet.insert(temp);
        temp = temp->next;
    }
    return false;
}

/*
 * Approach: This is the fastest method and has been described below:

 * Traverse linked list using two pointers.
 * Move one pointer(slow_p) by one and another pointer(fast_p) by two.
 * If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have
 * a loop.
 */
bool detectLoopUsingFloyd(Node *head) {
    Node *slow_p = head;
    Node *fast_p = head;
    while (slow_p != nullptr && fast_p != nullptr && fast_p->next != nullptr) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return true;
        }
    }
    return false;
}

void printNodes(Node *node) {
    Node *temp = node;
    unordered_set <Node*> nodeSet;
    while(nodeSet.find(temp) == nodeSet.end()) {
        cout<<temp->data<<" ";
        nodeSet.insert(temp);
        temp = temp->next;
    }
}

void pushFront(Node **node, int data) {
    if(*node == nullptr) {
        *node = new Node();
        (*node)->data = data;
        (*node)->next = nullptr;
        (*node)->flag = 0;
        return;
    }
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*node);
    new_node->flag = 0;
    (*node) = new_node;
}

