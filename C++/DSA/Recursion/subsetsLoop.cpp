// subsets of array using loop
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subset(int arr[], int n) {
    vector<vector<int>> res;
    res.push_back({});
    
    for (int i = 0; i < n; i++) {
        vector<vector<int>> tmp = res;
        for (int j = 0; j < tmp.size(); j++) {
            tmp[j].push_back(arr[i]);
            res.push_back(tmp[j]);
        }
    }
    
    return res;
}

int main() {
    int arr[] = {1,2,3};
    int n = sizeof(arr) / 4;
    vector<vector<int>> subs = subset(arr, n);
    
    for (int i = 0; i < subs.size(); i++) {
        for (int j = 0; j < subs[i].size(); j++) cout << subs[i][j];
        cout << endl;
    }
}