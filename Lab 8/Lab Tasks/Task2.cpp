#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int v) {
            left=NULL;
            right=NULL;
            data=v;
        }
};

void inorder(Node* root) {
    if (root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root==NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


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

Node* findMin(Node* root) {
    if (root==NULL) return NULL;
    else if (root->left==NULL) return root;
    else return findMin(root->left);
}

Node* deleteNode(Node* root, int id) {
    if (root==NULL) {
        return NULL;
    }

    if (root->data<id) {
        root->right = deleteNode(root->right, id);
    }
    else if (root->data>id) {
        root->left = deleteNode(root->left, id);
    }
    else {
        if (root->left==NULL && root->right==NULL) {
            cout << " -> LEAF\n";
            delete root;
            return NULL;
        }
        else if (root->left==NULL || root->right==NULL) {
            cout << " -> ONE CHILD\n";

            Node* temp;

            if (root->left!=NULL) temp=root->left;
            else temp=root->right;

            delete root;
            return temp;
        }
        else {
            Node* temp=findMin(root->right);

            cout << " -> TWO CHILDREN (replaced by successor " << temp->data << ")\n";

            root->data=temp->data;
            root->right=deleteNode(root->right, temp->data);

            return root;
        }
    }

    return root;
}

int main() {
    Node* tree=NULL;

    int n, id;

    cout << "Enter number of patients: ";
    cin >> n;

    cout << "Enter Patient IDs: ";

    for (int i=0; i<n; i++) {
        cin >> id;
        tree=insert(tree, id);
    }

    cout << "\nInitial pre-order : ";
    preorder(tree);
    cout << endl;

    cout << "\nInitial in-order : ";
    inorder(tree);
    cout << endl;

    int choice;

    do {
        cout << "\nEnter Patient ID to discharge (-1 to stop): ";
        cin >> id;

        if (id==-1) break;

        Node* temp=tree;

        while (temp!=NULL && temp->data!=id) {
            if (temp->data<id) temp=temp->right;
            else temp=temp->left;
        }

        if (temp==NULL) {
            cout << "Discharge " << id << " -> Patient not found\n";
            continue;
        }

        cout << "Discharge " << id;
        tree=deleteNode(tree, id);

        cout << "pre-order : ";
        preorder(tree);
        cout << endl;

        cout << "in-order : ";
        inorder(tree);
        cout << endl;

    } while (true);

    return 0;
}