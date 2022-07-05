#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<bool>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j]) cout << "Q ";
            else cout << "X ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<bool>> board, int r, int c) {
    for (int i = 0; i < r; i++) {
        if (board[i][c]) return false;
    }
    int c1 = board.size() - c - 1;
    int leftDi = min(r, c), rightDi = min(r, c1);
    
    // check left top diagonals
    for (int i = 1; i <= leftDi; i++) {
        if (board[r - i][c- i]) return false;
    }
    
    // check right top diagonals
    for (int i = 1; i <= rightDi; i++) {
        if (board[r - i][c + i]) return false;
    }
    return true;
}

int nQueens(vector<vector<bool>> &board, int row) {
    if (row == board.size()) {
        display(board);
        cout << endl;
        return 1;
    }
    int cnt = 0;
    for (int col = 0; col < board.size(); col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            cnt += nQueens(board, row + 1);
            board[row][col] = 0;            // backtracked
            // remove the queen that was put in the previous call
        }
    }
    return cnt;
}

int main() {
    vector<vector<bool>> board = {{0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0}};
                                
    cout << nQueens(board, 0) << endl;
}
