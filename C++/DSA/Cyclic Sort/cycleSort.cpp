#include <bits/stdc++.h>
using namespace std;

void cyclicSort(vector<int> &arr) {
    int n = arr.size();
    int i = 0;
    while(i < n) {
        int correct = arr[i] - 1;
        if (arr[correct] != arr[i]) {
            swap(arr[i], arr[correct]);
        }
        else i++;
    }
}

int main() {
    vector<int> arr{3,5,2,1,4};
    cyclicSort(arr);
    for (auto i : arr) cout << i << " ";
}