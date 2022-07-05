/**
 * @authors: kicker
 * @date: 10:01, 23 February 2022
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

// leetcode 268, amazon
// find missing number in an arr containg num from 0 to n except one that is missing
int missingNumber(vector<int>& arr) {
    int len = arr.size();
    // apply cycle sort
    int i = 0;
    while (i < len) {
        int correct = arr[i];
        if (correct >= len) i++;
        else if (correct != arr[correct]) swap(arr[i], arr[correct]);
        else i++;
    }
    // search for missing number
    i = 0;
    for (i; i < len; i++) {
        // if this condition will never be satisified,
        // then last number is missing. For loop will take care of that
        if (arr[i] != i) break;
    }
    return i;
}

int main(){
    vi arr{1,2,3,4,5};
    int miss = missingNumber(arr);
    cout << miss << endl;
}


