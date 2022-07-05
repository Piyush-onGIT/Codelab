/**
 * @authors: kicker
 * @date: 15:28, 21 March 2022
**/
#include <bits/stdc++.h>
using namespace std;

struct bstNode {
    int data;
    bstNode *left;
    bstNode *right;
};

bool isLesser(bstNode* root, int value) {
        if (root == NULL) return true;
        if (root -> data <= value && isLesser(root -> left, value) && isLesser(root -> right, value)) return true;
        else return false;
    }
    
bool isGreater(bstNode* root, int value) {
    if (root == NULL) return true;
    if (root -> data >= value && isGreater(root -> left, value) && isGreater(root -> right, value)) return true;
    else return false;
}

// this method is very slow, TC: O(n^2), because for every nodes we are checking all nodes in it's left and right
bool checkBST(bstNode* root) {
    if (root == NULL) return true;
    
    if (isLesser(root -> left, root -> data)
    && isGreater(root -> right, root -> data)
    && checkBST(root -> left)
    && checkBST(root -> right)) return true;
    
    else return false;
}

// TC: O(n)
bool checkBst(bstNode* root, int min, int max) {
    if (root == NULL) return true;
    if (root -> data >= min && root -> data <= max
        && checkBst(root -> left, min, root -> data)
        && checkBst(root -> right, root -> data, max)) return true;
        
    else return false;
}

int main() {
    bstNode *root = NULL;
    vector<int> arr{12,9,10,7,14,11,15};
    for (int i : arr) root = insert(i, root);
    
    cout << checkBst(root, INT_MIN, INT_MAX) << endl;
}