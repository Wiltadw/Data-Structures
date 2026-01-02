#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k){
        key = k;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVL{
private:

    int height(Node* n){
        return n ? n -> height : 0;
    }

    int getBalanced(Node* n){
        return n ? height(n -> left) - height(n -> right) : 0; 
    }

    int max (int a, int b){
        return (a > b) ? a : b;
    }
    
    Node* rightRotate (Node* y){

        Node* x = y -> left;
        Node* beta = x -> right;

        x -> right = y;
        y -> left = beta;

        x -> height = max(height(x -> left), height(x -> right)) + 1;
        y -> height = max(height(y -> left), height(y -> right)) + 1;
        
        return x;
    }

    Node* leftRotate (Node* x){

        Node* y = x -> right;
        Node* alpha = y -> left;

        y -> left = x;
        x -> right = alpha;

        x -> height = max(height(x -> left), height(x -> right)) + 1;
        y -> height = max(height(y -> left), height(y -> right)) + 1;

        return y;
    }

    Node* insert(Node* node, int key){

        if (!node) return new Node(key);

        if (key < node -> key)
            node -> left = insert(node -> left, key);
        
        else if (key > node -> key)
            node -> right = insert (node -> right, key);
        
        else
            return node; //duplicate not allowed

        node -> height = max(height(node -> left), height(node -> left)) + 1;

        int balance = getBalanced(node);

        // LL
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // RR
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // LR
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minVal(Node* node){

        Node* curr = node;
        while (curr -> left)
            curr = curr -> left;
        return curr;
    }

    Node* deleteNode(Node* root, int key){

        if (!root) return root;

        if (key < root -> key)
            root -> left = deleteNode(root -> left, key);

        else if (key > root -> key)
            root -> right = deleteNode(root -> right, key);

        else{

            if (!root -> left || !root -> right){
                Node* temp = root -> left ? root -> left : root -> right;

                if (!temp){
                    temp = root;
                    root = NULL;
                    
                }

                else *root = *temp;
                delete temp;
            }

            else{
                Node* temp = minVal(root -> right);
                root -> key = temp -> key;
                root -> right = deleteNode(root -> right, temp -> key);
            }
        }

        if (!root) return root;

        root -> height = max(height(root -> left), height(root -> right)) + 1;

        int balance = getBalanced(root);

        // LL
        if (balance > 1 && getBalanced(root -> left) >= 0)
            return rightRotate(root);

        // LR
        if (balance > 1 && getBalanced(root -> left) < 0) {
            root -> left = leftRotate(root -> left);
            return rightRotate(root);
        }

        // RR
        if (balance < -1 && getBalanced(root -> right) <= 0)
            return leftRotate(root);

        // RL
        if (balance < -1 && getBalanced(root -> right) > 0) {
            root -> right = rightRotate(root -> right);
            return leftRotate(root);
        }

        return root;
    }
        
    void inorder(Node* root){

        if (!root) return;
        inorder(root -> left);
        cout << root -> key << " ";
        inorder(root -> right);
    }

public:
    Node* root;

    AVL(){
        root = NULL;
    }

    void insert(int key){
        root = insert(root, key);
    }

    void remove(int key){
        root = deleteNode(root, key);
    }

    void print(){
        inorder(root);
        cout << endl;
    }
};

int main() { // test
    AVL tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    tree.print();

    tree.remove(40);
    tree.print();

    return 0;
}