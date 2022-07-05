/**
 * author: theKicker
 * created: 2022-01-16 15:46:29 
**/
// leetcode 33
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

// this will not work when there will be duplicate values
int findPivot(vector<int>& arr) {
    // pivot is the max element in the array
    int s = 0, e = arr.size() - 1;
    int mid;
    while (s <= e) {
        mid = s + (e - s) / 2;
        if (mid < e && arr[mid] > arr[mid + 1]) return mid;
        if (mid > s && arr[mid - 1] > arr[mid]) return mid - 1;

        // the 2 cases below will fail when s, mid and e all are pointing to equal elements;
        else if (arr[s] < arr[mid]) {
            // this means u r in sorted left part, so check right side
            s = mid + 1;
        }
        else e = mid - 1;       // this means mid is pointing to an index which is greater than the pivot index
        
    }
    return -1;                  // no pivot => array is sorted already
}

int findPivotWithDup(vector<int>& arr) {
    // pivot is the max element in the array
    int s = 0, e = arr.size() - 1;
    int mid;
    while (s <= e) {
        mid = s + (e - s) / 2;
        if (mid < e && arr[mid] > arr[mid + 1]) return mid;
        if (mid > s && arr[mid - 1] > arr[mid]) return mid - 1;

        // if elements at s, mid and end are equal then slip the duplicates
        if (arr[s] == arr[mid] == arr[e]) {
            // skip duplicates
            // NOTE: what is element at s or e is the pivot, so check it
            // check start is pivot or not
            if (arr[s] > arr[s + 1]) return s;
            s++;
            // check if end is pivot or not
            if (arr[e] < arr[e - 1]) return e;
            // pivot means nth element is greater than (n+1)th element
            e--;
        }
        // otherwise if left part is sorted then look in the right side
        else if (arr[s] < arr[mid] || (arr[s] == arr[mid] && arr[mid] > arr[e])) {
            s = mid + 1;
        }
        // else look in the left side
        else e = mid - 1;
        
    }
    return -1;                  // no pivot => array is sorted already
}

int binarySearch(vi arr, int target, int start, int end) {
    int mid;
    while (start <= end) {
        mid = start + (end - start)/2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return -1;
}

int search(vi nums, int target) {
    int pivot = findPivotWithDup(nums);
    if (pivot == -1) return binarySearch(nums, target, 0, nums.size()-1);
    else {
        if (nums[pivot] == target) return pivot;
        else if (target >= nums[0]) return binarySearch(nums, target, 0, pivot - 1);
        return binarySearch(nums, target, pivot + 1, nums.size() - 1);
    }
}

int main(){
    // process
    // find pivot index first
    // then check if pivot index is the target then return
    // if target is >= first element of the array, then target can only lie in left side of pivot index
    // else target can only lie in the right side of the pivot index
    vi nums{3,5,1};
    int res = search(nums, 5);
    outLn(res);
}