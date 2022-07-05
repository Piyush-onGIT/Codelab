/**
 * author: theKicker
 * date: 2022-01-13 17:29:10 
**/
// leetcode 1095
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

int binarySearch(vi nums, int num, int s, int e){
    int len = nums.size();
    int start = s;
    int end = e;
    bool isAsc = nums[start] < nums[end];
    while(start <= end){
        // int mid = (start + end) / 2;    // may exceed the limit of int
        int mid = start + (end-start)/2;
        if (nums[mid] == num){
            return mid;
        }
        if (isAsc) {
            if (num > nums[mid]){
                // search right half
                start = mid + 1;
            }
            else {
                // search left half
                end = mid - 1;
            }
        }
        else{
            if (num < nums[mid]){
                // search right half
                start = mid + 1;
            }
            else {
                // search left half
                end = mid - 1;
            }
        }
    }
    return -1;  // not found
}

int findInMountainArray(int target, vi nums) {
    int len = nums.size();
    int s = 0, e = len - 1, peak;
    int mid;
    
    // find peak index
    while (s < e) {
        mid = s + (e - s) / 2;
        if (nums[mid] > nums[mid + 1]) {
            e = mid;
        }
        else {
            s = mid + 1;
        }
    }
    peak = s;
    if(nums[s] == target) return s;
    
    int ind;
    if (nums[peak-1] >= target) {
        // target MAY lie in the left side of peak
        ind = binarySearch(nums, target, 0, peak - 1);
    }
    // if we are sure that target lies in the left of peak
    if (ind != -1) return ind;
    
    // target MAY lie in the right side of peak, so check
    ind = binarySearch(nums, target, peak + 1, len - 1);
    // it will return the ind of target or if not found it will return -1
    return ind;
}

int main(){
    // find the peak index
    // search in the left side(ascending part) of the array
    // if not found then search in the right side(descending part) of the array
    // apply order-agnostic binary search
    vi arr{1,2,3,4,5,2,1,0};
    int target = 2;
    int pos = findInMountainArray(target, arr);
    outLn(pos);
}