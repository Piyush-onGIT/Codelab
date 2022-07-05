/**
 * @authors: kicker
 * @date: 13:01, 14 March 2022
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define in cin >>
#define out cout <<
#define outLn(n) cout << n << endl
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define pb push_back
#define vii vector<int64_t>
#define vc vector<char>
#define si set<int>
#define mii map<int, int>
#define pqMax priority_queue<int>
#define pqMin priority_queue<int, vector<int>, greater<int>>

// leetcode 17 Google
                     
vector<string> phone(string p, string up, map<int, string> num) {
    if (up.length() == 0) {
        return {p};
    }
    vector<string> ans;
    int dig = up[0] - '0';
    for (int i = 0; i < num[dig].length(); i++) {
        string t = "";
        t += num[dig][i];
        vector<string> tmpAns = phone(p + t, up.substr(1), num);
        for (int i = 0; i < tmpAns.size(); i++) ans.push_back(tmpAns[i]);
    }
    return ans;
}

int main(){
	map<int, string> num{{1, ""}, {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"},
                     {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
    vs arr = phone("", "2", num);
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
}
