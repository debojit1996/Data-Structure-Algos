#include <iostream>

using namespace std;

class Node {
    public:
      int data;
      Node *left, *right;
};

void inorder(Node *pNode);
void preOrder(Node *root);

Node* buildTree(int in[], int pre[], int iStart, int iEnd);

int main() {
    Node *root = new Node();
    root->data = 10;
    root->left = new Node();
    root->left->data = 20;
    root->right = new Node();
    root->right->data = 30;
    root->left->left = new Node();
    root->left->left->data = 40;
    root->left->right = new Node();
    root->left->right->data = 50;

    cout<<"********InOrder*******\n";
    inorder(root);
    cout<<"\n********PreOrder*******\n";
    preOrder(root);

    int in[] = {40, 20, 50, 10, 30};
    int pre[] = {10, 20, 40, 50, 30};

    Node *newRoot = buildTree(in, pre, 0, 4);
    cout<<"\n********InOrder Build*******\n";
    inorder(newRoot);
    cout<<"\n********PreOrder Build*******\n";
    preOrder(newRoot);
    return 0;
}
int preIndex = 0;
Node* buildTree(int in[], int pre[], int iStart, int iEnd) {
    if (iStart > iEnd)
        return nullptr;
    Node *root = new Node();
    root->data = pre[preIndex++];

    int inIndex = 0;
    for( int i = iStart; i <= iEnd; i++) {
        if(in[i] == root->data) {
            inIndex = i;
            break;
        }
    }

    root->left = buildTree(in, pre, iStart, inIndex - 1);
    root->right = buildTree(in, pre, inIndex + 1, iEnd);
    return root;
}

void inorder(Node *root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preOrder(Node *root) {
    if (root == nullptr)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
