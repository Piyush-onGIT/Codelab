// linear search recursion
#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int ind, int n, int target) {
    if (ind == n) return false;
    return arr[ind] == target || linearSearch(arr, ++ind, n, target);
}

int findInd(int arr[], int ind, int n, int target) {
    if (ind == n) return -1;
    if (arr[ind] == target) return ind;
    return findInd(arr, ++ind, n, target);
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    int x = findInd(arr, 0, 6, 3);
    cout << x;
}