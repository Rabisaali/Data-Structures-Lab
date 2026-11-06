#include<iostream>
//bst 1 comparison in best case and O(n) comparisions in skewed case
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d) {
            left=NULL;
            right=NULL;
            data=d;
        }
};

Node* insert(Node* root, int v) {
    if (root==NULL) {
        return new Node(v);
    }
    else if (root->data==v) {
        cout << "Duplicate roll number " << v << " ignored\n";
    }
    else if (root->data<v) {
        root->right = insert(root->right, v);
    }
    else root->left = insert(root->left, v);
    return root;
}

bool search(Node* root, int v) {
    if (root==NULL) {
        // cout << "Tree is empty\n";
        return false;
    }
    else if (root->data==v) {
        cout << root->data << "\n";
        return true;
    }
    else if (root->data<v) {
        cout << root->data << " -> ";
        return search(root->right, v);
    }
    else if (root->data>v) {
        cout << root->data << " -> ";
        return search(root->left, v);
    }
    return false;
}

void inorder(Node* root) {
    if (root==NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main () {
    Node* tree=NULL;

    int choice=0;
    do {
        cout << endl;
        cout << "To register enter 1\nTo search applicant enter 2\nTo display sorted listed enter 3\nTo exit enter 4\n";
        cin >> choice;
        switch(choice) {
            case 1:
                int value;
                cout << "Enter the value: ";
                cin >> value;
                tree=insert(tree, value);
                break;

            case 2:
                int sea;
                cout << "Search: "; 
                cin >> sea;
                cout << (search(tree, sea)? "Found\n": "Not Found\n");
                break;

            case 3:
                cout << "Sorted List: ";
                inorder(tree);
                break;
            
            case 4:
                cout << "Exiting.....\n";
                break;
            
            default:
                cout << "Incorrect choice\n";
        }
    } while(choice!=4);

}