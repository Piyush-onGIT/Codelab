// linear search multiple indexes recursion
#include <bits/stdc++.h>
using namespace std;

// having ans vector in the argument
vector<int> findAll(vector<int> arr, int ind, int target, vector<int> ans) {
    if (ind == arr.size()) return ans;
    if (arr[ind] == target) ans.push_back(ind);
    return findAll(arr, ++ind, target, ans);
}

// without taking ans vector in argument
vector<int> findAll1(vector<int> arr, int ind, int target) {
    vector<int> ans;
    if (ind == arr.size()) return ans;
    if (arr[ind] == target) ans.push_back(ind);
    vector<int> final = findAll1(arr, ++ind, target);
    
    // adding the answer indexes which we get from each recursion call
    for (int i = 0; i < final.size(); i++) ans.push_back(final[i]);
    return ans;
}

int main() {
    vector<int> arr{1,2,3,3,4,5};
    vector<int> ans = findAll1(arr, 0, 3);
    cout << ans[1];
}