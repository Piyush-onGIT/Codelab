/**
 * @author: kicker
 * @date: 16:15, 21 March 2022
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define in cin >>
#define out cout <<
#define outLn(n) cout << n << endl
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define pb push_back
#define vii vector<int64_t>
#define vc vector<char>
#define si set<int>
#define mii map<int, int>
#define pqMax priority_queue<int>
#define pqMin priority_queue<int, vector<int>, greater<int>>

ll kadane(vi arr) {
	int ans = INT_MIN, tmpSum = 0;
	for (ll x : arr) {
		tmpSum += x;
		ans = max(ans, tmpSum);
		tmpSum = max(0, tmpSum);
	}
	return ans;
}

int main(){
    vi arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << kadane(arr) << endl;
}
