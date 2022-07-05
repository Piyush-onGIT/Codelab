/**
 * @author: kicker
 * @date: 11:06, 06 April 2022
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define line << endl
#define loop(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, x, n) for (int i = x; i < n; i++)
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

void solve() {
	ll row, col;
	cin >> row >> col;
	ll top, ans;
	
	if (row <= col) {
		if (col % 2) {
			top = col * col;
			ans = top - (row - 1);
		}
		else {
			top = ((col - 1) * (col - 1)) + 1;
			ans = top + row - 1;
		}
	}
	else {
		if (row % 2) {
			top = ((row - 1) * (row - 1)) + 1;
			ans = top + col - 1;
		}
		else {
			top = row * row;
			ans = top - (col - 1);
		}
	}
	
	cout << ans line;
}

int main() {
   ios_base::sync_with_stdio(false);cin.tie(NULL);
  
   #ifndef ONLINE_JUDGE
   freopen("../../input.txt", "r", stdin);
   freopen("../../error.txt", "w", stderr);
   freopen("../../output.txt", "w", stdout);
   #endif
  
   ll t;
   cin >> t;
   while(t--) {
      solve();
   }
  
   cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
   return 0;
}