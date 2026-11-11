#include<iostream>
using namespace std;

class AVLNode {
    public:
        int key;
        int height;
        AVLNode* left;
        AVLNode* right;

        AVLNode(int k) {
            key=k;
            height=1;
            left=nullptr;
            right=nullptr;
        }
};

int height(AVLNode* n) {
    return n? n->height: 0;
}

int getBalance(AVLNode* n) {
    return n? height(n->left)-height(n->right): 0;
}

void updateHeight(AVLNode* n) {
    n->height = 1+max(height(n->left), height(n->right));
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x=y->left;
    AVLNode* T2=x->right;

    x->right=y;
    y->left=T2;

    updateHeight(y);
    updateHeight(x);
    
    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y=x->right;
    AVLNode* T2=y->left;

    y->left=x;
    x->right=T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

AVLNode* insert(AVLNode* node, int key) {
    if (node==nullptr) return new AVLNode(key);

    if(key<node->key) node->left=insert(node->left, key);
    else if (key>node->key) node->right=insert(node->right, key);
    else return node;

    updateHeight(node);

    int balance=getBalance(node);

    if (balance>1 && key<node->left->key) {
        cout << " [LL case at " << node->key << ": right rotation] \n";
        return rightRotate(node);
    }

    if (balance<-1 && key>node->right->key) {
        cout << " [RR case at " << node->key << ": left rotation]\n";
        return leftRotate(node);
    }

    if (balance>1 && key>node->left->key) {
        cout << " [LR case at " << node->key << ": left rotation on " << node->left->key << ", then right rotation]\n";
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance<-1 && key<node->right->key) {
        cout << " [RL case at " << node->key << ": right rotation on " << node->right->key << ", then left rotation]\n";
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode* minValueNode(AVLNode* node) {
    while(node->left != nullptr) node=node->left;
    return node;
}

AVLNode* deleteNode(AVLNode* root, int key) {
    if (root==nullptr) return root;

    if(key<root->key) root->left=deleteNode(root->left, key);

    else if(key>root->key) root->right=deleteNode(root->right, key);

    else {
        if (root->left==nullptr || root->right==nullptr) {
            AVLNode* child=root->left? root->left: root->right;
            delete root;
            return child;
        } 

        AVLNode* succ=minValueNode(root->right);
        root->key=succ->key;
        root->right=deleteNode(root->right, succ->key);
    }

    updateHeight(root);
    int balance=getBalance(root);

    if (balance>1 && getBalance(root->left)>=0) {
        cout << " [LL case at " << root->key << ": rigth rotation]\n";
        return rightRotate(root);
    }

    if (balance>1 && getBalance(root->left)<0) {
        cout << " [LR case at " << root->key << ": double rotation]\n";
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance<-1 && getBalance(root->right)<=0) {
        cout << " [RR case at " << root->key << ": left rotation]\n";
        return leftRotate(root);
    }

    if (balance<-1 && getBalance(root->right)>0) {
        cout << " [RL case at " << root->key << ": double rotation]\n";
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool AVLsearch(AVLNode* root, int key) {
    if (root==nullptr) return false;
    else if (root->key==key) return true;
    else if (root->key>key) {
        bool val=AVLsearch(root->left, key);
        return val;
    }
    else {
        bool val=AVLsearch(root->right, key);
        return val;
    }
}