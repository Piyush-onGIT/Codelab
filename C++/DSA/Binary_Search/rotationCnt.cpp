/**
 * author: theKicker
 * created: 2022-01-21 14:18:43 
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

int main(){
    vi v{15, 18, 2, 3, 6, 12};
    // ans is pivot index + 1
    int piv = findPivot(v);
    outLn(piv + 1);
}