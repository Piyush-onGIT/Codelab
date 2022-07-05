// merge sort recursion
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int mid, int e) {
    int i = s;                  // for left sub arr
    int j = mid + 1;            // for right sub arr
    
    int temp[e + 1];
    int k = s;
    
    while (i <= mid && j <= e) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= e) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = s; i <= e; i++) arr[i] = temp[i];
}

void mergeSort(int arr[], int s, int e) {
    if (s < e) {                // if arr contains more than 1 element
        int m = (s + e) / 2;
        mergeSort(arr, s, m);
        mergeSort(arr, m + 1, e);
        merge(arr, s, m, e);
    }
}

int main() {
    int arr[] = {5,6,7,8,9,1,-1};
    int len = sizeof(arr) / 4;
    mergeSort(arr, 0, len - 1);
    
    for (int i = 0; i < len; i++) cout << arr[i] << " ";
}