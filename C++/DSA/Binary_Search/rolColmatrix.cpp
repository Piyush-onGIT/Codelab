/**
 * author: theKicker
 * created: 2022-01-26 00:58:28 
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

// search in a matrix which is sorted rowwise and columnwise
vi search(vector<vector<int>> matrix, int target) {
    int r = 0;
    int c = matrix[0].size() - 1;

    while (r < matrix.size() && c >= 0) {
        if (matrix[r][c] == target) {
            return {r, c};
        }
        if (matrix[r][c] < target) {
            r++;
        } else {
            c--;
        }
    }
    return {-1, -1};
}

int main() {
    vector<vector<int>> arr = {
            {10, 20, 30, 40},
            {15, 25, 35, 45},
            {28, 29, 37, 49},
            {33, 34, 38, 50}
    };
    vi ans = search(arr, 200);
    cout << ans[0] << " " << ans[1] << endl;
}