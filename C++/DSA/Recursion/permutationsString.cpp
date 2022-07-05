// permutations
#include <bits/stdc++.h>
using namespace std;

void permutations(string p, string up) {
    if (up.size() == 0) {
        cout << p << endl;
        return;
    }
    char ch = up[0];
    for (int i = 0; i <= p.size(); i++) {
        string f = p.substr(0, i);
        string l = p.substr(i, p.size());
        // put up[0] at different places and call recursion
        permutations(f + ch + l, up.substr(1));
    }
}

vector<string> permutation(string p, string up) {
    if (up.size() == 0) {
        vector<string> list;
        list.push_back(p);
        return list;
    }
    char ch = up[0];
    vector<string> ans;
    for (int i = 0; i <= p.size(); i++) {
        string f = p.substr(0, i);
        string l = p.substr(i, p.size());
        // put up[0] at different places and call recursion
        vector<string> list = permutation(f + ch + l, up.substr(1));
        // add the permutation in the ans vector of each function call
        for (int i = 0; i < list.size(); i++) ans.push_back(list[i]);
    }
    // finally return the ans vector containing all permutations
    return ans;
}

int permutationCount(string p, string up) {
    if (up.size() == 0) {
        return 1;       // we get one permutation here
    }
    int count = 0;
    char ch = up[0];
    for (int i = 0; i <= p.size(); i++) {
        string f = p.substr(0, i);
        string l = p.substr(i, p.size());
        // put up[0] at different places and call recursion
        count += permutationCount(f + ch + l, up.substr(1));
    }
    return count;
}

int main() {
	string str = "abcd";
	int ans = permutationCount("", str);
	cout << ans;
}