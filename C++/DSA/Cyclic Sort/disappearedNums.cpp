/**
 * @authors: kicker
 * @date: 10:28, 23 February 2022
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define in cin >>
#define out cout <<
#define outLn(n) cout << n << endl
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define vii vector<int64_t>
#define vc vector<char>
#define si set<int>
#define mii map<int, int>
#define pqMax priority_queue<int>
#define pqMin priority_queue<int, vector<int>, greater<int>>

// leetcode 448, Google
// find disappeared numbers from arr containing nums from 1 to n
vector<int> findDisappearedNumbers(vector<int>& arr) {
    int len = arr.size();
    int i = 0;
    while (i < len) {
        int correct = arr[i] - 1;
        if (arr[i] != arr[correct]) swap(arr[i], arr[correct]);
        else i++;
    }
    vector<int> res;
    for (int k = 0; k < len; k++) {
        if (arr[k] - 1 != k) res.push_back(k + 1);
    }
    return res;
}

int main(){
    vi arr{2,4,5,6};
    vi miss = findDisappearedNumbers(arr);
    for (int i = 0; i < miss.size(); i++) cout << miss[i] << " ";
    cout << endl;
}
