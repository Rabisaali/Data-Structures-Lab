#include<iostream>
#include<climits>
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
    return new Node(v);
}

bool isBST(Node* root, int minVal, int maxVal) {
    if (root==NULL) return true;

    if (root->data<=minVal || root->data>=maxVal) {
        return false;
    }

    return isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal);
}

Node* inorderSuccessor(Node* root, int key) {
    Node* ans=NULL;

    while (root!=NULL) {
        if (root->data>key) {
            ans=root;
            root=root->left;
        }
        else {
            root=root->right;
        }
    }

    return ans;
}

void kthSmallest(Node* root, int k, int& count, int& ans) {
    if (root==NULL) return;

    kthSmallest(root->left, k, count, ans);

    count++;

    if (count==k) {
        ans=root->data;
        return;
    }

    if (count<k) {
        kthSmallest(root->right, k, count, ans);
    }
}

void findKth(Node* root, int k) {
    int count=0;
    int ans=-1;

    kthSmallest(root, k, count, ans);

    if (k<=0 || count<k) {
        cout << "Out of range";
    }
    else {
        cout << ans;
    }
}

int main() {

    Node* A=createNode(50);

    A->left=createNode(30);
    A->right=createNode(70);

    A->left->left=createNode(20);
    A->left->right=createNode(40);

    A->right->left=createNode(60);
    A->right->right=createNode(80);

    Node* B=createNode(50);

    B->left=createNode(30);
    B->right=createNode(70);

    B->left->left=createNode(20);
    B->left->right=createNode(60);

    B->right->left=createNode(40);
    B->right->right=createNode(80);

    cout << "Tree A : ";

    if (isBST(A, INT_MIN, INT_MAX)) {
        cout << "VALID BST\n";
    }
    else {
        cout << "CORRUPTED\n";
    }

    cout << "Tree B : ";

    if (isBST(B, INT_MIN, INT_MAX)) {
        cout << "VALID BST\n";
    }
    else {
        cout << "CORRUPTED (60 sits in the left subtree of 50 but is larger than 50)\n";
    }

    if (isBST(A, INT_MIN, INT_MAX)) {

        int keys[]={40, 60, 30, 80};

        for (int i=0; i<4; i++) {
            Node* temp=inorderSuccessor(A, keys[i]);

            cout << "Successor(" << keys[i] << ") = ";

            if (temp==NULL) cout << "None";
            else cout << temp->data;

            cout << endl;
        }

        cout << "\n3rd smallest = ";
        findKth(A, 3);

        cout << "\n7th smallest = ";
        findKth(A, 7);

        cout << "\n8th smallest = ";
        findKth(A, 8);

        cout << endl;
    }

    return 0;
}
