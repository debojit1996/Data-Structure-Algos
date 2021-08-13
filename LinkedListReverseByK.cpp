#include <iostream>

using namespace std;

// Definition for singly-linked list.
 struct Node {
      int val;
      Node *next;
      Node() : val(0), next(nullptr) {}
      Node(int x) : val(x), next(nullptr) {}
      Node(int x, Node *next) : val(x), next(next) {}
 };

Node* reverseKGroup(Node **head, int K);
int countNodes(Node *head);
void print(Node *pNode);

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    print(head);

    reverseKGroup(&head, 2);

    print(head);


    return 0;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != nullptr) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

int countNodes(Node *head) {
    Node *temp = head;
    int count = 0;
    while(temp != nullptr) {
        temp = temp->next;
        count++;
    }
    return count;
}

Node* reverseKGroup(Node** head, int k) {
    int numNodes = countNodes(*head);
    if(k > numNodes)
        return (*head);
    if((*head) == nullptr)
        return nullptr;
    Node *prev = nullptr, *current = (*head), *next = nullptr;
    int cnt = 0;
    while(current != nullptr && cnt < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        cnt++;
    }

    if(next != nullptr)
        (*head)->next = reverseKGroup(&next, k);
    return prev;
}

