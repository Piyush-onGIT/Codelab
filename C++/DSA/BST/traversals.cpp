/**
 * @authors: kicker
 * @date: 09:27, 18 March 2022
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define in cin >>
#define out cout <<
#define outLn(n) cout << n << endl
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define pb push_back
#define vii vector<int64_t>
#define vc vector<char>
#define si set<int>
#define mii map<int, int>
#define pqMax priority_queue<int>
#define pqMin priority_queue<int, vector<int>, greater<int>>

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

/** Breadth-first search: Level-order traversal
 *  Depth-first search: Pre-Order Traversal(DLR), In-Order Traversal(LDR), Post-Order Traversal(LRD)
 * 	Inorder traversal of BST gives us a sorted list
**/

// For BFS/level order -> TC: O(n), SC: O(n), Best SC: O(1)
// Maximum extra space used is the maximum number of nodes in any level
// For tree like this: O->O->O->O->O, SC: O(1)
void levelOrder(bstNode *root) {
	if (root == NULL) {
		return;
	}
	queue<bstNode*> visited;
    visited.push(root);                                             // to visit the level 0
    int level = 0;
    
    while (!visited.empty()) {
        bstNode *tmp = visited.front();
        cout << tmp -> data << " ";                                 // operate the data of current node
        if (tmp -> left != NULL) visited.push(tmp -> left);         // store the left child to visit first
        if (tmp -> right != NULL) visited.push(tmp -> right);       // store the right child to visit after that
        visited.pop();                                              // remove that node whose operation(print) is done
    }
    cout << endl;
}

// DFS, TC: O(n), SC: O(h), where h is the height of tree
// worst case: h = n - 1, best/avg: h = log2(n)

// Preorder
/** Visit root, operate(print)
 *  Visit left subtree
 *  Visit right subtree
**/
void preorder(bstNode *root) {
    if (root == NULL) return;
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

//  Inorder
/** Visit left subtree
 *  Visit root, operate(print)
 *  Visit right subtree
**/
void inorder(bstNode *root) {
    if (root == NULL) return;
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

//  Postorder
/** Visit left subtree
 *  Visit right subtree
 *  Visit root, operate(print)
**/
void postorder(bstNode *root) {
    if (root == NULL) return;
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

int main(){
    bstNode *root = NULL;
    vi arr{12,9,10,7,14,11,15};
    for (int i : arr) root = insert(i, root);
    
    postorder(root);
    cout << endl;
}
