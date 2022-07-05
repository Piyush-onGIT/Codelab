/**
 * @authors: kicker
 * @date: 10:43, 23 February 2022
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

// leetcode 287, Amazon, Microsoft
// arr containing n + 1 nums, 1 <= arr[i] <= n, find that duplicate number

int findDuplicate(vector<int>& arr) {
    int len = arr.size();
    int i = 0;
    while (i < len) {
        if (arr[i] != i + 1) {              // element is not at correct index
            int correct = arr[i] - 1;
            // if element is not at correct position
            if (arr[i] != arr[correct]) swap(arr[i], arr[correct]);
            // else case means the element is already present at the correct position,                 // then, this ith element is the answer
            else break;
        }
        else i++;
    }
    return arr[i];
}

int main(){
    vi arr{2,3,1,4,4};
    int dup = findDuplicate(arr);
    cout << dup << endl;
}
