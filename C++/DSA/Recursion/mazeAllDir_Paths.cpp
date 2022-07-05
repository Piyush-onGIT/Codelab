#include <bits/stdc++.h>
using namespace std;

void mazeAllPaths(string p, vector<vector<bool>> &maze, int r, int c, int level, vector<vector<int>> &path) {
    if (r == maze.size() - 1 && c == maze[0].size() - 1) {
        level++;
        path[r][c] = level;
        for (int i = 0; i < path.size(); i++) {
            for (int j = 0; j < path[0].size(); j++) cout << path[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }
    if (!maze[r][c]) {              // if this is the obstacle
        return;
    }
    
    maze[r][c] = 0;         // mark visited
    level++;
    path[r][c] = level;
    
    if (r > 0) {
        mazeAllPaths(p + "U", maze, r - 1, c, level, path);
    }
    if (c > 0) {
        mazeAllPaths(p + "L", maze, r, c - 1, level, path);
    }
    if (r < maze.size() - 1) {
        mazeAllPaths(p + "D", maze, r + 1, c, level, path);
    }
    if (c < maze[0].size() - 1) {
        mazeAllPaths(p + "R", maze, r, c + 1, level, path);
    }
    
    maze[r][c] = 1;         // backtracked
    // revert the changes that you made in the previous call, when that call ends
    // control reaches here, so revert the changes.
    path[r][c] = 0;
}

int main() {
    vector<vector<bool>> maze = {{1, 1, 1},
                                {1, 1, 1},
                                {1, 1, 1}};
                                
    // if not marked visited as false, there will be stack overflow,
    // because at some time you will reach (0, 0) and there will be never-ending calls,
    // this will create a problem, because when you marked the visited cells false,
    // you will not be able to reach that cell again even if it is valid for any different.
    // That's why we are using backtracking
    vector<vector<int>> path(3, {0, 0, 0});
    mazeAllPaths("", maze, 0, 0, 0, path);
}
