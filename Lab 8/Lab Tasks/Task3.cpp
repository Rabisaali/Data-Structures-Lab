#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int v) {
            data=v;
            left=NULL;
            right=NULL;
        }
};

Node* createNode(int v) {
    if (v==-1) return NULL;
    return new Node(v);
}

void preorder(Node* root) {
    if (root==NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root==NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(Node* root) {
    if (root==NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp=q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left!=NULL) q.push(temp->left);
        if (temp->right!=NULL) q.push(temp->right);
    }
}

int countNodes(Node* root) {
    if (root==NULL) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(Node* root) {
    if (root==NULL) return 0;

    if (root->left==NULL && root->right==NULL) {
        return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}

int height(Node* root) {
    if (root==NULL) return -1;

    int l=height(root->left);
    int r=height(root->right);

    if (l>r) return l+1;
    else return r+1;
}

bool isFull(Node* root) {
    if (root==NULL) return true;

    if (root->left==NULL && root->right==NULL) return true;

    if (root->left!=NULL && root->right!=NULL) {
        return isFull(root->left) && isFull(root->right);
    }

    return false;
}

bool isComplete(Node* root) {
    if (root==NULL) return true;

    queue<Node*> q;
    q.push(root);

    bool flag=false;

    while (!q.empty()) {
        Node* temp=q.front();
        q.pop();

        if (temp->left!=NULL) {
            if (flag==true) return false;
            q.push(temp->left);
        }
        else {
            flag=true;
        }

        if (temp->right!=NULL) {
            if (flag==true) return false;
            q.push(temp->right);
        }
        else {
            flag=true;
        }
    }

    return true;
}

void analyze(Node* root) {
    cout << "\nPre-order : ";
    preorder(root);

    cout << "\nIn-order : ";
    inorder(root);

    cout << "\nPost-order : ";
    postorder(root);

    cout << "\nLevel-order : ";
    levelorder(root);

    cout << "\nNodes : " << countNodes(root);
    cout << "\nLeaves : " << countLeaves(root);
    cout << "\nHeight : " << height(root);

    cout << "\nFull? : ";
    if (isFull(root)) cout << "Yes";
    else cout << "No";

    cout << "\nComplete? : ";
    if (isComplete(root)) cout << "Yes";
    else cout << "No";

    cout << "\n\n";
}

int main() {

    Node* A=createNode(1);

    A->left=createNode(2);
    A->right=createNode(3);

    A->left->left=createNode(4);
    A->left->right=createNode(5);

    A->right->left=createNode(6);
    A->right->right=createNode(-1);

    cout << "========== CHART A ==========\n";
    analyze(A);

    Node* B=createNode(1);

    B->left=createNode(2);
    B->right=createNode(3);

    B->left->left=createNode(4);
    B->left->right=createNode(5);

    B->right->left=createNode(-1);
    B->right->right=createNode(7);

    cout << "========== CHART B ==========\n";
    analyze(B);

    Node* C=createNode(1);

    C->left=createNode(2);
    C->right=createNode(3);

    C->left->left=createNode(4);
    C->left->right=createNode(5);

    C->right->left=createNode(6);
    C->right->right=createNode(7);

    cout << "========== CHART C ==========\n";
    analyze(C);

    return 0;
}
