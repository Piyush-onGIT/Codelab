// search in a matrix which is sorted row-wise and column-wise
#include <bits/stdc++.h>
using namespace std;

// to search in a row provided between the column provided
vector<int> binarySearch(vector<vector<int>> matrix, int row, int cStart, int cEnd, int target) {
    while (cStart <= cEnd) {
        int mid = cStart + (cEnd - cStart) / 2;
        if (matrix[row][mid] == target) {
            return {row, mid};
        }
        if (matrix[row][mid] < target) {
            cStart = mid + 1;
        } else {
            cEnd = mid - 1;
        }
    }
    return {-1, -1};
}

vector<int> search(vector<vector<int>> matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size(); // be cautious, matrix may be empty
    if (cols == 0){
        return {-1,-1};
    }
    if (rows == 1) {
        return binarySearch(matrix,0, 0, cols-1, target);
    }

    int rStart = 0;
    int rEnd = rows - 1;
    int cMid = cols / 2;

    // run the loop till 2 rows are remaining
    while (rStart < (rEnd - 1)) { // while this is true it will have more than 2 rows
        int mid = rStart + (rEnd - rStart) / 2;
        if (matrix[mid][cMid] == target) {
            return {mid, cMid};
        }
        if (matrix[mid][cMid] < target) {
            rStart = mid;
        } else {
            rEnd = mid;
        }
    }
    // now we have two rows
    // check whether the target is in the col of 2 rows
    if (matrix[rStart][cMid] == target) {
        return {rStart, cMid};
    }
    if (matrix[rStart + 1][cMid] == target) {
        return {rStart + 1, cMid};
    }

    // search in 1st half
    if (target <= matrix[rStart][cMid - 1]) {
        return binarySearch(matrix, rStart, 0, cMid-1, target);
    }
    // search in 2nd half
    if (target >= matrix[rStart][cMid + 1] && target <= matrix[rStart][cols - 1]) {
        return binarySearch(matrix, rStart, cMid + 1, cols - 1, target);
    }
    // search in 3rd half
    if (target <= matrix[rStart + 1][cMid - 1]) {
        return binarySearch(matrix, rStart + 1, 0, cMid-1, target);
    } else {
        return binarySearch(matrix, rStart + 1, cMid + 1, cols - 1, target);
    }
}

int main() {
    vector<vector<int>> mat = {
                    {10,20,30,40},
                    {15,25,35,45},
                    {28,37,39,47},
                    {33,34,38,50}};
    vector<int> res = search(mat, 37);
    cout << res[0] << " " << res[1] << endl;
}