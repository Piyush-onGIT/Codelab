/**
 * author: theKicker
 * date: 2022-01-13 17:38:56 
**/
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