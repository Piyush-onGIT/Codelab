// selection sort using recursion
#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int begin, int end, int mx) {
    if (end < 0) return;

    if (begin <= end) {                     // find max element from begin index to end index
        if (arr[begin] > arr[mx]) mx = begin;
        selectionSort(arr, begin + 1, end, mx);
    }
    else {                                  // max element found now swap it with end index
        swap(arr[end], arr[mx]);
        // arr is getting sorted from last so, end - 1 and max element is assumed to be the first element
        selectionSort(arr, 0, end - 1, 0);
    }
}

int main() {
    int arr[] = {5,4,3,2,1,-1};
    int len = sizeof(arr) / 4;
    selectionSort(arr, 0, len - 1, 0);
    for (int i = 0; i < len; i++) cout << arr[i] << " ";
}