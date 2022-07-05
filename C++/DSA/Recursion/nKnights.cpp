#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<bool>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j]) cout << "K ";
            else cout << "X ";
        }
        cout << endl;
    }
}

bool isValid(vector<vector<bool>> board, int r, int c) {
    if (r >= 0 && r < board.size() && c >= 0 && c < board.size()) return true;
    return false;
}

bool isSafe(vector<vector<bool>> board, int r, int c) {
    if (isValid(board, r - 2, c - 1)) {
        if (board[r - 2][c - 1]) return false;
    }
    if (isValid(board, r - 1, c - 2)) {
        if (board[r - 1][c - 2]) return false;
    }
    if (isValid(board, r - 2, c + 1)) {
        if (board[r - 2][c + 1]) return false;
    }
    if (isValid(board, r - 1, c + 2)) {
        if (board[r - 1][c + 2]) return false;
    }
    return true;
}

void nKnights(vector<vector<bool>> &board, int row, int col, int knights) {
    if (knights == 0) {
        display(board);
        cout << endl;
        return;
    }
    
    if (row == board.size() - 1 && col == board.size()) return;
    
    if (col == board.size()) {
        nKnights(board, row + 1, 0, knights);
        return;
    }
    
    if (isSafe(board, row, col)) {
        board[row][col] = 1;
        nKnights(board, row, col + 1, knights - 1);
        board[row][col] = 0;
    }
    
    nKnights(board, row, col + 1, knights);
}

int main() {
    vector<vector<bool>> board = {{0, 0, 0},
                                  {0, 0, 0},
                                  {0, 0, 0}};
                                
    nKnights(board, 0, 0, 3);
}
