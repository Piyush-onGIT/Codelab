#include <bits/stdc++.h>
using namespace std;

int findUnique(int arr[], int n) {
    int unique = 0;
    for (int i = 0; i < n; i++) {
        unique ^= arr[i];
        cout << unique << endl;
    }
    return unique;
}

int main() {
    int arr[] = {2,3,4,3,4,5,2,5,6};
    int uniq = findUnique(arr, sizeof(arr)/4);
    cout << uniq;
}