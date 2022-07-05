// subsets with duplicates
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsetDuplicate(int arr[], int n) {
    vector<vector<int>> res;
    res.push_back({});
    
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        start = 0;
        vector<vector<int>> tmp = res;
        if (i > 0 && arr[i] == arr[i - 1]) {
            // add the duplicate element only in the newly created arrays
            // which was created in the previous pass
            start = end + 1;
        }
        end = tmp.size() - 1;
        for (int j = start; j < tmp.size(); j++) {
            tmp[j].push_back(arr[i]);
            res.push_back(tmp[j]);
        }
    }
    
    return res;
}


int main() {
    int arr[] = {2,2};
    int n = sizeof(arr) / 4;
    vector<vector<int>> subs = subsetDuplicate(arr, n);
    
    for (int i = 0; i < subs.size(); i++) {
        for (int j = 0; j < subs[i].size(); j++) cout << subs[i][j];
        cout << endl;
    }
}