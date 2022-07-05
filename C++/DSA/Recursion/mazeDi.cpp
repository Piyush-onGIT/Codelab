/**
 * @authors: kicker
 * @date: 10:13, 15 March 2022
**/
#include <bits/stdc++.h>
using namespace std;

// maze paths where only down, right and diagonal movements are allowed

int mazeDi(int r, int c) {
    if (r == 1 || c == 1) return 1;
    
    int left = mazeDi(r - 1, c);
    int right = mazeDi(r, c - 1);
    int di = mazeDi(r - 1, c - 1);
    
    return left + right + di;
}

void mazePathDi(string p, int r, int c) {
    if (r == 1 && c == 1) {
        cout << p << endl;
        return;
    }
    if (r > 1 && c > 1) mazePathDi(p + "Di", r - 1, c - 1);
    if (r > 1) mazePathDi(p + "D", r - 1, c);
    if (c > 1) mazePathDi(p + "R", r, c - 1);
}

vector<string> path(string p, int r, int c) {
    if (r == 1 && c == 1) {
        return {p};
    }
    vector<string> ans;
    if (r > 1 && c > 1) {
        vector<string> diPath = path(p + "Di", r - 1, c - 1);
        for (int i = 0; i < diPath.size(); i++) ans.push_back(diPath[i]);
    }
    
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
    mazePathDi("", 3, 3);
    
    int cnt = mazeDi(3, 3);
    cout << cnt << endl;
    
    vector<string> ans = path("", 3, 3);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
