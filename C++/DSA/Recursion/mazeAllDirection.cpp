#include <bits/stdc++.h>
using namespace std;

void mazeAllDirection(string p, vector<vector<bool>> &maze, int r, int c) {
    if (r == maze.size() - 1 && c == maze[0].size() - 1) {
        cout << p << endl;
        return;
    }
    if (!maze[r][c]) {              // if this is the obstacle
        return;
    }
    
    maze[r][c] = 0;         // mark visited
    
    if (r > 0) {
        mazeAllDirection(p + "U", maze, r - 1, c);
    }
    if (c > 0) {
        mazeAllDirection(p + "L", maze, r, c - 1);
    }
    if (r < maze.size() - 1) {
        mazeAllDirection(p + "D", maze, r + 1, c);
    }
    if (c < maze[0].size() - 1) {
        mazeAllDirection(p + "R", maze, r, c + 1);
    }
    
    maze[r][c] = 1;         // backtracked
    // revert the changes that you made in the previous call, when that call ends
    // control reaches here, so revert the changes.
}

int main() {
    vector<vector<bool>> maze = {{1, 1, 1},
                                {1, 1, 1},
                                {1, 1, 1}};
                                
    // if not marked visited as false, there will be stack overflow,
    // because at some time you will reach (0, 0) and there will be never-ending calls
    // this will create a problem, because when you marked the visited cells false,
    // you will not be able to reach that cell again even if it is valid for any different.
    // That's why we are using backtracking
    mazeAllDirection("", maze, 0, 0);
}
