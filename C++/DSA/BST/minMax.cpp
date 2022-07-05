/**
 * author: theKicker
 * created: 2022-01-14 11:04:35 
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

/*
            15
           /  \
          10   20
         / \   /  \
        8  12  17  25
*/

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

// iterative method to find min/max
// for max, go to the extreme right of the BST
int findMin(bstNode *root) {
    while (root -> left != NULL) {      // going to the extreme left of the BST
        root = root -> left;
    }
    int min = root -> data;
    return min;
}

//recursive method to find min/max
int fndMin(bstNode *root) {
    if (root == NULL) {
        outLn("Empty tree");
        return -1;
    }
    if (root -> left == NULL) return root -> data;      // base case
    root = root -> left;        // go to next left
    return fndMin(root);        // and call the function again
}

int main(){
    bstNode* root;      // pointer to root node
    root = NULL;        // tree is empty
    root = insert(15, root);
    root = insert(10, root);
    root = insert(20, root);
    root = insert(12, root);
    root = insert(8, root);
    root = insert(17, root);
    root = insert(25, root);
    int min = fndMin(root);
    outLn(min);
}