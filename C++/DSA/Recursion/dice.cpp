#include <bits/stdc++.h>
using namespace std;

// dice problem, Amazon

vector<string> dice(string p, int target) {
    if (target == 0) {
        // cout << p << endl;
        return {p};
    }
    vector<string> ans;
    for (int i = 1; i <= 6 && i <= target; i++) {
        vector<string> tmp = dice(p + to_string(i), target - i);
        for (int i = 0; i < tmp.size(); i++) ans.push_back(tmp[i]);
    }
    return ans;
}

void diceFace(string p, int target, int face) {
    if (target == 0) {
        cout << p << endl;
        return;
    }
    for (int i = 1; i <= face && i <= target; i++) {
        dice(p + to_string(i), target - i, face);
    }
}

int main() {
    vector<int> arr{1,2,3,4,5,6};
    int num = 4;
    vector<string> ans = dice("", num);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
}
