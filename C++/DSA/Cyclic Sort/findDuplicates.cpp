/**
 * @authors: kicker
 * @date: 11:54, 23 February 2022
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

// leetcode 442
// find duplicate elements in the array

vector<int> findDuplicates(vector<int>& arr) {
    int len = arr.size();
    int i = 0;
    while (i < len) {
        int correct = arr[i] - 1;
        if (arr[i] != arr[correct]) swap(arr[i], arr[correct]);
        else i++;
    }
    vector<int> res;
    for (int k = 0; k < len; k++) {
        if (arr[k] - 1 != k) res.push_back(arr[k]);
    }
    return res;
}


int main(){
    vi arr{1,2,2,3,4,5,5};
    vi dups = findDuplicates(arr);
    for (int i = 0; i < dups.size(); i++) cout << dups[i] << " ";
    cout << endl;
}
