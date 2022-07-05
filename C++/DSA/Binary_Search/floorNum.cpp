/**
 * author: theKicker
 * date: 2022-01-13 15:40:52 
**/
// floor: greatest number in the array which is <= target
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

int floorNum(int arr[], int len, float target) {
    int start = 0, end = len-1;
    int mid;
    if (target < arr[0]) return -1;           // floor can't be found
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
    return arr[end];
    // in the end, end will be pointing to the number which is just smaller than the target
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,19,21,22,35,49};
    int len = sizeof(arr)/4;
    float num;
    in num;
    int floor = floorNum(arr, len, num);
    outLn(floor);
}