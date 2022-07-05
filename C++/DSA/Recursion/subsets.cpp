#include <bits/stdc++.h>
using namespace std;

void subsets(vector<int> arr, int ind, vector<vector<int>> ans) {
	if (ind >= arr.size()) {
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
			cout << endl;
		}
		return;
	}
	vector<vector<int>> tmp = ans;
	for (int i = 0; i < tmp.size(); i++) {
		tmp[i].push_back(arr[ind]);
	}
	subsets(arr, ind + 1, tmp);
	subsets(arr, ind + 1, ans);
}

vector<vector<int>> subset(vector<int> arr, int ind, vector<vector<int>> ans) {
	if (ind >= arr.size()) {
		return ans;
	}
	vector<vector<int>> tmp = ans;
	for (int i = 0; i < tmp.size(); i++) {
		tmp[i].push_back(arr[ind]);
	}
	vector<vector<int>> left = subset(arr, ind + 1, tmp);
	vector<vector<int>> right = subset(arr, ind + 1, ans);
	
	for (int i = 0; i < right.size(); i++) left.push_back(right[i]);
	return left;
}

// find subsets with only one recursive call inside
vector<vector<int>> subsetDuplicate(vector<int> arr, int ind, vector<vector<int>> ans, int s, int e) {
	if (ind >= arr.size()) {
		return ans;
	}
	if (ind > 0 && arr[ind] == arr[ind - 1]) s = e + 1;
	else s = 0;
	vector<vector<int>> tmp = ans;
	// vector<vector<int>> tmp1 = ans;
	e = tmp.size() - 1;
	
	for (int i = s; i < tmp.size(); i++) {
		tmp[i].push_back(arr[ind]);
		ans.push_back(tmp[i]);
	}
	vector<vector<int>> left = subsetDuplicate(arr, ind + 1, ans, s, e);
	return left;
}

int main() {
	vector<int> arr{1,2,3};
	
	vector<vector<int>> sub = subsetDuplicate(arr, 0, {{}}, 0, 0);
	for (int i = 0; i < sub.size(); i++) {
		for (int j = 0; j < sub[i].size(); j++) cout << sub[i][j] << " ";
		cout << endl;
	}
}