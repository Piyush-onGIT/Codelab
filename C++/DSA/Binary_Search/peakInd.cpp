/**
 * author: theKicker
 * date: 2022-01-13 17:20:27 
**/
// leetcode 852
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

int peakIndexInMountainArray(vector<int>& arr) {
    int s = 0, e = arr.size() - 1;
    int mid;
    while (s < e) {
        mid = s + (e - s) / 2;
        if (arr[mid] > arr[mid + 1]) {
            // u r in decreasing part
            // this may be the answer but look at left
            // so e is not equal to mid-1
            e = mid;
        }
        else {
            // u r in increasing part
            s = mid + 1;
            // as arr[mid+1] is greater than arr[mid]
        }
    }
    // in the end start and end will be pointing to the max element
    // start and end are always trying to find the max element in above two
    // checks and hence when they are equal, then they must be pointing to the max element
    return s;
}

int main(){
    vi arr{1,2,3,4,5,3,2,0};
    int peak = peakIndexInMountainArray(arr);
    outLn(peak);
}