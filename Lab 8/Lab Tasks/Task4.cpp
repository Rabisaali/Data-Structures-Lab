#include<iostream>
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

Node* insert(Node* root, int v) {
    if (root==NULL) {
        return new Node(v);
    }
    else if (root->data==v) {
        cout << "Duplicate price " << v << " ignored\n";
    }
    else if (root->data<v) {
        root->right=insert(root->right, v);
    }
    else {
        root->left=insert(root->left, v);
    }

    return root;
}

Node* findMin(Node* root) {
    if (root==NULL) return NULL;

    while (root->left!=NULL) {
        root=root->left;
    }

    return root;
}

Node* findMax(Node* root) {
    if (root==NULL) return NULL;

    while (root->right!=NULL) {
        root=root->right;
    }

    return root;
}

void rangeSearch(Node* root, int low, int high, int& count) {
    if (root==NULL) return;

    count++;

    if (root->data>low) {
        rangeSearch(root->left, low, high, count);
    }

    if (root->data>=low && root->data<=high) {
        cout << root->data << " ";
    }

    if (root->data<high) {
        rangeSearch(root->right, low, high, count);
    }
}

Node* floorPrice(Node* root, int x) {
    Node* ans=NULL;

    while (root!=NULL) {
        if (root->data==x) {
            return root;
        }
        else if (root->data<x) {
            ans=root;
            root=root->right;
        }
        else {
            root=root->left;
        }
    }

    return ans;
}

Node* ceilPrice(Node* root, int x) {
    Node* ans=NULL;

    while (root!=NULL) {
        if (root->data==x) {
            return root;
        }
        else if (root->data>x) {
            ans=root;
            root=root->left;
        }
        else {
            root=root->right;
        }
    }

    return ans;
}

int countNodes(Node* root) {
    if (root==NULL) return 0;

    return 1+countNodes(root->left)+countNodes(root->right);
}

int main() {
    Node* root=NULL;

    int n, price;

    cout << "Enter number of products: ";
    cin >> n;

    cout << "Enter product prices: ";

    for (int i=0; i<n; i++) {
        cin >> price;
        root=insert(root, price);
    }

    int low, high;
    int visited=0;

    cout << "\nEnter range (low high): ";
    cin >> low >> high;

    cout << "Range [" << low << ", " << high << "] : ";

    rangeSearch(root, low, high, visited);

    cout << "\nVisited nodes : " << visited;
    cout << "\nTotal nodes : " << countNodes(root);

    Node* mn=findMin(root);
    Node* mx=findMax(root);

    if (mn!=NULL) cout << "\nCheapest : " << mn->data;
    else cout << "\nCheapest : None";

    if (mx!=NULL) cout << "\nMost expensive : " << mx->data;
    else cout << "\nMost expensive : None";

    int x;

    cout << "\n\nEnter price to find floor and ceil: ";
    cin >> x;

    Node* f=floorPrice(root, x);
    Node* c=ceilPrice(root, x);

    cout << "Floor(" << x << ") : ";
    if (f==NULL) cout << "None";
    else cout << f->data;

    cout << "\nCeil(" << x << ") : ";
    if (c==NULL) cout << "None";
    else cout << c->data;

    return 0;
}
