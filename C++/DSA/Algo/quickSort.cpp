// quick sort
#include <bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;
    
    int s = low, e = high;
    int mid = s + (e - s) / 2;
    int pivot = arr[mid];
    
    while (s <= e) {
        // s will be pointing to first illegal element from the left end of pivot
        while (arr[s] < pivot) s++;
        // e will be pointing to first illegal element from the right end of pivot
        while (arr[e] > pivot) e--;
        
        if (s <= e) {
            // swap the illegal elements
            swap(arr[s], arr[e]);
            // move forward after swapping
            s++; e--;
        }
        // after this loop my pivot is at it right place
    }
    // now sort both halves
    quickSort(arr, low, e);
    quickSort(arr, s, high);
}

int main() {
	int arr[] = {5,4,3,2,1,10};
	int len = sizeof(arr) / 4;
	quickSort(arr, 0, len - 1);
	for (int i = 0; i < len; i++) cout << arr[i] << " ";
}