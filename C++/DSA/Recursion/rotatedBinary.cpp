// rotated binary search using recursion
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> arr, int target, int s, int e) {
    if (s > e) return -1;
    
    int mid = s + (e - s) / 2;
    if (arr[mid] == target) return mid;
    
    if (arr[s] <= arr[mid]) {
        if (target >= arr[s] && target <= arr[mid]) {
            return search(arr, target, s, mid - 1);
        }
        else return search(arr, target, mid + 1, e);
    }
    
    if (target >= arr[mid] && target <= arr[e]) return search(arr, target, mid + 1, e);
    else return search(arr, target, s, mid - 1);
}

int main() {
    vector<int> arr{5,6,1,2,3};
    int ans = search(arr, 5, 0, 4);
    cout << ans;
}