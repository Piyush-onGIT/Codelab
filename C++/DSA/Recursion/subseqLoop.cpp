// subsequences of string using loop
#include <bits/stdc++.h>
using namespace std;

vector<string> subseq(string str) {
    vector<string> res;
    res.push_back("");
    for (int i = 0; i < str.size(); i++) {
        vector<string> tmp = res;
        for (int j = 0; j < tmp.size(); j++) {
            string t = tmp[j] + str[i];
            res.push_back(t);
        }
    }
    return res;
}

int main() {
    string str = "abc";
    vector<string> subs = subseq(str);
    
    for (int i = 0; i < subs.size(); i++) {
        for (int j = 0; j < subs[i].size(); j++) cout << subs[i][j];
        cout << endl;
    }
}