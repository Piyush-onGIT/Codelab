/**
 * author: theKicker
 * date: 2022-01-14 00:38:57 
**/
#include <bits/stdc++.h>
using namespace std;
#define in cin >>
#define out cout <<
#define outLn(n) cout << n << endl
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define pb push_back
#define pp pop_back
#define si set<int>
#define mii map<int, int>

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

bool search(bstNode *root, int data) {
    if (root == NULL) return false;
    if (root -> data == data) return true;
    if (root -> data > data) {
        // search in left subtrees of root
        return search(root -> left, data);
    }
    else {
        // search in right subtree of root
        return search(root -> right, data);
    }
}

int getHeight(bstNode *root) {
    if (root == NULL) {
        return -1;
    }
    int lHeight = 0;
    lHeight += getHeight(root -> left);
    
    int rHeight = 0;
    rHeight += getHeight(root -> right);
    return max(rHeight, lHeight) + 1;
}

int main() {
    bstNode* root;      // pointer to root node
    root = NULL;        // tree is empty
    vi arr{5,4,6,3,7,2,8,1,9};
    for (int i = 0; i < arr.size(); i++) root = insert(arr[i], root);
        
    cout << getHeight(root) << endl;
}