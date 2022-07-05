// check sorted array
#include <bits/stdc++.h>
using namespace std;

bool sorted(int arr[], int ind, int n) {
    if (ind == n - 1) return true;
    return arr[ind] < arr[ind + 1] && sorted(arr, ++ind, n);
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    bool x = sorted(arr, 0, 6);
    cout << x;
}