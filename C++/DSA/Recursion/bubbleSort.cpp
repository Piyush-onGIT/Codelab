// bubble sort using recursion
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int last, int s) {
    if (last < 0) return;
    if (s < last) {
        if (arr[s] > arr[s + 1]) swap(arr[s], arr[s + 1]);
        bubbleSort(arr, last, s + 1);
    }
    else bubbleSort(arr, last - 1, 0);
}

int main() {
    int arr[] = {5,4,3,2,1};
    bubbleSort(arr, 4, 0);
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}