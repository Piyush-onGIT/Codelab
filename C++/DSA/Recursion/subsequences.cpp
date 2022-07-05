// subsequences using recursion
#include <bits/stdc++.h>
using namespace std;

// take the crnt char or ignore it
// idea behind subsets/subsequence problems
void substring(string str, int crnt, string ans) {
    if (crnt == str.size()) {
        cout << ans << endl;
        return;
    }
    // take the current char and call
    substring(str, crnt + 1, ans + str[crnt]);
    // ignore the current char and call
    substring(str, crnt + 1, ans);
}

vector<string> substring1(string str, int crnt, string ans) {
    if (crnt == str.size()) {
        // cout << ans << endl;
        vector<string> subs;
        subs.push_back(ans);
        return subs;
    }
    // take the current char and call
    vector<string> left = substring1(str, crnt + 1, ans + str[crnt]);
    // ignore the current char and call
    vector<string> right = substring1(str, crnt + 1, ans);
    
    // combine both left and right
    for (int i = 0; i < right.size(); i++) left.push_back(right[i]);
    return left;
}

int main() {
    string str = "abc";
    int len = str.size();
    vector<string> sub;
    substring(str, 0, "");
    cout << endl;
    sub = substring1(str, 0, "");
    for (int i = 0; i < sub.size(); i++) cout << sub[i] << endl;
}