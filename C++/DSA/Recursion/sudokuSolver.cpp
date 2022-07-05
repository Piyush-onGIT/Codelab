#include <bits/stdc++.h>
using namespace std;

// leetcode 37

bool isSafe(vector<vector<int>> board, int r, int c, int num) {
    // check the number in the row
    for (int i = 0; i < board.size(); i++) {
        if (board[r][i] == num) return false;
    }
    
    // check the number in the column
    for (int i = 0; i < board.size(); i++) {
        if (board[i][c] == num) return false;
    }
    
    // check inside the 3 X 3 box
    int root = sqrt(board.size());
    int sRow = r - (r % root);
    int sCol = c - (c % root);
    
    for (int i = sRow; i < sRow + root; i++) {
        for (int j = sCol; j < sCol + root; j++) {
            if (board[i][j] == num) return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board) {
    int n = board.size();
    bool empty = 0;
    int row = -1, col = -1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                empty = 1;
                break;
            }
        }
        if (empty) break;
    }
    if (!empty) return true;            // sudoku solved
    else {
        // now try to put number from 1 to n
        for (int i = 1; i <= n; i++) {
            if (isSafe(board, row, col, i)) {
                board[row][col] = i;
                if (solve(board)) {
                    return true;
                }
                else {
                    // backtrack
                    board[row][col] = 0;
                }
            }
        }
    }
    return false;           // can't be solved
}

void display(vector<vector<int>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> board =     {{5, 3, 0, 0, 7, 0, 0, 0, 0}, 
                                     {6, 0, 0, 1, 9, 5, 0, 0, 0}, 
                                     {0, 9, 8, 0, 0, 0, 0, 6, 0}, 
                                     {8, 0, 0, 0, 6, 0, 0, 0, 3}, 
                                     {4, 0, 0, 8, 0, 3, 0, 0, 1}, 
                                     {7, 0, 0, 0, 2, 0, 0, 0, 6}, 
                                     {0, 6, 0, 0, 0, 0, 2, 8, 0}, 
                                     {0, 0, 0, 4, 1, 9, 0, 0, 5}, 
                                     {0, 0, 0, 0, 8, 0, 0, 7, 9}};
                                     
    if (solve(board)) display(board);
}
