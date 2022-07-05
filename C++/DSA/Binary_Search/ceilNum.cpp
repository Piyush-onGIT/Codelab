/**
 * author: theKicker
 * date: 2022-01-13 15:30:02 
**/
// ceiling: smallest element in the array which is >= target
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

int ceilingNum(int arr[], int len, float target) {
    int start = 0, end = len-1;
    int mid;
    if (target > arr[len-1]) return -1;         // no ceiling found
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
    return arr[start];                          // start will be poiting to ceiling of number
    // in the end start will be pointing to the number which is just greater than the target
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,19,21,32};
    float num;
    in num;
    int len = sizeof(arr)/4;
    int ceiling = ceilingNum(arr, len, num);
    outLn(ceiling);
}