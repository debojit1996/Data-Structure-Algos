#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next, *random;
    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};

void print(Node *start);

Node* cloneList(Node *start);

int main() {
    Node* start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    // 1's random points to 3
    start->random = start->next->next;

    // 2's random points to 1
    start->next->random = start;

    // 3's and 4's random points to 5
    start->next->next->random =
            start->next->next->next->next;
    start->next->next->next->random =
            start->next->next->next->next;

    // 5's random points to 2
    start->next->next->next->next->random = start->next;

    cout<<"Original list\n";
    print(start);

    Node *newStart = cloneList(start);
    cout<<"\n";
    cout<<"Cloned list\n";
    print(newStart);


    return 0;
}

Node* cloneList(Node *start) {
    Node *current = start, *temp;
    while(current != nullptr) {
        temp = new Node(current->data);
        temp->next = current->next;
        current->next = temp;
        current = temp->next;
    }

    current = start;
    while(current != nullptr) {
        if(current->next != nullptr) {
            current->next->random = current->random ? current->random->next : current->random;
        }
        current = current->next ? current->next->next : current->next;
    }

    Node *original = start, *copy = start->next;
    Node *newHead = copy;
    while(original != nullptr && copy != nullptr) {
        original->next = copy->next;
        copy->next = original->next ? original->next->next : original->next;
        original = original->next;
        copy = copy->next;
    }
    return newHead;
}

void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

