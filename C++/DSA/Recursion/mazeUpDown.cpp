/**
 * @authors: kicker
 * @date: 10:13, 15 March 2022
**/
#include <bits/stdc++.h>
using namespace std;

// maze paths where only down and right movements are allowed

int maze(int r, int c) {
    if (r == 1 || c == 1) return 1;
    
    int left = maze(r - 1, c);
    int right = maze(r, c - 1);
    
    return left + right;
}

void mazePath(string p, int r, int c) {
    if (r == 1 && c == 1) {
        cout << p << endl;
        return;
    }
    if (r > 1) mazePath(p + "D", r - 1, c);
    if (c > 1) mazePath(p + "R", r, c - 1);
}

vector<string> path(string p, int r, int c) {
    if (r == 1 && c == 1) {
        return {p};
    }
    vector<string> ans;
    if (r > 1) {
        vector<string> lPath = path(p + "D", r - 1, c);
        for (int i = 0; i < lPath.size(); i++) ans.push_back(lPath[i]);
    }
    
    if (c > 1) {
        vector<string> rPath = path(p + "R", r, c - 1);
        for (int i = 0; i < rPath.size(); i++) ans.push_back(rPath[i]);
    }
    
    return ans;
}

int main() {
    int pathCnt = maze(3, 3);
    
    vector<string> ans = path("", 3, 3);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
