/**
 * author: theKicker
 * date: 2022-01-13 17:05:52 
**/
// gfg, amazon
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

int findInf(vi arr, int target) {
    int len = arr.size();
    // first, find the range in which the target exists
    int s = 0, e = 1;               // initial chunk
    while (target > arr[e]) {
        // double the chunk size
        int newS = e + 1;
        // new end = previous end + (size of chunk) * 2
        // size of box = e - s + 1
        e = e + (e - s + 1) * 2;
        s = newS;
    }
    // now we know in which box our target exists, so now apply binary search
    int pos = binarySearch(arr, target, s, e);
    return pos;
}

int main(){
    // code may not work in some cases because arr is not an infinte array so in some cases e will be pointing to a index
    // which is out of bound
    vi arr{1,2,3,4,5,6,7,8,9};
    int pos = findInf(arr, 4);
    outLn(pos);
}