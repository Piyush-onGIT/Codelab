/**
 * author: theKicker
 * date: 2022-01-13 16:59:13 
**/
// leetcode 34
#include <bits/stdc++.h>
using namespace std;
#define in cin >>
#define out cout <<
#define outLn(n) cout << n << endl
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define pb push_back
#define pp pop_back
#define si set<int>
#define mii map<int, int>

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> inds;
    vector<int> nf{-1, -1};
    int s = 0;
    int e = nums.size() - 1;
    int mid;
    int len = e+1;
    int first = -1, last = -1;
    while (s <= e) {
        mid = s + (e-s)/2;
        if (nums[mid] > target) {
            e = mid-1;
        }
        else if (nums[mid] < target) {
            s = mid+1;
        }
        else {
            // search for smaller index in left side
            first = mid;    // store one possible answer
            e = mid-1;
        }
    }
    if (first == -1) return nf;     // not found
    inds.push_back(first);
    
    s = 0, e = len-1;
    while (s <= e) {
        mid = s + (e-s)/2;
        if (nums[mid] > target) {
            e = mid-1;
        }
        else if (nums[mid] < target) {
            s = mid+1;
        }
        else {
            // search for larger index in right side
            last = mid;     // store one possible answer
            s = mid+1;
        }
    }
    if(last == -1) inds.push_back(first);   // if only one position found
    else inds.push_back(last);
    
    return inds;
}

int main(){
    vi arr{1,1,1,2,2,3,4,5,6,7,7,7,8,8};
    int target = 7;
    vi ans = searchRange(arr, target);
}