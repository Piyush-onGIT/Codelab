#include <bits/stdc++.h>
using namespace std;

// same concept as permutation of string
void permutations(vector<int> arr, vector<int> ans, int ind) {
	if (ind >= arr.size()) {
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		cout << endl;
		return;
	}
	int num = arr[ind];
	for (int i = 0; i <= ans.size(); i++) {
		vector<int> tmp = ans;
		vector<int>::iterator itr = tmp.begin();
		itr += i;
		tmp.insert(itr, num);
		permutations(arr, tmp, ind + 1);
	}
}

vector<vector<int>> permutation(vector<int> arr, vector<int> ans, int ind) {
	if (ind >= arr.size()) {
		vector<vector<int>> res;
		res.push_back(ans);
		return res;
	}
	
	int num = arr[ind];
	vector<vector<int>> calls;
	
	for (int i = 0; i <= ans.size(); i++) {
		vector<int> tmp = ans;
		vector<int>::iterator itr = tmp.begin();
		itr += i;
		tmp.insert(itr, num);
		vector<vector<int>> call = permutation(arr, tmp, ind + 1);
		for (int i = 0; i < call.size(); i++) calls.push_back(call[i]);
	}
	return calls;
}

int permutationCount(vector<int> arr, vector<int> ans, int ind) {
	if (ind >= arr.size()) {
		return 1;
	}
	
	int num = arr[ind];
	int count = 0;
	for (int i = 0; i <= ans.size(); i++) {
		vector<int> tmp = ans;
		vector<int>::iterator itr = tmp.begin();
		itr += i;
		tmp.insert(itr, num);
		count += permutationCount(arr, tmp, ind + 1);
	}
	return count;
}

int main() {
	vector<int> arr{1,2,3};
	permutations(arr, {}, 0);	
	vector<vector<int>> ans1 = permutation(arr, {}, 0);
	for (int i = 0; i < ans1.size(); i++) {
		for (int j = 0; j < ans1[i].size(); j++) cout << ans1[i][j] << " ";
		cout << endl;
	}
}