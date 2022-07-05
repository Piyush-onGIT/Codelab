/**
 * @author: kicker
 * @date: 22:31, 05 April 2022
**/
#include <bits/stdc++.h>
using namespace std;

struct bstNode {
    int data;
    bstNode *left;
    bstNode *right;
};

bstNode* getNode(int data){
    bstNode *node = new bstNode();
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

bstNode* insert(int data, bstNode *root) {
    if (root == NULL) {     // if BST is empty
        root = getNode(data);
    }
    // recursive calls to insert the data at the right position in BST
    else if (data <= root -> data) root -> left = insert(data, root -> left);
    else root -> right = insert(data, root -> right);
    return root;
}

bstNode* minNode(bstNode* root) {
    while (root -> left != NULL) {
        root = root -> left;
    }
    return root;
}

bstNode* deleteNode(bstNode* root, int val) {
    if (root == NULL) return root;
    else if (root -> data < val) {                          // traverse to find node with the given val
        root -> right = deleteNode(root -> right, val);
    }
    else if (root -> data > val) {                          // traverse to find node with the given val
        root -> left = deleteNode(root -> left, val);
    }
    else {
        if (root -> left == NULL) {                         // node has right child only
            bstNode* tmp = root -> right;
            delete(root);
            return tmp;
        }
        else if (root -> right == NULL) {                   // node has left child only
            bstNode* tmp = root -> left;
            delete(root);
            return tmp;
        }
        else {                                              // node has two child
            bstNode* tmp = minNode(root -> right);          // get the minimum value from the RST of crnt node
            root -> data = tmp -> data;                     // replace the value of crnt node with the min value
            deleteNode(root -> right, tmp -> data);         // now remove that minimum node
        }
    }
    return root;
}

int main() {
    bstNode* node;
    node = insert(20, node);
    node = insert(18, node);
    node = insert(10, node);
    node = insert(45, node);
    node = insert(42, node);
    node = insert(67, node);
    inorder(node);
    cout << endl;
    
    deleteNode(node, 20);
    
    levelOrder(node);
    cout << endl;
}