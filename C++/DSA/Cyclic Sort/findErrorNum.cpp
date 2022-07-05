/**
 * @authors: kicker
 * @date: 14:27, 23 February 2022
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

// leetcode 645
// In a set of numbers from 1 to n,
// one number is repeated and one is missing due to the repeatition, find both

vector<int> findErrorNums(vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    vector<int> res;
    while (i < n) {
        int correct = arr[i] - 1;
        if (arr[i] != arr[correct]) swap(arr[i], arr[correct]);
        else i++;
    }
    for (int k = 0; k < n; k++) {
        if (arr[k] != k + 1) {
            // this kth element is at wrong place
            // this means this element is the repeated number
            // and the number which got deleted must be (k + 1)
            res.push_back(arr[k]);
            res.push_back(k + 1);
            break;
        }
    }
    return res;
}

int main(){
    vi arr{1,2,2,3,4};
    vi err = findErrorNums(arr);
    for (int i = 0; i < err.size(); i++) cout << err[i] << " ";
    cout << endl;
}
