/**
 * author: theKicker
 * date: 2022-01-13 15:12:20 
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

int binarySearch(int arr[], int len, int target) {
    int start = 0, end = len-1;
    int mid;
    while (start <= end) {
        mid = start + (end - start)/2;          // to make sure it can't go out of int limit
        if (arr[mid] == target) return mid;     // element found
        else if (arr[mid] > target) {           // element lies in the left side of mid
            end = mid - 1;
        }
        else {
            start = mid + 1;                    // element lies in the right side of mid
        }
    }
    return -1;                                  // not found
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,49};
    int num;
    in num;
    int len = sizeof(arr)/4;
    int pos = binarySearch(arr, len, num);
    outLn(pos);
}