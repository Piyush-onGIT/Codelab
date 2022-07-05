/**
 * author: theKicker
 * created: 2022-01-21 16:12:39 
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

int split(vi arr) {
    int start = 0, end = 0;
    int len = arr.size();
    for (int i = 0; i < len; i++) {
        start = max(start, arr[i]);
        end += arr[i];
    }
    while (start < end) {
        // mid is our potential answer
        int mid = start + (end - start) / 2;
        // now count the number of pieces
        int pieces = 0, sum = 0;
        for (int num : arr) {
            if (sum + num > mid) {
                // now u can't add this number in this subarray, create a new one
                // sum will be equal to the num, that is the first element of the new subarray formed
                sum = num;
                pieces++;
            }
            else sum += num;
        }
        if (pieces > mid) start = mid + 1;
        else end = mid;
    }
    return end;
}

int main(){

}