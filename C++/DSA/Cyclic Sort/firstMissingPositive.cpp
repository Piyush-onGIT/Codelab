/**
 * @authors: kicker
 * @date: 14:35, 23 February 2022
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

// leetcode 41, Amazon
// given an unsorted array, find first missing positive number

int firstMissingPositive(vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    while (i < n) {
        if (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) swap(arr[i], arr[arr[i] - 1]);
        else i++;
    }
    int k = 0;
    for (k; k < n; k++) {
        if (arr[k] != k + 1) break;
    }
    return k + 1;
}

int main(){
    vi arr{2,3,1,-1,4};
    int miss = firstMissingPositive(arr);
    cout << miss << endl;
}
